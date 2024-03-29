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


$filename = basename($fv->path);
$extension = get_extension($filename);
$type = mime_content_type($fv->path);
$location = dirname($fv->path);
$share = $fs->get_share($fv->path);
//do not let user share it's home folder or modify the name!
$write_perms = ($fs->has_write_permission($GO_SECURITY->user_id, $fv->path) && !$fs->is_home_path($GO_SECURITY->user_id, $fv->path));

$return_to = isset($_REQUEST['return_to']) ? $_REQUEST['return_to'] : $_SERVER['PHP_SELF'].'?path='.urlencode($return_to_path);
$link_back = $_SERVER['PHP_SELF'].'?task=properties&path='.$urlencoded_path.'&return_to='.urlencode($return_to);

$prop_task = isset($_REQUEST['prop_task']) ? $_REQUEST['prop_task'] : '';

if($prop_task == 'mail')
{
	$_SESSION['attach_array'] = array ();
	require_once ($GO_MODULES->modules['email']['class_path']."email.class.inc");
	$email = new email();

	if ($fs->has_read_permission($GO_SECURITY->user_id, $fv->path)) {
		$tmp_file = $GO_CONFIG->tmpdir.md5(uniqid(time()));
		if (copy($fv->path, $tmp_file)) {
			$email->register_attachment($tmp_file, $filename, filesize($fv->path), mime_content_type($fv->path));
		}
	} else {
		$popup_feedback .= access_denied_box(basename($file));
	}

	$form->innerHTML .= '<script type="text/javascript" language="javascript">';
	$form->innerHTML .= 'popup("'.$GO_MODULES->modules['email']['url'].'send.php?email_file=true","'.$GO_CONFIG->composer_width.'","'.$GO_CONFIG->composer_height.'");';
	$form->innerHTML .= '</script>';

}


$menu = new button_menu();
$form->add_html_element(new input('hidden','close'));
$form->add_html_element(new input('hidden','goto_url'));
$form->add_html_element(new input('hidden','properties_task','',false));

$tabstrip = new tabstrip('properties_tab', $strProperties);
$tabstrip->set_attribute('style','width:100%');
$tabstrip->set_return_to(htmlspecialchars($return_to));

//$tabstrip->add_tab('properties', $fbGeneral);
//$tabstrip->add_tab('links', $strLinks);
if ($share)
{
	$tabstrip->add_tab('read_permissions', $strReadRights);
	if(is_writable($fv->path))
	{
		$tabstrip->add_tab('write_permissions', $strWriteRights);
	}
}

$menu = new button_menu();


if(!is_dir($fv->path))
{
	$gota_supported = file_exists($GO_MODULES->modules['filesystem']['path'].'jnlp.php');
	$fs_settings = $fs->get_settings($GO_SECURITY->user_id);
	if($fs_settings['use_gota']=='1' && $gota_supported)
	{
		$menu->add_button(
			'upload',
			$fs_download,
			'jnlp.php?path='.$urlencoded_path);
	}else
	{
		$menu->add_button(
			'upload',
			$fs_download,
			'download.php?mode=download&path='.$urlencoded_path);
	}

	if($fs->is_viewable_in_browser($fv->path))
	{
		$menu->add_button(
		'magnifier_big',
		$fs_view,
		'download.php?mode=inline&path='.$urlencoded_path, array('target'=>'_blank'));
	}

	if(eregi('htm', $extension))
	{
		$menu->add_button(
		'new_doc',
		$cmdEdit,
		'edit.php?path='.$urlencoded_path);
	}

	if(eregi('eml', $extension) && file_exists($GO_CONFIG->control_path.'mimeviewer/mimeviewer.php'))
	{
		//softnix disabled
		//$menu->add_button(
		//'magnifier_big',
		//$fs_view,
		//$GO_CONFIG->control_url.'mimeviewer/mimeviewer.php?path='.$urlencoded_path,array('target'=>'_blank'));
	}

	if (isset($GO_MODULES->modules['email']) && $GO_MODULES->modules['email']['read_permission']) {
		//softnix disabled
		//$menu->add_button('fs_email', $lang_modules['email'],"javascript:document.forms[0].prop_task.value='mail';document.forms[0].submit();");
	}
	
	if(isset($GO_MODULES->modules['logviewer']) && $GO_MODULES->modules['logviewer']['read_permission'])
	{
		$GO_THEME->load_module_theme('logviewer');
		
		require($GO_LANGUAGE->get_language_file('logviewer'));
		
		$menu->add_button(
		'logviewer',
		$lv_view_log,
		"javascript:popup('".$GO_MODULES->modules['logviewer']['url'].'index.php?link_id='.$link_id."','900','400');");
	}
	
}

