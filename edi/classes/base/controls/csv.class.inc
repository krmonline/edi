<?php
/**
 * @copyright Intermesh 2007
 * @author Merijn Schering <mschering@intermesh.nl>
 * @version $Revision:  $ $Date:  $
 *
   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2 of the License, or (at your
   option) any later version.

 * @package Framework
 * @subpackage Controls
 */

/**
 * Creates a table that uses tabs to show multiple screens
 * 
 * @package Framework
 * @subpackage Controls
 * 
 * @access public
 */

require_once($GO_CONFIG->class_path.'base/controls/html_element.class.inc');
 
class csv
{
	var $delimiter;
	var $encapsulator;
	var $csv;

	
	function csv($delimiter=',', $encapsulator='"')
	{
		$this->delimiter=$delimiter;
		$this->encapsulator=$encapsulator;
		
	}
	
	function add_record($values)
	{
		$escaped_values = array();
		foreach($values as $value)
		{
			$escaped_values[]=str_replace($this->encapsulator, $this->encapsulator.$this->encapsulator, $value);
		}

		$this->csv .= $this->encapsulator.implode($this->encapsulator.$this->delimiter.$this->encapsulator, $escaped_values).$this->encapsulator."\n";
	}
	
	function get_csv()
	{
		return $this->csv;
	}
	
	
	function import_table($table)
	{
		
		if(count($table->headings))
		{
			$record = array();
			foreach($table->headings as $cell)
			{				
				$record[]=strip_tags(str_replace('<br />',' ',$cell->innerHTML));
				if(isset($cell->attributes['colspan']))
				{
					for($i=1;$i<$cell->attributes['colspan'];$i++)
					{
						$record[]='';
					}
				}				
			}
			$this->add_record($record);
		}
		
		if(isset($table->autosort) && $table->autosort)
		{
			if($table->sort_ascending)
			{
				asort($table->sort_table);
			}else
			{
				arsort($table->sort_table);
			}

			foreach($table->sort_table as $key=>$value)
			{
				$row = $table->rows[$key];
				$record = array();
				foreach($row->cells as $cell)
				{				
					$record[]=strip_tags(str_replace('<br />',' ',$cell->innerHTML));
					if(isset($cell->attributes['colspan']))
					{
						for($i=1;$i<$cell->attributes['colspan'];$i++)
						{
							$record[]='';
						}
					}				
				}
				$this->add_record($record);
				
			}
		}else
		{
		
			foreach($table->rows as $row)
			{
				$record = array();
				foreach($row->cells as $cell)
				{				
					$record[]=strip_tags(str_replace('<br />',' ',$cell->innerHTML));
					if(isset($cell->attributes['colspan']))
					{
						for($i=1;$i<$cell->attributes['colspan'];$i++)
						{
							$record[]='';
						}
					}				
				}
				$this->add_record($record);
			}
		}
	}
}