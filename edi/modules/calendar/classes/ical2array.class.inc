<?php
/*
Copyright Intermesh 2004
Author: Merijn Schering <mschering@intermesh.nl>
Version: 1.0 Release date: 14 March 2004
Version: 2.0 Release date: 15 June 2004

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2 of the License, or (at your
option) any later version.

builds an array from an ics file:

Example:

SUMMARY:object summary
$this->objects[$n]['SUMMARY']['value'] = 'object summary';

RRULE:FREQ=YEARLY;INTERVAL=1;BYMONTH=3
$this->objects[$n]['RRULE']['value'] = 'FREQ=YEARLY;INTERVAL=1;BYMONTH=3';

You can parse the rrule with parse_rrule() into:

$rrule = $this->parse_rrule('FREQ=YEARLY;INTERVAL=1;BYMONTH=3');
$rrule['FREQ'] = 'YEARLY';
$rrule['INTERVAL'] = '1';
$rrule['BYMONTH'] = '3';

DTSTART;VALUE=DATE:20040303
$this->objects[$n]['DTSTART']['params']['VALUE'] = 'DATE';
$this->objects[$n]['DTSTART']['value'] = '20040303';
*/


define("ICAL_DELIM_EQUAL", "=");
define("ICAL_WORD_WRAP_DOS", chr(13).chr(10));
define("ICAL_WORD_WRAP_MAC", chr(13));
define("ICAL_WORD_WRAP_UNIX", chr(10));
define("ICAL_CHAR_WSP", chr(32));
define("ICAL_CHAR_HTAB", chr(9));

class ical2array
{
	var $todos = array();

	var $object = array();
	var $object_name;
	var $param_name;
	var $buffer;
	var $object_types = array('VTIMEZONE', 'VCALENDAR', 'DAYLIGHT', 'VEVENT', 'VTODO', 'STANDARD');
	var $timezones = array();
	var $force_timezone;//hours
	var $continue_value=false;

	
	//Workaround for Nokia bug that sends GMT time without a Z at the end
	function force_timezone($timezone)
	{
		$this->force_timezone = $timezone;
	}
	
	function parse_file($ical_file)
	{
		if (!$fp = fopen ($ical_file, "r"))
		{
			return false;
		}else
		{
 			$data = fread($fp, filesize($ical_file));
 			fclose($fp);
 			
 			$vcalendar = $this->parse_icalendar_string($data);
 			$this->timezones = $this->get_timezones($vcalendar);
 			return $vcalendar;
 		}
	}
	
	function parse_string($ical_string)
	{
		$vcalendar = $this->parse_icalendar_string($ical_string);
		$this->timezones = $this->get_timezones($vcalendar);
		return $vcalendar;
	}
	
	
	function parse_icalendar_string($data)
	{		
		/*word wrap - replace <CRLF> by <LF> (dos)*/
		$data = str_replace(ICAL_WORD_WRAP_DOS, ICAL_WORD_WRAP_UNIX, $data);
		/*word wrap - replace <CR> by <LF> (mac)*/
		$data = str_replace(ICAL_WORD_WRAP_MAC, ICAL_WORD_WRAP_UNIX, $data);
		/*unfolding lines ending up in '=<LF>', originally '=<CRLF>'*/
		$regex = '/('.ICAL_DELIM_EQUAL.ICAL_WORD_WRAP_UNIX.')/i';
		$data = preg_replace($regex, "", $data);
		
		/*unfolding lines as specified in RFC2425*/
		$regex = '/('.ICAL_WORD_WRAP_UNIX.')(['.ICAL_CHAR_WSP.'|'.ICAL_CHAR_HTAB.'])/i';
		$data = preg_replace($regex, "", $data);
			
		$objects = array();


		$eol = true;	
		while(strlen($data) > 0 && $eol !== false)
		{			
			//read line by line
			$eol = strpos($data, "\n");
			if($eol === false)
			{
				$line = $data;
			}else
			{
				$line = substr($data,0,$eol);
			}	

			$data = trim(substr($data,$eol));
			
	  	//check for all object types
	  	for($i=0;$i<count($this->object_types);$i++)
	  	{	  		
  			if(eregi('BEGIN:'.$this->object_types[$i], $line))
  			{  				
  				//found beginning of object now find the end
  				$eoo = strpos($data, 'END:'.$this->object_types[$i]);
  				if($eoo !== false)
  				{
  					$obj_data = substr($data,0,$eoo);		
  
						$object = $this->parse_object_string($obj_data, $this->object_types[$i]);
						$object['type'] = $this->object_types[$i];

						$object['objects']  = $this->parse_icalendar_string($obj_data);
														
						$objects[] = $object;
						$data = substr($data, $eoo);
  				}	  				
				}
			}
		}		
		
		return $objects;	
	}

