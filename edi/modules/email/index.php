<?php

/*
   Copyright Intermesh 2003
   Author: Merijn Schering <mschering@intermesh.nl>
   Version: 1.0 Release date: 08 July 2003

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2 of the License, or (at your
   option) any later version.
 */

require_once ("../../Group-Office.php");

$GO_SECURITY->authenticate();
$GO_MODULES->authenticate('email');

require_once ($GO_CONFIG->class_path."mail/imap.class.inc");
require_once ($GO_MODULES->class_path."email.class.inc");
require_once ($GO_LANGUAGE->get_language_file('email'));
$email = new email();

$GO_CONFIG->set_help_url($ml_help_url);

$em_settings = $email->get_settings($GO_SECURITY->user_id);

$account_id = isset ($_REQUEST['account_id']) ? $_REQUEST['account_id'] : 0;
$task = isset ($_REQUEST['task']) ? $_REQUEST['task'] : '';
$uid = isset ($_REQUEST['uid']) ? $_REQUEST['uid'] : 0;
$mailbox = isset ($_REQUEST['mailbox']) ? smart_stripslashes($_REQUEST['mailbox']) : 'INBOX';
$link_back = $GO_MODULES->url.'index.php?account_id='.$account_id.'&mailbox='.urlencode($mailbox);

if (!$account = $email->get_account($account_id)) {
	$account = $email->get_account(0);
}

if(!$account)
{
	header('Location: accounts.php?return_to='.urlencode($link_back));
	exit();
}elseif ($account['password'] == '') {
	//Password lost because of the removal of the insecure encryption
	//Redirect to enter password again.	
	header('Location: account.php?account_id='.$account['id'].'&return_to='.urlencode($link_back).'&feedback='.urlencode($ml_reenter_password));
	exit ();
}elseif ($account["user_id"] != $GO_SECURITY->user_id) {
	header('Location: '.$GO_CONFIG->host.'error_docs/403.php');
	exit ();
}

if(!isset($_SESSION['GO_SESSION']['email_module']['cached']) || isset($_REQUEST['refresh']))
{
	$email->cache_accounts($GO_SECURITY->user_id);
	$_SESSION['GO_SESSION']['email_module']['cached']=true;
}


//search query parameters
$from = isset ($_REQUEST['from']) ? smart_stripslashes(trim($_REQUEST['from'])) : '';
$to = isset ($_REQUEST['to']) ? smart_stripslashes(trim($_REQUEST['to'])) : '';
$subject = isset ($_REQUEST['subject']) ? smart_stripslashes(trim($_REQUEST['subject'])) : '';
$cc = isset ($_REQUEST['cc']) ? smart_stripslashes(trim($_REQUEST['cc'])) : '';
$body = isset ($_REQUEST['body']) ? smart_stripslashes(trim($_REQUEST['body'])) : '';
$before = isset ($_REQUEST['before']) ? smart_stripslashes(trim($_REQUEST['before'])) : '';
$since = isset ($_REQUEST['since']) ? smart_stripslashes(trim($_REQUEST['since'])) : '';
$before = isset ($_REQUEST['before']) ? $_REQUEST['before'] : '';
$since = isset ($_REQUEST['since']) ? $_REQUEST['since'] : '';
$flagged = isset ($_REQUEST['flagged']) ? $_REQUEST['flagged'] : '';
$answered = isset ($_REQUEST['answered']) ? $_REQUEST['answered'] : '';
if ($task == 'set_search_query' || !isset ($_SESSION['email_search_query'])) {
	$mail = new imap();
	$_SESSION['email_search_query'] = $mail->build_search_query($subject, $from, $to, $cc, $body, $before, $since, $before, $since, $flagged, $answered);
}

$page_title = $lang_modules['email'];

$GO_HEADER['head'] = '<script type="text/javascript" src="'.$GO_MODULES->url.'email.js"></script>';
//$GO_HEADER['head'] .= '<script type="text/javascript" src="'.$GO_CONFIG->host.'javascript/base64.js"></script>';


if(isset($_REQUEST['mail_to']))
{
	$qs=str_replace('mailto:','', $_SERVER['QUERY_STRING']);
	$qs=str_replace('?subject','&subject', $qs);

	parse_str($qs, $vars);
	//var_dump($vars);

	$GO_HEADER['body_arguments'] = 'onload="javascript:composer(\'\',\''.smart_stripslashes($vars['mail_to']).'\',\''.smart_stripslashes($vars['subject']).'\',\''.smart_stripslashes($vars['body']).'\')"';
}


require_once ($GO_THEME->theme_path."header.inc");
?>
<script type="text/javascript">
function search_messages()
{
	messages.location.href='search.php?account_id='+messages.document.forms[0].account_id.value+'&mailbox='+messages.document.forms[0].mailbox.value;	
}



