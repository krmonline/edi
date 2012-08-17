#!/usr/local/bin/php
<?php
//ini_set("display_errors","Off");
require_once("/usr/local/softnix/apache2/htdocs/edi/Group-Office.php");
require_once("/usr/local/softnix/apache2/htdocs/edi/classes/duplicatemail.class.inc");
if(count($argv) > 1){
	$username = strtolower($argv[1]);
	$mtime = isset($argv[2])?$argv[2]:90;
	$dup = new duplication_check;
	$dup->add_folder('/home/'.$username.'/Maildir/cur');
	$dup->add_folder('/home/'.$username.'/Maildir/new');
	$dup->check_dup();
}else{
	echo "/usr/local/softnix/apache2/htdocs/edi/duplicate_cmd.php [username] [time]\n";
}


?>