	function parse_object_string($data, $type)
	{
		$this->object = array();
		$in_nested_object = false;
		$in_value = false;
		$this->buffer_type = 'object_name';
		$this->buffer = '';

		$eol = true;
		while(strlen($data) > 0 && $eol !== false)
		{	
			//read line by line
			$eol = strpos($data, "\n");
			if($eol === false)
			{
				$line = $data;
			}else
			{
				$line = substr($data,0,$eol);
			}		 
	
			$data = trim(substr($data,$eol));

		  //don't process empty lines
		  if (strlen($line) == 0)
		  {
		  	if ($this->buffer_type == 'value')
				{
					$this->add_buffer();
					$this->buffer_type = 'object_name';
				}
		  }else
		  {
		  	if(eregi('BEGIN:', $line))
		  	{
		  		$in_nested_object = true;
		  	}elseif(eregi('END:', $line))
		  	{
		  		$in_nested_object = false;
		  	}
		  	
		  	if(!$in_nested_object)
		  	{
	  			/*
					If we are processing a value and the first value is a tab (chr(9)) or
					a space (chr(32)) then cut it. if it's not one of these chars
					then we are done processing a value.
					*/
					if ($this->buffer_type == 'value')
					{
						if(isset($line[0]) && $line[0] != chr(32) && $line[0] != chr(9) && !$this->continue_value)
						{
							$this->add_buffer();
							$this->buffer_type = 'object_name';
						}else
						{		
							if(!$this->continue_value)
							{
								$line = substr($line, 1);
							}
						}
					}
					$this->continue_value=false;
	
					$line_length = strlen($line);
					for($i=0;$i<$line_length;$i++)
					{
						$char = $line[$i];
	
						switch($char)
						{
							case ':':
								if (strlen($this->buffer) > 0)
								{
									//after an : comes an:
									if ($this->buffer_type == 'value')
									{
										$this->buffer .= $char;
									}else
									{
										$this->add_buffer();
										$this->buffer_type = 'value';
									}
								}
							break;
	
							case ';':
								if (strlen($this->buffer) > 0)
								{
									//after an ; comes an:
									if ($this->buffer_type == 'value')
									{
										$this->buffer .= $char;
									}else
									{
										$this->add_buffer();
										$this->buffer_type = 'param_name';
									}
								}
							break;
	
							case '=':
								
								//if (strlen($this->buffer) > 0)
								//{
									//after an ; comes an:
									if ($this->buffer_type == 'value')
									{
										if($i == ($line_length-1))
										{
											$this->continue_value=true;
										}else
										{
											$this->buffer .= $char;
										}
									}else
									{
										$this->add_buffer();
										$this->buffer_type = 'param_value';
									}
								//}
							break;
	
							default:
								//default is to create the buffer
								$this->buffer .= $char;
							break;
						}
					}
				}
			}
		}
		$this->add_buffer();
		return $this->object;
	}
	
	function add_buffer()
	{
		$this->buffer = str_replace('\r\n', "\r\n", $this->buffer);
		$this->buffer = str_replace('\n', "\r\n", $this->buffer);
		$this->buffer = stripslashes($this->buffer);
		$this->buffer = trim($this->buffer);

		switch($this->buffer_type)
		{
			case 'object_name':
				$this->object[$this->buffer] = array();
				$this->object_name = $this->buffer;
			break;

			case 'param_name':
				$this->object[$this->object_name]['params'][$this->buffer] = '';
				$this->param_name = $this->buffer;
			break;

			case 'param_value':
				if(!isset($this->param_name))
				{
					//go_log(LOG_DEBUG, $this->buffer);
				}
				$this->object[$this->object_name]['params'][$this->param_name] = $this->buffer;
			break;

			case 'value':
				$this->object[$this->object_name]['value'] = $this->buffer;
				unset($this->object_name,	$this->param_name);
			break;
		}
		$this->buffer = '';
	}
	