function save_message()
{
	popup('save_message.php?account_id='+message.document.forms[0].account_id.value+'&uid='+message.document.forms[0].uid.value+'&mailbox='+message.document.forms[0].mailbox.value+'&filename='+escape(message.document.forms[0].subject.value)+'.eml');
}

function link_message()
{
	popup('<?php echo $GO_CONFIG->control_url; ?>select/global_select.php?multiselect=true&handler='+Base64.encode('<?php echo $GO_MODULES->url; ?>link_message.php?account_id='+message.document.forms[0].account_id.value+'&uid='+message.document.forms[0].uid.value+'&mailbox='+message.document.forms[0].mailbox.value),'600','400');	
}
function link_messages()
{
	var count = messages.table_count_selected('email_form','messages_table');
	
	if(count==0)
	{
		alert('<?php echo addslashes($strNoItemSelected); ;?>');
	}else
	{
		openPopup('link_messages', 'about:blank','600','400', 'yes');
		var old_target = messages.document.forms[0].target;
		messages.document.forms[0].target='link_messages';
		var old_action=messages.document.forms[0].action;
		messages.document.forms[0].action='prepare_message_link_handler.php';
		messages.document.forms[0].submit();
		messages.document.forms[0].target=old_target;
		messages.document.forms[0].action=old_action;
	}
}

function composer(action,mail_to,subject,body)
{
	if(typeof(mail_to) == "undefined")
	{
		mail_to='';
	}
	if(typeof(subject) == "undefined")
	{
		subject='';
	}
	if(typeof(body) == "undefined")
	{
		body='';
	}
	
	if(action != '')
	{
		var url = 'send.php?mail_from='+message.document.forms[0].account_id.value+
		 	'&uid='+message.document.forms[0].uid.value+'&mailbox='+
		 	escape(message.document.forms[0].mailbox.value)+'&action='+action;
	}else
	{
		var url = 'send.php?mail_from='+messages.document.forms[0].account_id.value;
	}
	
	url += '&mail_to='+mail_to+'&mail_subject='+subject+'&mail_body='+escape(body);
	
	var height='<?php echo $GO_CONFIG->composer_height; ?>';
	var width='<?php echo $GO_CONFIG->composer_width; ?>';
	var centered;
	
	x = (screen.availWidth - width) / 2;
	y = (screen.availHeight - height) / 2;
	centered =',width=' + width + ',height=' + height + ',left=' + x + ',top=' + y + ',scrollbars=yes,resizable=yes,status=yes';

	var popup = window.open(url, '_blank', centered);
  if (!popup.opener) popup.opener = self;
	popup.focus();
}
</script>

