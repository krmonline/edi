<?php
/**
 * @copyright Intermesh 2007
 * @author Merijn Schering <mschering@intermesh.nl>
 * @version $Revision: 1.91 $ $Date: 2006/12/05 11:37:30 $
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

require('../../Group-Office.php');

load_basic_controls();
load_control('datatable');

$GO_SECURITY->authenticate();
$GO_MODULES->authenticate('logviewer');

require_once($GO_LANGUAGE->get_language_file('logviewer'));

if(isset($_POST['task']) && $_POST['task']=='delete')
{
	
	$time = date_to_unixtime(smart_stripslashes($_POST['date']));
	
	$GO_LOGGER->delete($time);
}


$link_id=isset($_REQUEST['link_id']) ? smart_addslashes($_REQUEST['link_id']) : '';

$form = new form('logform');
$form->add_html_element(new input('hidden','task', '', false));

$h1 = new html_element('h1', $lang_modules['logviewer']);
$form->add_html_element($h1);

$menu = new button_menu();
$menu->add_button('print', $cmdPrint, 'javascript:window.print();');

$form->add_html_element($menu);

if(!$GO_LOGGER->enabled)
{
	$form->add_html_element(new html_element('p', $lv_disabled));
}else
{
	if($link_id==0)
	{
		load_control('date_picker');
		$GO_HEADER['head'] = date_picker::get_header();
		
	
		$subtable= new table();
		$subtable->set_attribute('cellpadding','0');
		$subtable->set_attribute('cellspacing','0');
		$subrow= new table_row();
		$subrow->add_cell(new table_cell($lv_delete.':'));
		$datepicker = new date_picker('date', $_SESSION['GO_SESSION']['date_format'], date($_SESSION['GO_SESSION']['date_format'],date_add(get_gmt_time(),0,-1)));
		$subrow->add_cell(new table_cell($datepicker->get_html()));
		
		$button = new button($cmdDelete, "javascript:document.forms[0].task.value='delete';document.forms[0].submit();");
		$button->set_attribute('style','margin-left:5px;margin-top:0px;width:100px');
		$subrow->add_cell(new table_cell($button->get_html()));
	
		$subtable->add_row($subrow);
		
		$form->add_html_element($subtable);
	}else
	{
		$form->add_html_element(new input('hidden','link_id', $link_id));
	}

	$datatable = new datatable('logviewer');
	$th = new table_heading($strDate, 'time');
	$datatable->add_column($th);
	$th = new table_heading($strUser, 'user_id');
	$datatable->add_column($th);
	$th = new table_heading('Module', 'module');
	$datatable->add_column($th);
	$th = new table_heading('Text', 'text');
	$datatable->add_column($th);


	$count = $GO_LOGGER->get_log('',$link_id,'',$datatable->start, $datatable->offset, $datatable->sort_index, $datatable->sql_sort_order);

	$datatable->set_pagination($count);
	
	if($count){
		while($GO_LOGGER->next_record()){
			$row = new table_row();

			$cell = new table_cell(get_timestamp($GO_LOGGER->f('time')));
			$row->add_cell($cell);

			$cell = new table_cell(show_profile($GO_LOGGER->f('user_id')));
			$row->add_cell($cell);

			$cell = new table_cell($GO_LOGGER->f('module'));
			$row->add_cell($cell);

			$cell = new table_cell($GO_LOGGER->f('text'));
			$row->add_cell($cell);

			$datatable->add_row($row);
		}
	}else {
		$row = new table_row();
		$cell = new table_cell($strNoItems);
		$cell->set_attribute('colspan','99');
		$row->add_cell($cell);
		$datatable->add_row($row);
	}

	
	$form->add_html_element($datatable);

	$GO_HEADER['head'] = $datatable->get_header();

}
require($GO_THEME->theme_path.'header.inc');
echo $form->get_html();
require($GO_THEME->theme_path.'footer.inc');
