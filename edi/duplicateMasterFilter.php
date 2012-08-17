#!/usr/local/bin/php
<?php
require_once("/usr/local/softnix/apache2/htdocs/edi/Group-Office.php");
require_once("/usr/local/softnix/apache2/htdocs/edi/classes/duplicatemail.class.inc");
//$a = var_export($argv,true);
$tmpfname = $argv[5];
//section filter
$dup = new duplication_check;
$result = $dup->ReadFromFile($tmpfname);
if($result){
	//$a = var_export($result,true);
	//$dup->log("debug","$a");
	if($result['subject']){
		//$dup->log("debug","get subj");
		$subj = $result['subject'];
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');
    	$found = $dup->isDuplicateWithSubj($subj);
    	//$dup->log("debug","get found");
    	if($found){
    		//drop this message
    		$dup->log("Duplicate","drop this message with subject '$subj'");
    		$del = 1;//message count to delete
    		$filename = "queue";
    		$dup->tracker($result['date'],$result['from'],$result['to'],$result['subject'],$del,"Drop",'Queue(Master.cf)');
    	}else{
    		//send mail to folder with command
    		//`sudo -u filter sendmail -G -i -f 'krm<krm.online@gmail.com>' -- softnix@nikon-edisys.com < /tmp/test.txt;exit`;
    		$argv[0]  = "sudo -u filter /usr/sbin/sendmail -G -i ";
    		$argv[5] = "";
    		$cmd = implode(" ",$argv);
    		$cmd .= " < $tmpfname";
    		//$dup->log("Duplicate",$cmd);
    		$tmp = `$cmd`;
    		
    	}
	}
}else{
	//error 
	$dup->log("Duplicate","error 40 function ReadFromFile return false");
}

?>