if($tabstrip->get_active_tab_id()=='links')
{
	load_control('links_list');
	$links_list = new links_list($link_id, '0', $link_back);
	$menu->add_button(
	'delete_big',
	$cmdDelete,
	$links_list->get_delete_handler());
	$menu->add_button(
	'unlink',
	$cmdUnlink,
	$links_list->get_unlink_handler());
}

//softnix disabled
//$menu->add_button('link', $strCreateLink, $GO_LINKS->search_link($link_id, 6, 'opener.'.$tabstrip->get_tab_handler_for_function('links')));
$form->add_html_element($menu);



$form->add_html_element(new input('hidden', 'prop_task', '', false));
$form->add_html_element(new input('hidden', 'path', $fv->path, false));

switch($tabstrip->get_active_tab_id())
{
	case 'read_permissions':
		$tabstrip->innerHTML .= get_acl($share['acl_read']);
		$tabstrip->add_html_element(new html_element('br'));
		$tabstrip->add_html_element(new button($cmdClose, 'javascript:document.location=\''.$_SERVER['PHP_SELF'].'?path='.urlencode($return_to_path).'\';'));
		break;

	case 'write_permissions':
		$tabstrip->innerHTML .= get_acl($share['acl_write']);
		$tabstrip->add_html_element(new html_element('br'));
		$tabstrip->add_html_element(new button($cmdClose, 'javascript:document.location=\''.$_SERVER['PHP_SELF'].'?path='.urlencode($return_to_path).'\';'));
		break;

	case 'links':
		$tabstrip->add_html_element($links_list);
		$tabstrip->add_html_element(new button($cmdClose, "javascript:document.location='".htmlspecialchars($return_to)."'"));
		break;

	default:
		if (isset($feedback))
		{
			$p = new html_element('p', $feedback);
			$p->set_attribute('class','Error');
			$tabstrip->add_html_element($p);
		}

		$table = new table();
		$row = new table_row();
		$row->add_cell(new table_cell($strName.':*'));
		$cell = new table_cell();

		if ($write_perms)
		{
			if(is_dir($fv->path))
			{
				$input = new input('text', 'name', basename($fv->path));
				$input->set_attribute('style','width:300px;');
				$cell->add_html_element($input);
			}else
			{
				$input = new input('text', 'name', strip_extension(basename($fv->path)));
				$input->set_attribute('style','width:300px;');

				$cell->add_html_element($input);
				$form->add_html_element(new input('hidden', 'extension', get_extension(basename($fv->path))));
				$form->add_html_element(new input('hidden', 'location', dirname($fv->path)));
			}
		}else
		{
			$cell->innerHTML .= basename($fv->path);
		}
		$row->add_cell($cell);

		$table->add_row($row);
		$row = new table_row();

		$row->add_cell(new table_cell($fbLocation.':'));

		if (dirname($GO_CONFIG->file_storage_path).$GO_CONFIG->slash.basename($GO_CONFIG->file_storage_path) == $location)
		{
			$row->add_cell(new table_cell($GO_CONFIG->slash));
		}else
		{
			//softnix  change to url path
			//$row->add_cell(new table_cell(str_replace($GO_CONFIG->file_storage_path,$GO_CONFIG->slash,$location)));
			$row->add_cell(new table_cell(str_replace($GO_CONFIG->file_storage_path,$GO_CONFIG->urlfile,$fv->path)));
		}
		$table->add_row($row);

		$row = new table_row();
		$cell = new table_cell('&nbsp;');
		$cell->set_attribute('colspan','2');
		$row->add_cell($cell);
		$table->add_row($row);

		$row = new table_row();
		$row->add_cell(new table_cell($strType.':'));

		if (is_dir($fv->path))
		{
			$img = new image('folder');
			$img->set_attribute('style','width:16px;height:16px;border:0;margin-right:5px;');
			$img->set_attribute('align','absmiddle');
			$cell = new table_cell($img->get_html().$fbFolder);
		}else
		{
			$img = new image('',get_filetype_image($extension));
			$img->set_attribute('style','width:16px;height:16px;border:0;margin-right:5px;');
			$img->set_attribute('align','absmiddle');
			$cell = new table_cell($img->get_html().get_filetype_description($extension).'&nbsp;('.mime_content_type($fv->path).')');
		}
		$cell->set_attribute('valign','top');
		$row->add_cell($cell);
		$table->add_row($row);

		$row = new table_row();
		$row->add_cell(new table_cell($strSize.':'));

		if (is_dir($fv->path) && !isset($_REQUEST['calc_size']))
		{

			$link = new hyperlink($_SERVER['PHP_SELF'].'?task=properties&path='.$urlencoded_path.'&calc_size=true', $fs_calculate_folder_size);
			$link->set_attribute('class','normal');
			$row->add_cell(new table_cell($link->get_html()));
		}else
		{
			$row->add_cell(new table_cell(format_size($fs->size($fv->path))));
		}
		$table->add_row($row);

		$row = new table_row();
		$cell = new table_cell('&nbsp;');
		$cell->set_attribute('colspan','2');
		$row->add_cell($cell);
		$table->add_row($row);


		$row = new table_row();
		$row->add_cell(new table_cell($strCreated.':'));
		$row->add_cell(new table_cell(date($_SESSION['GO_SESSION']['date_format'].' '.$_SESSION['GO_SESSION']['time_format'], get_time(filectime($fv->path)))));
		$table->add_row($row);

		$row = new table_row();
		$row->add_cell(new table_cell($strAccessed.':'));
		$row->add_cell(new table_cell(date($_SESSION['GO_SESSION']['date_format'].' '.$_SESSION['GO_SESSION']['time_format'], get_time(fileatime($fv->path)))));
		$table->add_row($row);

		$row = new table_row();
		$row->add_cell(new table_cell($strModified.':'));
		$row->add_cell(new table_cell(date($_SESSION['GO_SESSION']['date_format'].' '.$_SESSION['GO_SESSION']['time_format'], get_time(filemtime($fv->path)))));
		$table->add_row($row);


		if (is_dir($fv->path))
		{
			$row = new table_row();
			$cell = new table_cell('&nbsp;');
			$cell->set_attribute('colspan','2');
			$row->add_cell($cell);
			$table->add_row($row);

			$disabled = ($fs->is_owner($GO_SECURITY->user_id, $fv->path) || $GO_MODULES->write_permission) ? false : true;


			$checkbox = new checkbox('share_folder', 'share_folder', $fv->path, $fs_activate_sharing, $share, $disabled);
			$checkbox->set_attribute('onclick','javascript:confirm_unshare(\''.htmlentities($fs_confirm_unshare, ENT_QUOTES).'\');');

			$row = new table_row();
			$cell = new table_cell($checkbox->get_html());
			$cell->set_attribute('colspan','2');
			$row->add_cell($cell);
			$table->add_row($row);

			if ($disabled && $share)
			{
				$form->add_html_element(new input('hidden','share_folder',$fv->path));
			}
			
			
			$fs_settings = $fs->get_settings($GO_SECURITY->user_id);
			if($fs_settings['notify']=='0')
			{
			
			
				$checkbox = new checkbox('notify', 'notify', $fv->path, $fs_notify_folder, $fs->is_notified(addslashes($fv->path), $GO_SECURITY->user_id));
				//$checkbox->set_attribute('onclick','javascript:confirm_unshare(\''.htmlentities($fs_confirm_unshare, ENT_QUOTES).'\');');
	
				$row = new table_row();
				$cell = new table_cell($checkbox->get_html());
				$cell->set_attribute('colspan','2');
				$row->add_cell($cell);
				$table->add_row($row);
			}
			
			
		}
		
		
		
		if (!is_dir($fv->path))
		{
			$file = $fs->get_file(addslashes($fv->path));	
			
			if($write_perms)
			{
	
				$row = new table_row();
				$row->add_cell(new table_cell($fs_status.':'));
		
				$select = new select('status_id', $file['status_id']);
				//$select->set_attribute('onchange','javascript:set_text(this.value);');
				$fs->get_statuses();
				$select->add_value(0, $fs_no_status);
				while($fs->next_record())
				{
					$select->add_value($fs->f('id'), $fs->f('name'));
				}
				$cell = new table_cell($select->get_html());
				
				if($GO_MODULES->write_permission)
				{
					$img = new image('edit');
					$img->set_attribute('align','absmiddle');
					$img->set_attribute('style','border:0px;margin-left:5px;');
	
					$link = new hyperlink('javascript:popup(\'statuses.php\', \'300\', \'300\');',$img->get_html(), $strEdit);
	
					$cell->add_html_element($link);
				}
				$row->add_cell($cell);
				$table->add_row($row);
				
				$row = new table_row();
				$cell = new table_cell($strComments.':');
				$cell->set_attribute('style','vertical-align:top');
				$row->add_cell($cell);
				
				$textarea = new textarea('comments','');
				$textarea->set_attribute('style','width:300px;height:80px;');
				$row->add_cell(new table_cell($textarea->get_html()));
				$table->add_row($row);
			}else {
				$row = new table_row();
				$row->add_cell(new table_cell($fs_status.':'));
		
				if($file['status_id']>0)
				{
					$status_name=$fs->get_status_name($file['status_id']);
				}
				if(empty($status_name))
				{				
					$status_name=$fs_no_status;
				}
				$cell = new table_cell($status_name);
				
				$row->add_cell($cell);
				$table->add_row($row);
			}
	
			//$tabstrip->add_html_element($table);
			
			
			
			$status_table = new table();
			$status_table->set_attribute('class','go_table');
			$status_table->set_attribute('style','margin-botom:20px;');
			$status_table->add_column(new table_heading($fs_status));
			$status_table->add_column(new table_heading($fs_author));
			$status_table->add_column(new table_heading($strDate));
	
			if($fs->get_status_history($file['link_id']))
			{
				while($fs->next_record())
				{
					$status_row = new table_row($fs->f('id'));
	
					$status_cell = new table_cell(htmlspecialchars($fs->f('status_name')));
					if($fs->f('comments')!='')
					{
						$status_cell->set_attribute('style','border-bottom:0px;font-weight:bold');	
					}else {
						$status_cell->set_attribute('style','font-weight:bold');	
					}
					$status_row->add_cell($status_cell);
	
					$status_cell = new table_cell(show_profile($fs->f('user_id')));
					if($fs->f('comments')!='')
					{
						$status_cell->set_attribute('style','border-bottom:0px;');	
					}
					$status_row->add_cell($status_cell);
					$status_cell = new table_cell(get_timestamp($fs->f('ctime')));
					if($fs->f('comments')!='')
					{
						$status_cell->set_attribute('style','border-bottom:0px;');	
					}
					$status_row->add_cell($status_cell);
					$status_table->add_row($status_row);
					
					
					if($fs->f('comments')!='')
					{
						$status_row = new table_row();
						
						$status_cell = new table_cell($fs->f('comments'));
						$status_cell->set_attribute('colspan','99');
						$status_row->add_cell($status_cell);
						
						$status_table->add_row($status_row);	
					}
					
					
					
					
					
				}
				$tabstrip->add_html_element($table);
				$tabstrip->add_html_element($status_table);
			}else
			{
				$tabstrip->add_html_element($table);
				$status_row = new table_row();
				$status_cell = new table_cell($fs_no_status_history);
				$status_cell->set_attribute('colspan','99');
				$status_row->add_cell($status_cell);
				$status_table->add_row($status_row);

			}
			
		}else
		{
			$tabstrip->add_html_element($table);
		}
		

		if ($write_perms)
		{
			$tabstrip->add_html_element(new button($cmdOk, "javascript:save('properties','true');"));
			$tabstrip->add_html_element(new button($cmdApply, "javascript:save('properties','false');"));
		}
		$tabstrip->add_html_element(new button($cmdClose, 'javascript:document.location=\''.htmlspecialchars($return_to).'\';'));

		break;
}

$form->add_html_element($tabstrip);
?>
<script type="text/javascript">
function save(task, close)
{
	document.forms[0].properties_task.value='save_properties';
	document.forms[0].task.value=task;
	document.forms[0].close.value=close;
	document.forms[0].submit();
}

function confirm_unshare(message)
{	
	if(!document.forms[0].share_folder.checked)
	{
		if(confirm(message))
		{
			document.forms[0].properties_task.value='save_properties';
			document.forms[0].task.value='properties';
			document.forms[0].submit();
		}else
		{
			document.forms[0].share_folder.checked=true;
		}
	}else
	{
		document.forms[0].properties_task.value='save_properties';
		document.forms[0].submit();
	}
}
</script>
