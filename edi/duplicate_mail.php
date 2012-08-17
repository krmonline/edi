<?php
//ini_set("display_errors","On");
require_once("Group-Office.php");
require_once("/usr/local/softnix/apache2/htdocs/edi/classes/duplicatemail.class.inc");
$dup = new duplication_check;
$dup->add_folder('/home/x06301/Maildir/cur');
$dup->add_folder('/home/x06301/Maildir/new');
$dup->check_dup();
?>

