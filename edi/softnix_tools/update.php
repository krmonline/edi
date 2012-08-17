<?php
require("Group-Office.php");
$a = new db();
$b = new db();
$sql = "select id from users";
$a->query($sql);
while($a->next_record()){
echo $a->f("id")."\n";
$id = $a->f("id");

	$sql = "select * from settings where user_id=$id and name='sort_index_messages_table'";
	$b->query($sql);
	//echo $b->num_rows()."\n";
	if($b->num_rows()){
		$sql = "update settings set value=1 where name='sort_index_messages_table'";
		$b->query($sql);
		echo "$id update\n";
	}else{
		echo "$id insert\n";
		$sql = "insert into settings (`user_id`,`name`,`value`) VALUES ($id,'sort_index_messages_table',1)";
		$b->query($sql);
	}
}
?>
