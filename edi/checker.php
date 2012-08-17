<?php
/**
 * @copyright Intermesh 2004
 * @author Merijn Schering <mschering@intermesh.nl>
 * @version $Revision: 1.52 $ $Date: 2006/11/22 09:35:30 $
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */
require_once('Group-Office.php');
$GO_SECURITY->authenticate();
?>
<html>
<head>
<script language="javascript" type="text/javascript">
<!-- Centring window Javascipt mods By Muffin Research Labs//-->

function popup(url,w,h,target)
{

	var centered;
	x = (screen.availWidth - w) / 2;
	y = (screen.availHeight - h) / 2;
	centered =',width=' + w + ',height=' + h + ',left=' + x + ',top=' + y + ',scrollbars=yes,resizable=no,status=no';
	popup = window.open(url, target, centered);
	if (!popup.opener) popup.opener = self;
	popup.focus();

}
</script>
<title><?php echo $GO_CONFIG->title; ?>
</title>
<?php
echo '<meta http-equiv="refresh" content="'.$GO_CONFIG->refresh_rate.';url='.$_SERVER['PHP_SELF'].'?initiated=true">';
//echo '<meta http-equiv="refresh" content="5;url='.$_SERVER['PHP_SELF'].'?initiated=true">';
$height = 0;
$popup=false;
$beep=false;

//if user uses the calendar then check for events to remind
$calendar_module = isset($GO_MODULES->modules['calendar']) ? $GO_MODULES->modules['calendar'] : false;
if ($calendar_module && $GO_MODULES->modules['calendar']['read_permission'])
{
	require_once($calendar_module['class_path'].'calendar.class.inc');
	$cal = new calendar();
	if($remind_events = $cal->get_events_to_remind($GO_SECURITY->user_id))
	{
		$popup=true;
		$height += 200+(20*$remind_events);
	}
}

$task = isset($_REQUEST['task']) ? $_REQUEST['task'] : '';


$_SESSION['GO_SESSION']['email_module']['notified'] = isset($_SESSION['GO_SESSION']['email_module']['notified']) ? $_SESSION['GO_SESSION']['email_module']['notified'] : 0;
$_SESSION['GO_SESSION']['email_module']['new'] = 0;


if($_SESSION['GO_SESSION']['start_module'] != 'email' || isset($_REQUEST['initiated']))
{
	//check for email
	if (isset($GO_MODULES->modules['email']) && $GO_MODULES->modules['email']['read_permission'])
	{
		require_once($GO_MODULES->modules['email']['class_path'].'email.class.inc');
		require_once($GO_CONFIG->class_path.'mail/imap.class.inc');
		$imap = new imap();
		$email = new email();
		
		$settings = $email->get_settings($GO_SECURITY->user_id);
		

		if(!isset($_SESSION['GO_SESSION']['email_module']['cached']))
		{
			$email->cache_accounts($GO_SECURITY->user_id);
			$_SESSION['GO_SESSION']['email_module']['cached']=true;
		}else {
			$email->cache_accounts($GO_SECURITY->user_id,true);
		}
		
		 $_SESSION['GO_SESSION']['email_module']['new']=$email->get_total_unseen($GO_SECURITY->user_id);


		if ($_SESSION['GO_SESSION']['email_module']['new'] > 0 && $_SESSION['GO_SESSION']['email_module']['new'] > $_SESSION['GO_SESSION']['email_module']['notified'])
		{			
			if($settings['beep']=='1')
			{	
				$beep = true;
			}
			$height += 120;
			if($settings['open_popup']=='1')
			{
				$popup=true;
			}else
			{
				$_SESSION['GO_SESSION']['email_module']['notified']=$_SESSION['GO_SESSION']['email_module']['new'];
			}
		}elseif($_SESSION['GO_SESSION']['email_module']['new'] < $_SESSION['GO_SESSION']['email_module']['notified'])
		{
			$_SESSION['GO_SESSION']['email_module']['notified']=	$_SESSION['GO_SESSION']['email_module']['new'];		
		}
		
	}
}

require($GO_CONFIG->class_path.'base/reminder.class.inc');
$rm = new reminder();

$reminder_count = $rm->get_reminders($GO_SECURITY->user_id);

if($reminder_count)
{
	$height += 120+(20*$reminder_count);
}



if ($reminder_count || ($popup && isset($_REQUEST['initiated'])))
{
	if($height > 600) $height = 600;

	echo '<script language="javascript" type="text/javascript">'.
	'popup("'.$GO_CONFIG->control_url.'reminder.php", "600", "'.$height.'", "reminder");'.
	'</script>';
}
?>
<link href="<?php echo $GO_THEME->theme_url.'css/checker.css'; ?>" rel="stylesheet" type="text/css" />
</head>
<body>
<?php

if (isset($GO_MODULES->modules['helpdesk']) && $GO_MODULES->modules['helpdesk']['read_permission'])
{
	require_once($GO_MODULES->modules['helpdesk']['class_path']."helpdesk.class.inc");
	$helpdesk = new helpdesk();

	$hd_settings = $helpdesk->get_settings($GO_SECURITY->user_id);

	$statuses = explode(',',$hd_settings['statuses']);
	
	if($count = $helpdesk->get_tickets(0, 0, 'id', 'ASC', $statuses))
	{
		$GO_THEME->load_module_theme('helpdesk');
		echo '<a href="'.$GO_MODULES->modules['helpdesk']['url'].'" target="main"><img src="'.$GO_THEME->images['ticket_alert'].'" border="0" align="absmiddle" /> '.$count.'</a>&nbsp;';
	}
}

if (isset($GO_MODULES->modules['email']) && $GO_MODULES->modules['email']['read_permission'] && $_SESSION['GO_SESSION']['email_module']['new']>0)
{
	echo '<a href="'.$GO_MODULES->modules['email']['url'].'" target="main"><img src="'.$GO_THEME->images['mail'].'" border="0" align="absmiddle" /> '.$_SESSION['GO_SESSION']['email_module']['new'].'</a>';
}

if($beep && !$popup && isset($_REQUEST['initiated']))
{


	echo '<br /><br /><br /><object width="0" height="0">'.
		'<param name="movie" value="'.$GO_THEME->sounds['reminder'].'">'.
		'<param name="loop" value="false">'.
		'<embed src="'.$GO_THEME->sounds['reminder'].'" loop="false" width="1" height="1">'.
		'</embed>'.
		'</object>';
}


foreach($GO_MODULES->modules as $module)
{
	if($module['read_permission'] && $module['id'] != 'search' && file_exists($module['class_path'].$module['id'].'.class.inc'))
	{
		require_once($module['class_path'].$module['id'].'.class.inc');
		$class = new $module['id'];
	
		if(method_exists($class, '__on_checker'))
		{	
			$class->__on_checker();
		}
	}
}


?>

</body>
</html>

