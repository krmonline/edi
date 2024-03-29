<?php
/**
 * @copyright Intermesh 2005
 * @author Merijn Schering <mschering@intermesh.nl>
 * @version $Revision: 1.22 $ $Date: 2006/11/21 16:25:42 $

 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

load_control('datatable');
 
class projects_list extends datatable
{
	var $count;
	
	function projects_list($id, $link_id=0, $return_zero=true, $form_name='0', $return_to='')
	{
		global $GO_CONFIG, $GO_SECURITY, $GO_MODULES, $GO_LANGUAGE, $GO_LINKS;
		
		$this->datatable($id, false, $form_name);
		$this->set_attribute('style','width:100%;margin-bottom:20px;margin-top:0px;');
		
		$return_to = !empty($return_to) ? $return_to : $_SERVER['PHP_SELF'];
		
		
		
		require($GO_LANGUAGE->get_language_file('projects'));
		
		require_once($GO_MODULES->modules['projects']['class_path']."projects.class.inc");
		$projects = new projects();
		
		$this->add_outerhtml_element(new input('hidden', $this->attributes['id'].'[project_id]','',false));

		$show_projects = $GO_CONFIG->get_setting('show_projects', $GO_SECURITY->user_id);
		
		if ($this->task == 'start_timer') {
			$projects->start_timer($GO_SECURITY->user_id, $_POST[$this->attributes['id']]['project_id']);
		}

		if(isset($_POST[$this->attributes['id']]['show_projects']) && $_POST[$this->attributes['id']]['show_projects'] != $show_projects)
		{
			$GO_CONFIG->save_setting(
				'show_projects', 
				smart_addslashes($_POST[$this->attributes['id']]['show_projects']), 
				$GO_SECURITY->user_id);
				
			$show_projects = smart_stripslashes($_POST[$this->attributes['id']]['show_projects']);
		}		 
		
				
		if ($timer = $projects->get_timer($GO_SECURITY->user_id)) {
		
			$img = new image('alert');
			$img->set_attribute('align','middle');
			$img->set_attribute('style','border:0px;margin-right:5px;');			
			
			$link = new hyperlink($GO_MODULES->modules['projects']['url'].
				'book.php?task=stop_timer&project_id='.
				$timer['project_id'], $GLOBALS['pm_clocked_in']);
		
			$div = new html_element('div', 
				$img->get_html().
				$link->get_html()
				);
			$div->set_attribute('class', 'ErrorBox');
			$this->add_outerhtml_element($div);
		}
		

		$table = new table();
		$table->set_attribute('style','width:100%');
		$row = new table_row();
		$row->add_cell(new table_cell($pm_filter.':'));

		$select = new select($this->attributes['id'].'[show_projects]', $show_projects);
		$select->set_attribute('onchange', 'javascript:document.forms[\''.$this->form_name.'\'].submit()');

		$select->add_value('', $GLOBALS['cmdShowAll']);
		$projects->get_statuses();
		while($projects->next_record())
		{
			$select->add_value($projects->f('id'), $projects->f('name'));
		}
		$row->add_cell(new table_cell($select->get_html()));

		if($this->task == 'delete')
		{
			foreach($this->selected as $delete_project_id)
			{
				$delete_project_id =str_replace('5:', '', $delete_project_id);
				$project = $projects->get_project($delete_project_id);
				
				if ($GO_SECURITY->has_permission($GO_SECURITY->user_id, $project['acl_write']))
				{
					$projects->delete_project($delete_project_id);
				}else
				{
					$feedback = $GLOBALS['strAccessDenied'];
				}
			}
		}elseif($this->task=='unlink')
		{
			global $GO_LINKS;
			
			foreach($this->selected as $project_id)
			{
				$project_id =str_replace('5:', '', $project_id);
				if($project = $projects->get_project($project_id))
				{
					$GO_LINKS->delete_link($link_id, $project['link_id']);
				}
			}
		}
		$links = $link_id > 0 ? $GO_LINKS->get_links($link_id, 5) : false;
			
		if (isset($feedback))
		{
			$p = new html_element('p', $feedback);
			$p->set_attribute('class','Error');
			$this->add_outerhtml_element($p);
		}

		$this->add_column(new table_heading($GLOBALS['strName'], 'name'));
		$this->add_column(new table_heading($pm_status, 'status'));
		$this->add_column(new table_heading($pm_start_date,'start_date'));
		$this->add_column(new table_heading($pm_end_date, 'end_date'));
		$this->add_column(new table_heading($pm_probability, 'probability'));

		$th = new table_heading('&nbsp;');
		$th->set_attribute('colspan','3');
		$this->add_column($th);
		$this->count = $projects->get_authorized_projects(
			$GO_SECURITY->user_id, 
			$links, 
			$this->sort_index, 
			$this->sql_sort_order, 
			$this->start, 
			$this->offset, 
			$show_projects);
			
		$this->set_pagination($this->count);

		$cell = new table_cell($this->count.' '.$pm_projects_count);
		$cell->set_attribute('style','text-align:right;width:100%');
		$cell->set_attribute('class','small');

		$row->add_cell($cell);

		$table->add_row($row);

		$this->add_outerhtml_element($table);

		if($this->count > 0)
		{
			$time = get_time();
			$projects2 = new projects();
			while ($projects->next_record()) {			
				$row = new table_row('5:'.$projects->f('id'));
				$row->set_attribute('ondblclick', 
					"javascript:window.location.href='".
					$GO_MODULES->modules['projects']['url'].
					'project.php?project_id='.$projects->f('id').
					'&return_to='.urlencode($return_to)."';");	
					
				$project_name = ($projects->f('description') == '') ? 
					htmlspecialchars($projects->f('name')) : 
					htmlspecialchars($projects->f('name').' ('.$projects->f('description').')');
				$row->add_cell(new table_cell($project_name));
				
				$row->add_cell(new table_cell($projects->f('status_name')));
				$row->add_cell(new table_cell(date($_SESSION['GO_SESSION']['date_format'], $projects->f('start_date'))));
				$row->add_cell(new table_cell(date($_SESSION['GO_SESSION']['date_format'], $projects->f('end_date'))));				
				$row->add_cell(new table_cell($projects->f('probability').'%'));
				
				$cell = new table_cell();
				$cell->set_attribute('style','text-align:right');
				
				$img = new image('enter_data');
				$img->set_attribute('style','border:0px;');
				
				$book_link = new hyperlink($GO_MODULES->modules['projects']['url'].
					'book.php?project_id='.$projects->f("id").'&return_to='.urlencode($return_to),
				 $img->get_html(), $pm_enter_data);
					
				$img = new image('clock');
				$img->set_attribute('style','border:0px;');
					
				$start_timer_link = new hyperlink('javascript:start_timer('.$projects->f('id').');',$img->get_html(), $pm_start_timer);
					
				$img = new image('clockout');
				$img->set_attribute('style','border:0px;');
					
				$stop_timer_link = new hyperlink($GO_MODULES->modules['projects']['url'].
						'book.php?task=stop_timer&project_id='.$projects->f("id").'&return_to='.
						urlencode($return_to), $img->get_html(), $pm_stop_timer);
				
				if (!$timer)
				{	
					$cell->add_html_element($book_link);
					$cell->add_html_element($start_timer_link);
				}elseif ($timer['project_id'] == $projects->f('id')) {
					$cell->add_html_element($stop_timer_link);
				}
								
				$row->add_cell($cell);
				
				$this->add_row($row);

			}
			
		}else
		{
			if($return_zero)
			{
				$row = new table_row();
				$cell = new table_cell($pm_no_projects);
				$cell->set_attribute('colspan','99');
				$this->add_row($row);
			}else
			{
				$this->innerHTML = '';
				return false;
			}
		}
		
		$this->outerHTML .= '
		<script type="text/javascript">
		
		function start_timer(project_id)
		{
			document.forms["'.$this->form_name.'"].elements["'.$this->attributes['id'].'[project_id]"].value=project_id;
			document.forms["'.$this->form_name.'"].elements["'.$this->attributes['id'].'[task]"].value="start_timer";
			document.forms["'.$this->form_name.'"].submit();
		}
		
		
		</script>';
	}
	function get_print_handler() {
     global $GO_SECURITY, $GO_CONFIG;
      $show_projects = $GO_CONFIG->get_setting('show_projects', $GO_SECURITY->user_id);
      return 'javascript:popup(\'print_projects.php?type=pl&uid='.smart_addslashes($GO_SECURITY->user_id).'&sort_index='.
      smart_addslashes($this->sort_index). '&sql_sort_order='.smart_addslashes($this->sql_sort_order).'&start='.
      smart_addslashes($this->start).'&offset='. smart_addslashes($this->offset).'&show_projects='.
      smart_addslashes($show_projects).'\')';
	 }
}
