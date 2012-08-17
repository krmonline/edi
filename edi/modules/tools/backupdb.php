<?php
/*
   Copyright Intermesh 2007
   Author: Merijn Schering <mschering@intermesh.nl>
   Version: 1.0 Release date: 07 March 2007

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2 of the License, or (at your
   option) any later version.
 */

require_once("../../Group-Office.php");
$GO_SECURITY->authenticate();
$GO_MODULES->authenticate('tools');
require_once($GO_LANGUAGE->get_language_file('tools'));

header('Content-Disposition: attachment; filename="groupoffice-dbbackup-'.date('YmdGi').'.sql"');
header('Content-Type: application/download');

echo "#Group-Office version ".$GO_CONFIG->version."\n";
echo "#Generated by Group-Office DB backup tool\n";
echo "#Written by Merijn Schering <mschering@intermesh.nl>\n\n\n";



$db = new db();

$db->query('SHOW TABLES;');
while($db->next_record())
{
	$tables[]=$db->f(0);
}

foreach($tables as $table)
{
	$db->query("SHOW CREATE TABLE `$table`");
	
	if($db->next_record())
	{
		echo "\n#Create table ".$table."\n\n";		
		
		
		echo $db->f(1);
		echo ";\n\n";
	}else {
		die('Failed to dump table "'.$table.'"');
	}
	
	echo "#Dumping data for ".$table."\n\n";
	
	$db->query("SELECT * FROM `$table`");
	
	while($db->next_record(MYSQL_ASSOC))
	{
		if(count($db->Record))
		{
			$fields=array();
			$values=array();
			foreach($db->Record as $field=>$value)
			{
				$fields[]=$field;
				$values[]=addslashes($value);
			}
			
			echo "REPLACE INTO `$table` (`"; 
			
			echo implode('`,`', $fields)."`) VALUES ('";
			echo implode('\',\'',$values)."');\n";
		}
	}
}