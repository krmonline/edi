<?php 

class duplication_check extends logger {
	public $arr_msg = array();
	public $mtime = 90;
	public $db;	
	function __construct(){
		parent::__construct();
		$this->db =new db;
	}
	
	function ReadFromFile($filename){
		if(!file_exists($filename)){
			//$this->log("debug","1");
			return false;
		}
		$fp = fopen($filename,"r");
		$found_from = false;
		$found_to = false;
		$found_subj = false;
		$found_date = false;
		while(!feof($fp)){
			$line = trim(fgets($fp,1024));
			//echo $line."\n";
			if(preg_match("/^From\:\s*(.+)/",$line,$found)){
				$from = $found[1];
				$found_from = true;
				//echo "search found From:".$from."\n";
			}elseif(preg_match("/^Subject\:\s*(.+)$/",$line,$found)){
				$subj = $found[1];
				$md5 = md5($subj);
				//echo "search found subject:".$subj."\n";
				$found_subj = true;
			}elseif(preg_match("/^To\:\s*(.+)$/",$line,$found)){
				$to = $found[1];
				$found_to = true;
				//echo "search found to:".$to."\n";
			}elseif(preg_match("/^Date\:\s*(.+)$/",$line,$found)){
				$date = $found[1];
				$found_date = true;
				//echo "search found date:".$date."\n";
			}
			//$md5 = "dontcare";
			if($found_from && $found_to && $found_subj && $found_date){
				$arr['from'] = $from;
				$arr['to'] = $to;
				$arr['date'] = $date;
				$arr['subject'] = $subj;
				$arr['md5'] =  $md5;
				//$this->log("debug","true,$from,$to,$date,$md5");
				return $arr;
			}
		}	
		//$this->log("debug","false,$from,$to,$date,$md5");
		return false;
		fclose($fp);
	}
	
	/***
	 * Add folder and return all message 
	 * 
	 * ***/
	function add_folder($folder){
			$mtime = $this->mtime;
			$arr_msg = $this->arr_msg; 
	        if(is_dir($folder)){
	        	$folder = escapeshellarg($folder);
	            //check argv
	            $cmd = "sudo /usr/bin/find $folder -mtime -$mtime -type f|/usr/bin/xargs -I {} ls -la {}|/usr/bin/awk '{print \$9}'";
	            //$this->log("Duplicate","sudo /usr/bin/find $folder -mtime -$mtime -type f|/usr/bin/xargs -I {} ls -la {}|/usr/bin/awk '{print \$9}'");
	           // $cmd = "sudo /usr/local/softnix/apache2/htdocs/edi/duplicate_cmd.php $folder $mtime";
	            //echo $cmd;
	            $response = `$cmd`;
	            //echo $response;
	            //die();
	            //echo "/usr/bin/find $folder -mtime -$mtime -type f|/usr/bin/xargs -I {} ls -la {}|/usr/bin/awk '{print \$9}'\n";
				//var_dump($response);
				//echo $cmd."\n";
				//$this->log("Duplicate",$response);
				$arr_files = explode("\n",$response);
				//var_dump($arr_files);
				$i = 0;
				foreach($arr_files as $eachfile){
					$eachfile = trim($eachfile);
					if(file_exists($eachfile)){
						$fp = fopen($eachfile,"r");
						$found_from = false;
						$found_to = false;
						$found_subj = false;
						$found_date = false;
						while(!feof($fp)){
							$line = trim(fgets($fp,1024));
							//echo $line."\n";
							$found = array();
							if(preg_match("/^From\:\s*(.+)/",$line,$found)){
								$from = $found[1];
								$found_from = true;
								//echo "search found From:".$from."\n";
							}elseif(preg_match("/^Subject\:\s*(.+)$/",$line,$found)){
								$subj = $found[1];
								$md5 = md5($subj);
								//echo "search found subject:".$subj."\n";
								$found_subj = true;
							}elseif(preg_match("/^To\:\s*(.+)$/",$line,$found)){
								$to = $found[1];
								$found_to = true;
								//echo "search found to:".$to."\n";
							}elseif(preg_match("/^Date\:\s*(.+)$/",$line,$found)){
								$date = $found[1];
								$found_date = true;
								//echo "search found date:".$date."\n";
							}
							//$md5 = "dontcare";
							if($found_from && $found_to && $found_subj && $found_date){
								//echo $from."\t".$to."\t".$subj."\n";
								if(isset($arr_msg[$md5]) && $arr_msg[$md5]){
									if(isset($md5_count)){
										$md5_count++;	
									}else{
										$md5_count = 0;
									}

									$arr_msg[$md5]['dup'][$md5_count]['date'] = $date;
									$arr_msg[$md5]['dup'][$md5_count]['filename'] = $eachfile;								
								}else{
									$md5_count = 0;
									$arr_msg[$md5]['from'] = $from;
									$arr_msg[$md5]['to'] = $to;
									$arr_msg[$md5]['subj'] = $subj;
									$arr_msg[$md5]['dup'][$md5_count]['date'] = $date;
									$arr_msg[$md5]['dup'][$md5_count]['filename'] = $eachfile;
									//$arr_msg[$md5]['filename'] = $eachfile;					
								}
								//var_dump($arr_msg[$i]);
								$i++;
								$from = "";
								$to = "";
								$subj = "";
								break; 
							}
						}
						fclose($fp);
					}else{
						//echo "file $eachfile not found\n";
					}
				}
				//var_dump($arr_msg);
				//die();
				/*
				foreach($arr_msg as $k => $v){
					$count = count($v);
					if($count > 4){
							echo "================\n";
							echo $v['from']."\t".$v['subj']."\t".$count."\n";
							var_dump($v);
							echo "================\n";
					}				
				}
				*/
				$this->arr_msg = $arr_msg;
				//var_dump($arr_msg);
	        }else{
	        	$this->log("Duplicate","Not found folder $folder");
	        }
	        return count($this->arr_msg);
	}
	