	function get_timezones($vcalendar)
	{
		$timezones = array();
		if(isset($vcalendar[0]['objects']))
		{
			while($object = array_shift($vcalendar[0]['objects']))
			{
				
				if($object['type'] == 'VTIMEZONE' && isset($object['TZID']) && isset($object['objects']))
				{				
					while($sub_object = array_shift($object['objects']))
					{
						$timezones[$object['TZID']['value']][$sub_object['type']] = $this->convert_timezone( $sub_object['TZOFFSETTO']['value']);
					}				
				}
			}
		}
		return $timezones;
	}
	
	function convert_timezone($timezone)
	{
		return intval(substr($timezone,0,-2));
	}

	function parse_rrule($rrule)
	{
		$rrule_arr = array();

		$rrule = str_replace('RRULE:', '', $rrule);
		
		if(strpos($rrule,';') === false)
		{
			//this must be a vcalendar 1.0 rrule
			//we are attempting to convert it to icalendar format
			
			//GO Supports only one rule everything behind the first rule is chopped
			$hek_pos = strpos($rrule, '#');
			if($hek_pos)
			{
					$space_pos = strpos($rrule, ' ', $hek_pos);
					if($space_pos)
					{
						return false;
						//$rrule = substr($rrule,0,$space_pos);
					}					
			}
			
			$expl_rrule = explode(' ', $rrule);
			
			//the count or until is always in the last element
			if($until = array_pop($expl_rrule))
			{
				if($until{0} == '#')
				{
					$count = substr($until, 1);
					if($count > 0)
					{
						$rrule_arr['COUNT'] = $count;
					}
				}else
				{
					$rrule_arr['UNTIL'] = $until;
				}
			}
			
			
			if($rrule_arr['FREQ'] = array_shift($expl_rrule))
			{
						
				$rrule_arr['INTERVAL'] = '';
				
				$lastchar = substr($rrule_arr['FREQ'], -1, 1);
				while(is_numeric($lastchar))
				{				
					//echo $rrule_arr['FREQ'].'<br>';
					$rrule_arr['INTERVAL'] = $lastchar.$rrule_arr['INTERVAL'];
					$rrule_arr['FREQ'] = substr($rrule_arr['FREQ'], 0, strlen($rrule_arr['FREQ'])-1);
					$lastchar = substr($rrule_arr['FREQ'], -1, 1);
				}
				
				switch($rrule_arr['FREQ'])
				{
					case 'D':
						$rrule_arr['FREQ'] = 'DAILY';
					break;
					
					case 'W':
						$rrule_arr['FREQ'] = 'WEEKLY';
						$rrule_arr['BYDAY'] = implode(',',$expl_rrule);
					break;
					
					case 'MP':
						$rrule_arr['FREQ'] = 'MONTHLY';
						
						//GO Supports only one position in the month
						/*if(count($expl_rrule) > 1)
						{
							//return false;
						}*/	
						$month_time = array_shift($expl_rrule);
						//todo negative month times
						$rrule_arr['BYDAY'] = substr($month_time, 0, strlen($month_time)-1).array_shift($expl_rrule);						
					break;
					
					case 'MD':
						$rrule_arr['FREQ'] = 'MONTHLY';						
						//GO Supports only one position in the month
						if(count($expl_rrule) > 1)
						{
							return false;
						}	
				
						$month_time = array_shift($expl_rrule);
						//todo negative month times						
						//$rrule_arr['BYMONTHDAY'] = substr($month_time, 0, strlen($month_time)-1);
						//for nexthaus
						$rrule_arr['BYMONTHDAY'] = trim($month_time);//substr($month_time, 0, strlen($month_time)-1);
					break;
					
					case 'YM':
						$rrule_arr['FREQ'] = 'YEARLY';
						//GO Supports only one position in the month
						if(count($expl_rrule) > 1)
						{
							return false;
						}	
						$rrule_arr['BYMONTH'] = array_shift($expl_rrule);
					break;
					
					case 'YD':
						//Currently not supported by GO
						return false;
					break;
				}
			}	
		}else
		{
			$params = explode(';', $rrule);

			while($param = array_shift($params))
			{
				$param_arr = explode('=', $param);

				if (isset($param_arr[0]) && isset($param_arr[1]))
				{
					$rrule_arr[strtoupper(trim($param_arr[0]))] = strtoupper(trim($param_arr[1]));
				}
			}
		}		
		
		//go_log(LOG_DEBUG, var_export($rrule_arr,true));
		
		return $rrule_arr;
	}
	
