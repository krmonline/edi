<?php 
require('../../Group-Office.php');
require("/usr/local/softnix/apache2/htdocs/edi/classes/duplicatemail.class.inc");
$dup = new duplication_check;
$action = isset($_POST['action'])?$_POST['action']:'';
switch($action){
	case 'getlog':
		$start =isset($_POST['start'])?$_POST['start']:0;
		$limit = isset($_POST['limit'])?$_POST['limit']:20;
		$sort = isset($_POST['sort'])?$_POST['sort']:'date';
		$dir = isset($_POST['dir'])?$_POST['dir']:'desc';
		$arr_results = $dup->get_tracker($start,$limit,$sort,$dir);
		$results = "";
		foreach($arr_results as $v){
			$text = "";
			foreach($v as $k => $v2){
				if($text){
					$text .= ",";
				}
				$text .= "'$k':'$v2'";
			}
			
			if($results){
				$results .= ",";
			}
			
			$results .= "{".$text."}";
			
		}
		$dup->db->query("select count(`id`) c from `duplicate_mail`");
		$dup->db->next_record();
		$limit = $dup->db->Record['c'];
		echo "{docs:[".$results."],total:$limit}";		
	break;
	case 'cleardata':
		$results = $dup->db->query("truncate `duplicate_mail`");
		echo "{'status':'ok','error':'$results'}";
	break;
}
?>