	function check_dup(){
		if(count($this->arr_msg)){
			foreach($this->arr_msg as $k => $v){
				$count = count($v['dup']);
				if($count > 1){
					$log =  "found  $count duplicate with subject '".$v['subj']."'\n";
					$this->log("Duplicate",$log);
					$arr_dup = $v['dup'];
					while(count($arr_dup) > 1){
						$arr_del = array_pop($arr_dup);
						$del = count($arr_dup);
						$log = "delete".$arr_del['filename']." for subj = ".$v['subj']."\n";
						$this->log("Duplicate",$log);
						$filename_shell = escapeshellarg($arr_del['filename']);
						$cmd = "sudo /bin/rm -f $filename_shell";
						$this->log("Duplicate",$cmd);
						`$cmd`;
						$this->tracker($arr_del['date'],$v['from'],$v['to'],$v['subj'],$del,"Delete",$arr_del['filename']);
					}
				}
			}
		}
	}
	
	
	function clear_folder(){
		$this->arr_msg = array();
		return true;
	}
	
	function get_messages(){
		return $this->arr_msg;
	}
	
	function isDuplicateWithSubj($subj){
		$md5 = md5($subj);
		if(isset($this->arr_msg[$md5])){
			$log = "Found duplicate subj = ".$this->arr_msg[$md5]['subj']." from ".$this->arr_msg[$md5]['from']." to ".$this->arr_msg[$md5]['to']." and message hasbeen block\n";
			$this->log("Duplicate",$log);
			return true;
		}else{
			return false;
		}
	}
	
	
	
	function tracker($time,$sender,$recipient,$subject,$duplicate,$action,$filename){
		//$time = strtotime($time);
		$time = time();
		preg_match("/([A_Za-z0-9._]+@[A_Za-z0-9.-]+)/",$sender,$arr_sender);
		if(isset($arr_sender[1])){
			$sender = $arr_sender[1];
		}
		preg_match("/([A_Za-z0-9._]+@[A_Za-z0-9.-]+)/",$recipient,$arr_recipient);
		if(isset($arr_recipient[1])){
			$recipient = $arr_recipient[1];
		}		
		
		$sql = "Insert into `duplicate_mail` (`date`,`sender`,`recipient`,`subject`,`duplicate`,`action`,`filename`) 
		value ('$time','$sender','$recipient','$subject','$duplicate','$action','$filename')";
		//echo $sql."\n";
		$this->db->query($sql);
	}
	
	function get_tracker($start = 0,$limit = 10,$order = "date",$dir = 'DESC'){
		$sql = "select * from `duplicate_mail` order by `$order` $dir limit $start,$limit";
		$this->db->query($sql);
		$i = 0;
		while($this->db->next_record()){
			$record = $this->db->Record;
			$arr_results[$i]['id'] = $record['id'];
			$arr_results[$i]['date'] = date("d/m/Y H:i:s",$record['date']);
			$arr_results[$i]['sender'] = $record['sender'];
			$arr_results[$i]['recipient'] = $record['recipient'];
			$arr_results[$i]['subject'] = $record['subject'];
			$arr_results[$i]['duplicate'] = $record['duplicate'];
			$arr_results[$i]['filename'] = $record['filename'];
			$arr_results[$i]['action'] = $record['action'];
			$i++;
		}
		return $arr_results;
	}
	
}
?>