<table border="0" cellspacing="0" cellpadding="0" style="width:100%;height:100%;">
<tr>
		<td colspan="99" height="60">
			<?php

			echo '<table border="0" cellspacing="0" cellpadding="0"><tr>';
			echo '<td class="ModuleIcons">';
			//softnix edisys
			if($GO_MODULES->write_permission){
				echo "<a href=\"javascript:composer('');\"><img src=\"".$GO_THEME->images['compose']."\" border=\"0\" /><br />".$ml_compose."</a></td>\n";		
				echo '<td class="ModuleIcons">';	
			}

			echo '<a href="javascript:search_messages();"><img src="'.$GO_THEME->images['ml_search'].'" border="0" /><br />'.$ml_search.'</a></td>';
			
			echo '<td class="ModuleIcons">';
			echo '<a href="javascript:document.location=\'index.php?account_id=\'+messages.document.forms[0].account_id.value+\'&mailbox=INBOX&refresh=true\';"><img src="'.$GO_THEME->images['em_refresh'].'" border="0" /><br />'.$ml_refresh.'</a></td>';			
			//echo '<td class="ModuleIcons">';
			//echo '<a href="javascript:window.messages.confirm_delete();"><img src="'.$GO_THEME->images['delete_big'].'" border="0" /><br />'.$ml_delete.'</a></td>';					
			
			if(file_exists($GO_MODULES->modules['email']['path'].'prepare_message_link_handler.php'))
			{
				echo '<td class="ModuleIcons">';
				echo '<a href="javascript:link_messages();"><img src="'.$GO_THEME->images['link'].'" border="0" /><br />'.$strCreateLink.'</a></td>';
			}
			
						
			echo '<td id="accountButtons">';
			echo '<table border="0" cellspacing="0" cellpadding="0"><tr>';

			
			

						
			//if ($GO_MODULES->write_permission) {
			//	echo '<td class="ModuleIcons">';
			//	echo '<a href="accounts.php?return_to='.urlencode($link_back).'"><img src="'.$GO_THEME->images['accounts'].'" border="0" /><br />'.$ml_accounts.'</a></td>';
			/*} else {
				echo '<td class="ModuleIcons">';
				echo '<a href="account.php?account_id='.$account['id'].'&return_to='.urlencode($link_back).'"><img src="'.$GO_THEME->images['accounts'].'" border="0" /><br />'.$ml_edit_account.'</a></td>';
			}*/		
			//echo '<td class="ModuleIcons">';
			//	echo '<a href="javascript:document.location=\'account.php?account_id=\'+messages.document.forms[0].account_id.value+\'&account_tab=folders&return_to='.urlencode($link_back).'\';"><img src="'.$GO_THEME->images['folders'].'" border="0" /><br />'.$ml_folders.'</a></td>';

			
			echo '</td></tr></table>';	
			
			echo '</td><td>';
			
				
			echo '</td><td id="messageButtons" style="display:none;">';
			echo '<table border="0" cellspacing="0" cellpadding="0"><tr>';
			
			
			//echo '<td class="ModuleIcons">';
			//echo "<a href=\"javascript:composer('reply');\"><img src=\"".$GO_THEME->images['reply']."\" border=\"0\" /><br />".$ml_reply."</a></td>\n";
			
			echo '<td class="ModuleIcons">';
			echo '<a href="javascript:document.location=\'index.php?account_id=\'+messages.document.forms[0].account_id.value+\'&mailbox=INBOX&refresh=true\';"><img src="'.$GO_THEME->images['close'].'" border="0" /><br />Close</a></td>';				
		//	echo '<td class="ModuleIcons">';
		//	echo "<a href=\"javascript:composer('reply_all');\"><img src=\"".$GO_THEME->images['reply_all']."\" border=\"0\" /><br />".$ml_reply_all."</a></td>\n";
			//softnix edisys
			//echo '<td class="ModuleIcons">';
			//echo "<a href=\"javascript:composer('forward');\"><img src=\"".$GO_THEME->images['forward']."\" border=\"0\" /><br />".$ml_forward."</a></td>\n";
			//echo '<td class="ModuleIcons">';
			//echo "<a href=\"javascript:popup('properties.php?account_id='+message.document.forms[0].account_id.value+'&uid='+message.document.forms[0].uid.value+'&mailbox='+message.document.forms[0].mailbox.value,'450','500')\"><img src=\"".$GO_THEME->images['properties']."\" border=\"0\" /><br />".$fbProperties."</a></td>\n";
			
			//echo '<td class="ModuleIcons">';
			//echo '<a href="javascript:window.message.print_message();"><img src="'.$GO_THEME->images['print'].'" border="0" /><br />'.$ml_print.'</a></td>';
			
			if(file_exists($GO_MODULES->modules['email']['path'].'save_message.php') && isset($GO_MODULES->modules['filesystem']) && $GO_MODULES->modules['filesystem']['read_permission'])
			{
			//	echo '<td class="ModuleIcons">';
			//	echo '<a href="javascript:save_message();"><img src="'.$GO_THEME->images['save_big'].'" border="0" /><br />'.$cmdSave.'</a></td>';
			}

			//echo '<td class="ModuleIcons" id="previous_button" style="display:none">';
			//echo '<a href="javascript:window.message.previous_message();"><img src="'.$GO_THEME->images['previous'].'" border="0" /><br />'.$cmdPrevious.'</a></td>';		
			
			//echo '<td class="ModuleIcons" id="next_button" style="display:none">';
			//echo '<a href="javascript:window.message.next_message();"><img src="'.$GO_THEME->images['next'].'" border="0" /><br />'.$cmdNext.'</a></td>';		
			
			echo '<td class="ModuleIcons" id="fsButton">';
			if($em_settings['show_preview']=='1')
			{
				//echo '<a href="javascript:close_message_frame();"><img src="'.$GO_THEME->images['close'].'" border="0" /><br />'.$cmdClose.'</a></td>';		
				echo '</td>';	
			}else
			{
				//echo '<a href="javascript:close_message_frame_for_delete();"><img src="'.$GO_THEME->images['close'].'" border="0" /><br />'.$cmdClose.'</a></td>';
				echo '</td>';
			}
			
			echo '</tr></table>';
			echo '</td></tr></table>';			
			?>
	</td>
</tr>
<tr>
	<td id="treeview" style="width:25%">
		<iframe id="treeviewFrame" marginheight="0" marginwidth="0" vspace="0" frameborder="0" style="width:100%;height:100%;" src="blank.html" name="treeview"></iframe>
	</td>
	<td style="width:75%;height:100%" id="messagesTD">
		<iframe marginheight="0" marginwidth="0" vspace="0" frameborder="0" height="50%" style="width:100%;height:50%;" src="messages.php?account_id=<?php echo $account['id']; ?>&mailbox=<?php echo urlencode($mailbox); if(isset($_REQUEST['uid'])) echo '&uid='.$_REQUEST['uid']; ?>" name="messages" id="messages"></iframe>
		<br />
		<iframe marginheight="0" marginwidth="0" vspace="0" frameborder="0" height="50%" style="width:100%;height:50%;" width:100%; src="blank.html" name="message" id="message"></iframe>
	</td>
</tr>
</table>
<?php
require_once ($GO_THEME->theme_path."footer.inc");
