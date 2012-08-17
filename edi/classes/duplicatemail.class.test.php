<?php 
ini_set("display_error",'Off');
/*
 * You can run this script via command with user root
 * */
require_once('simpletest/autorun.php');
require_once("/usr/local/softnix/apache2/htdocs/edi/Group-Office.php");
require_once("/usr/local/softnix/apache2/htdocs/edi/classes/duplicatemail.class.inc");


/*
 * function นี้จะ clear data ทั้งหมดของ user softnix และ add เพิ่มเข้าไป 2 message ที่มี subject ตรงกัน
 * และทำการ  delete message ที่ duplicate 
 */
class TestDuplicate extends UnitTestCase {
    function testDuplicateCheckFromLoop() {
    	$text = "Return-Path: <krm.online@gmail.com>
    	
Subject:test

Message-Id: <20120817071346.09F9F178260@mail.nikon-edisys.com>

Date: Fri, 17 Aug 2012 14:13:39 +0700 (ICT)

From: krm.online@gmail.com

To: undisclosed-recipients:;



test.
    	";
    	file_put_contents("/tmp/test.txt",$text);
    	$this->assertTrue(file_exists('/tmp/test.txt'), 'File /tmp/test.txt created');
    	$dup = new duplication_check;
    	$this->assertIsA($dup,'duplication_check',"create object name duplication_check");
    	`rm -f /home/softnix/Maildir/cur/*`;
    	`rm -f /home/softnix/Maildir/new/*`;
    	//add folder cur
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$result = ($count)?true:false;
    	//add folder new
    	$this->assertFalse($result,"folder cur should be empty");
    	$count += $dup->add_folder('/home/softnix/Maildir/new');
    	$result = ($count)?true:false;
    	$this->assertFalse($result,"folder new should be empty");
    	$all_file = $dup->get_messages();
    	$count = count($all_file);
    	$this->assertEqual(0,$count,"folder should be empty");
    	$dup->clear_folder();
    	$all_file = $dup->get_messages();
    	$count = count($all_file);
    	$this->assertEqual(0,$count,"folder should be empty");    	
    	`sudo -u filter sendmail -G -i -f 'krm<krm.online@gmail.com>' -- softnix@nikon-edisys.com < /tmp/test.txt;exit`;
    	//sleep(1); //wait for second
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');
    	$this->assertEqual(1,$count,"folder should be 1 message."); 
    	//send again
    	`sudo -u filter sendmail -G -i -f 'krm<krm.online@gmail.com>' -- softnix@nikon-edisys.com < /tmp/test.txt;exit`;
    	//sleep(1); //wait for second
    	$dup->clear_folder();
    	$count = $dup->add_folder('/home/softnix/Maildir/cur'); //add cur 	
    	$count += $dup->add_folder('/home/softnix/Maildir/new');   	//add new
    	$this->assertEqual(1,$count,"folder should be 1 message (now is $count)");
    	$arr_message = $dup->get_messages();
    	$arr = current($arr_message);
		$this->assertEqual(2,count($arr['dup']),"dup array should be 2 messages");
		$dup->check_dup(); //execute to delete duplicate file
		$dup->clear_folder();
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');		
    	$arr_message = $dup->get_messages();
    	$arr = current($arr_message);
		$this->assertEqual(1,count($arr['dup']),"dup array should be 1 messages");		
    	
    	//$this->assertTrue($result,"folder new shuld be empty");
    	
 		//$dup->check_dup();
    }
    
    /*
     * function นี้จะทำการทดอบ การรับ message มา 1 message และ ค้นหาดูว่าจะเจอ message ที่มี subject ตรงกันหรือไม่
     * เพื่อนำไปใช้ใน file master.cf 
     * */
    function TestDuplicateCheckFromSubj(){
    	$subject_create = array("hello softnix","hi softnix");
    	`rm -f /home/softnix/Maildir/cur/*`;
    	`rm -f /home/softnix/Maildir/new/*`;
    	$dup = new duplication_check;
    	$this->assertIsA($dup,'duplication_check',"create object name duplication_check");
     	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');
    	$this->assertEqual(0,$count,"folder should be 0 message (now is $count)");
    	foreach($subject_create as $v){
    		$text = "Return-Path: <krm.online@gmail.com>
    	
Subject:$v

Message-Id: <20120817071346.09F9F178260@mail.nikon-edisys.com>

Date: Fri, 17 Aug 2012 14:13:39 +0700 (ICT)

From: krm.online@gmail.com

To: undisclosed-recipients:;



test.
    	";
	    	unlink("/tmp/test.txt");
	    	$this->assertFalse(file_exists('/tmp/test.txt'), 'File should\'n be create');
	    	file_put_contents("/tmp/test.txt",$text);
	    	$this->assertTrue(file_exists('/tmp/test.txt'), 'File should be created');
	    	`sudo -u filter sendmail -G -i -f 'krm<krm.online@gmail.com>' -- softnix@nikon-edisys.com < /tmp/test.txt;exit`;
    	}
 		$dup->clear_folder();
    	$count = $dup->add_folder('/home/softnix/Maildir/cur');
    	$count += $dup->add_folder('/home/softnix/Maildir/new');		
    	$arr_messages = $dup->get_messages(); 
    	$this->assertEqual(2,count($arr_messages),"Message should be 2 .");	
    	$result = $dup->isDuplicateWithSubj("hello softnix");
    	$this->assertTrue($result,"Should be found subject");
    	
    }
}
?>