	function get_timezone_offset($date, $timezone_id='')
	{
		$year = substr($date,0,4);
		$month = substr($date,4,2);
		$day = substr($date,6,2);

		if (strpos($date, 'T') !== false)
		{
			$hour = substr($date,9,2);
			$min = substr($date,11,2);
			$sec = substr($date,13,2);
		}else
		{
			$hour = 0;
			$min = 0;
			$sec = 0;
		}
		
		if(isset($this->force_timezone))
		{
			$timezone_offset = $this->force_timezone;
		}else
		{		
			if(strpos($date, 'Z') !== false)
			{
				$timezone_offset = 0;
			}else
			{
				$timezone_offset =  get_timezone_offset(mktime($hour, $min, $sec, $month, $day , $year));

				if(isset($this->timezones[$timezone_id]) && isset($this->timezones[$timezone_id]['STANDARD']))
				{
					$standard_tzoffset = $this->timezones[$timezone_id]['STANDARD'];
					$daylight_tzoffset = isset($this->timezones[$timezone_id]['DAYLIGHT']) ? $this->timezones[$timezone_id]['DAYLIGHT'] : $standard_tzoffset;

					if(date('I', mktime($hour, $min, $sec, $month, $day , $year)) > 0)
					{
						//event is in DST
						$timezone_offset = $daylight_tzoffset;
					}else
					{
						$timezone_offset = $standard_tzoffset;
					}
				}
			}
		}
		return $timezone_offset;
	}

	function parse_date($date, $timezone_id='')
	{	
		$date=trim($date);
		$year = substr($date,0,4);
		$month = substr($date,4,2);
		$day = substr($date,6,2);

		if (strpos($date, 'T') !== false)
		{
			$hour = substr($date,9,2);
			$min = substr($date,11,2);
			$sec = substr($date,13,2);
		}else
		{
			$hour = 0;
			$min = 0;
			$sec = 0;
		}
		
		if(isset($this->force_timezone))
		{
			$timezone_offset = $this->force_timezone;
		}else
		{		
			if(strpos($date, 'Z') !== false)
			{
				$timezone_offset = 0;
			}else
			{
				$timezone_offset =  get_timezone_offset(mktime($hour, $min, $sec, $month, $day , $year));

				if(isset($this->timezones[$timezone_id]) && isset($this->timezones[$timezone_id]['STANDARD']))
				{
					$standard_tzoffset = $this->timezones[$timezone_id]['STANDARD'];
					$daylight_tzoffset = isset($this->timezones[$timezone_id]['DAYLIGHT']) ? $this->timezones[$timezone_id]['DAYLIGHT'] : $standard_tzoffset;

					if(date('I', adodb_mktime($hour, $min, $sec, $month, $day , $year)) > 0)
					{
						//event is in DST
						$timezone_offset = $daylight_tzoffset;
					}else
					{
						$timezone_offset = $standard_tzoffset;
					}
				}
			}
		}
		return adodb_mktime($hour-$timezone_offset, $min, $sec, $month, $day , $year);
	}
	
	function parse_duration($duration)
	{
	 	ereg ('^P([0-9]{1,2}[W])?([0-9]{1,2}[D])?([T]{0,1})?([0-9]{1,2}[H])?([0-9]{1,2}[M])?([0-9]{1,2}[S])?', $data, $output); 
		$weeks 			= ereg_replace('W', '', $duration[1]); 
		$days 			= ereg_replace('D', '', $duration[2]); 
		$hours 			= ereg_replace('H', '', $duration[4]); 
		$minutes 		= ereg_replace('M', '', $duration[5]); 
		$seconds 		= ereg_replace('S', '', $duration[6]); 
		return ($weeks * 60 * 60 * 24 * 7) + ($days * 60 * 60 * 24) + ($hours * 60 * 60) + ($minutes * 60) + ($seconds);	
	}

	

	function add_object()
	{
		$this->objects[] = $this->object;
		$this->object = array();
	}
}
