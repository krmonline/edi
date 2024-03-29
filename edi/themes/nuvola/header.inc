<?php
$charset = isset($charset) ? $charset : 'UTF-8';
header('Content-Type: text/html; charset='.$charset);
?>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
<script language="javascript" type="text/javascript" src="<?php echo $GO_CONFIG->host; ?>javascript/common.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $GO_CONFIG->host; ?>javascript/ext/adapter/ext/ext-base.js"></script>
<script type="text/javascript" src="<?php echo $GO_CONFIG->host; ?>javascript/ext/ext-all.js"></script> 
<link rel="shortcut icon" href="<?php echo $GO_CONFIG->host; ?>lib/favicon.ico" />

<?php if (isset($GO_HEADER['head'])) echo $GO_HEADER['head']; ?>
<?php require($GO_CONFIG->control_path.'fixpng.inc'); ?>
<link rel="shortcut icon" href="<?php echo $GO_CONFIG->host; ?>lib/favicon.ico" />
<link rel="stylesheet" type="text/css" href="<?php echo $GO_CONFIG->host; ?>javascript/ext/resources/css/ext-all.css" /> 
<link rel="stylesheet" type="text/css" href="<?php echo $GO_CONFIG->host; ?>javascript/ext/resources/css/xtheme-slg3.css" /> 
<link href="<?php echo $GO_THEME->theme_url.'css/common.css'; ?>" rel="stylesheet" type="text/css" />
<?php
if(!empty($GO_MODULES->id))
{
	$GO_THEME->load_module_theme($GO_MODULES->id);
	echo $GO_THEME->get_stylesheet($GO_MODULES->id);
}
?>
<title>

<?php
echo $GO_CONFIG->title;
if (isset($page_title))
{
        echo " - ".$page_title;
}

echo '</title>';
if(isset($GO_HEADER['auto_refresh']))
{	
	$GO_HEADER['auto_refresh']['interval'] = isset($GO_HEADER['auto_refresh']['interval']) ? $GO_HEADER['auto_refresh']['interval'] : $GO_CONFIG->refresh_rate;
	$GO_HEADER['auto_refresh']['action'] = isset($GO_HEADER['auto_refresh']['action']) ? $GO_HEADER['auto_refresh']['action'] : "document.location='".$_SERVER['PHP_SELF']."';";	
	echo '<script type="text/javascript">'.
		'setTimeout("'.$GO_HEADER['auto_refresh']['action'].'", '.($GO_HEADER['auto_refresh']['interval']*1000).');'.	
		'</script>';
}
echo "</head>\r\n";
$htmldirection= isset($htmldirection) ? $htmldirection : 'ltr';
echo '<body dir="'.$htmldirection.'" ';
if (isset($GO_HEADER['body_arguments'])) echo ' '.$GO_HEADER['body_arguments'];
echo '><div id="overDiv" style="position:absolute; visibility:hidden; z-index:1000;"></div>';
?>

<!--Einde header-->
