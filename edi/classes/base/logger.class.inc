<?php

class logger extends db
{
	var $enabled=false;
	function logger()
	{
		global $GO_CONFIG;

		if($GO_CONFIG->dblog)
		{
			$this->db();
			$this->enabled=true;
		}
			
	}

	function delete($time)
	{
		$sql = "DELETE FROM log WHERE time<$time";
		return $this->query($sql);
	}
	
	function log($module, $text, $link_id='')
	{
		if($this->enabled)
		{
			global $GO_SECURITY;

			$log['user_id']=$GO_SECURITY->user_id;
			$log['time']=get_gmt_time();
			$log['module']=$module;
			$log['text']=addslashes($text);
			$log['link_id']=$link_id;
			$log['id']=$this->nextid('log');

			if($log['id'])
			{
				$this->insert_row('log', $log);
					
				return $log['id'];
			}else
			{
				return false;
			}
		}
	}


	function get_log($module='', $link_id='', $user_id='', $start=0, $offset=0, $sort_field='mtime', $sort_order='DESC',$search = '',$from='',$to='',$log_user)
	{
		$sql = "SELECT * FROM log";

		$where=false;
		/*
		if(!empty($module))
		{
			$where=true;
			$sql .=" WHERE module='$module'";
		}
		*/
		if(!empty($module))
		{
			if($where)
			{
				$sql .= ' AND ';
			}else
			{
				$sql .= ' WHERE ';
			}
				
			$sql .="module='$module'";
			$where=true;
		}

		if(!empty($link_id))
		{
			if($where)
			{
				$sql .= ' AND ';
			}else
			{
				$sql .= ' WHERE ';
			}
				
			$sql .="link_id=$link_id";
			$where=true;
		}

		if(!empty($user_id))
		{
			if($where)
			{
				$sql .= ' AND ';
			}else
			{
				$sql .= ' WHERE ';
			}
				
			$sql .="user_id=$user_id";
			$where=true;
		}
		
		if(!empty($search))
		{
			if($where)
			{
				$sql .= ' AND ';
			}else
			{
				$sql .= ' WHERE ';
			}
				
			$sql .="`text` like  '%$search%'";
			
			$where=true;
		}
		
		if(!empty($log_user))
		{
			if($where)
			{
				$sql .= ' AND ';
			}else
			{
				$sql .= ' WHERE ';
			}
			$dbtmp = new db;
			$dbtmp->query("select `id` from `users` where `username` like '%$log_user%@%'");
			echo "=";
			$dbtmp->next_record();
			$user_id =  $dbtmp->f('id');
			unset($dbtmp);
			$sql .="`user_id` =  '$user_id'";
			
			$where=true;
		}
		
		if(!empty($from) && !empty($to))
		{
			list($fy,$fm,$fd) = explode("/",$from);
			list($ty,$tm,$td) = explode("/",$to);
			$timestamp_from = mktime(0,0,0,$fm,$fd,$fy);
			$timestamp_to = mktime(23,59,59,$tm,$td,$ty);
			if($where)
			{
				$sql .= ' AND ';
			}else
			{
				$sql .= ' WHERE ';
			}

			$sql .="`time` BETWEEN $timestamp_from and $timestamp_to";
			
			$where=true;
		}		

		$sql .= " ORDER BY $sort_field $sort_order";
		//echo $sql;
		$this->query($sql);
		$count = $this->num_rows();

		if($offset>0 && $count> $start)
		{
			$sql .= " LIMIT $start, $offset";
			$this->query($sql);
		}
		return $count;
	}
}
