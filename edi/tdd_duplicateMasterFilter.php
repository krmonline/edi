<?php 
ini_set("display_error",'Off');
/*
 * You can run this script via command with user root
 * */
require_once('simpletest/autorun.php');
require_once("/usr/local/softnix/apache2/htdocs/edi/Group-Office.php");
require_once("/usr/local/softnix/apache2/htdocs/edi/classes/duplicatemail.class.inc");



/*
 * I test with user softnix 
 * */
class TestOfLogging extends UnitTestCase {
	function testsendmail(){
		`rm -f /home/softnix/Maildir/cur/*`;
    	`rm -f /home/softnix/Maildir/new/*`;
		$dup = new duplication_check;
    	$this->assertIsA($dup,'duplication_check',"create object name duplication_check");
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');
    	$this->assertEqual(0,$count,"folder should be 0 message (now is $count)");
    	$socket = fsockopen("localhost","25",$errorno,$errstr);
    	$this->assertEqual(0,$errorno,"Errorno should be 0");
    	$line = fgets($socket);
    	//echo $line;
    	$this->assertTrue(preg_match("/220/",$line),"smtp should return 220");
    	fwrite($socket,"helo mail\r\n");
    	$line = fgets($socket);
		$this->assertTrue(preg_match("/250/",$line),"smtp should return 250");
		fwrite($socket,"mail from:krm.online@gmail.com\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/Ok/",$line),"mail from should return ok => $line");
		fwrite($socket,"rcpt to:softnix@nikon-edisys.com\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/Ok/",$line),"rcpt should return ok => $line");
		fwrite($socket,"data\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/354/",$line),"data should return 354 => $line");
		$text = "To:softnix@nikon-edisys.com\r\nSubject:hello world\r\nhelo test\r\n.\r\n";
		fwrite($socket,$text);
		$line = fgets($socket);
		$this->assertTrue(preg_match("/queued/",$line),"data should send to queued => $line");
		sleep(1);
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');
    	$this->assertEqual(1,$count,"Message should be 1 .");
    	
    	//send mail with new subject
    	fwrite($socket,"helo mail\r\n");
    	$line = fgets($socket);
		$this->assertTrue(preg_match("/250/",$line),"smtp should return 250");
		fwrite($socket,"mail from:krm.online@gmail.com\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/Ok/",$line),"mail from should return ok => $line");
		fwrite($socket,"rcpt to:softnix@nikon-edisys.com\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/Ok/",$line),"rcpt should return ok => $line");
		fwrite($socket,"data\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/354/",$line),"data should return 354 => $line");
		$text = "To:softnix@nikon-edisys.com\r\nSubject:hello world2\r\nhelo test\r\n.\r\n";
		fwrite($socket,$text);
		$line = fgets($socket);
		$this->assertTrue(preg_match("/queued/",$line),"data should send to queued => $line");     	
		sleep(1);
		$dup->clear_folder();
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');
    	$this->assertEqual(2,$count,"Message should be 2 . => $count");
    	    	
    	//send duplicate with the same subject
    	fwrite($socket,"helo mail\r\n");
    	$line = fgets($socket);
		$this->assertTrue(preg_match("/250/",$line),"smtp should return 250");
		fwrite($socket,"mail from:krm.online@gmail.com\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/Ok/",$line),"mail from should return ok => $line");
		fwrite($socket,"rcpt to:softnix@nikon-edisys.com\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/Ok/",$line),"rcpt should return ok => $line");
		fwrite($socket,"data\r\n");
		$line = fgets($socket);
		$this->assertTrue(preg_match("/354/",$line),"data should return 354 => $line");
		$text = "To:softnix@nikon-edisys.com\r\nSubject:hello world\r\nhelo test\r\n.\r\n";
		fwrite($socket,$text);
		$line = fgets($socket);
		$this->assertTrue(preg_match("/queued/",$line),"data should send to queued => $line");    	
		sleep(1);
		$dup->clear_folder();
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');
    	$this->assertEqual(2,$count,"Message should be 2 . => $count");    	
    	//fwrite($socket,"mail from:krm.online@gmail.com");
    	//$line = fgets($socket);
     	//echo $line;   	
	}
}
?>