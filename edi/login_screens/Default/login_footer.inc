
		</td>
	</tr>
	<tr>
	<td id="FooterBar">
	<!-- <a style="color: white;" target="_blank" href="http://www.intermesh.nl"><?php echo $link; ?></a> -->
	</td>
	</tr>
	</table>
	<table>
	<tr><td>
<?php 
$now = time();
$dbtmp = new db;
$dbtmp->query("select * from sum_announcements where due_time > $now order by mtime desc");
$i = 0;
while($dbtmp->next_record()){
	if($i == 0){
		$new = new image("new");
		$new_text = " ".$new->get_html();
	}else{
		$new_text = "";
	}
	$img = new image('offer');
	$anmt[$i]['title'] =  $img->get_html()." ".$dbtmp->f("title").$new_text;
	$anmt[$i]['content'] =  $dbtmp->f("content");
	$anmt[$i]['mtime'] =  $dbtmp->f("mtime");
	$i++;
}


?>
<?php 
if(isset($anmt) && count($anmt)){
	print <<<HEREDOCS
</td></tr>
</table >
<table width="70%" border=1 cellspacing=0 cellpadding=0>
<tr><td bgcolor="white" >
HEREDOCS;
	$i = 0;
	foreach($anmt as $v){
		echo "<div >";
		echo "<h1>{$v['title']}</h1>";
		//$mtime = date("d/m/Y H:i:s",$v['mtime']);
		$mtime = "";
		echo $v['content']."<br>".$mtime."<br><br>";
		echo "</div>";
		$i++;
	}	
}
echo <<<HEREDOCS
</td></tr>
</table>
	</td>
</tr>
</table>
HEREDOCS;
?>

</body>
</html>
