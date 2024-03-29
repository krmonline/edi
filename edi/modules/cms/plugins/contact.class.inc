<?php
class cms_contact {

	var $attributes;
	var $cms_site;
	
	function cms_contact($attributes, &$cms_site)
	{
		$this->cms_site = &$cms_site;
		$this->attributes=$attributes;
	}
	
	function get_name()
	{
		global $GO_LANGUAGE;
		require($GO_LANGUAGE->get_language_file('cms'));
		return $cms_contact_form;
	}
	
	function has_permission()
	{
		return true;
	}
	
	function get_header()
	{
	}
	
	function get_html()
	{		
		global $GO_CONFIG, $GO_SECURITY, $GO_LANGUAGE;
		
		$contact_task = isset($_REQUEST['contact_task']) ? $_REQUEST['contact_task'] : '';
		
		if(!isset($_SESSION['GO_SESSION']['antispamkey']))
		{
			$_SESSION['GO_SESSION']['antispamkey']=uniqid();
		}
		
		if($contact_task == 'contact')
		{		
			$name = smart_stripslashes(trim($_POST['name']));
			$email = smart_stripslashes(trim($_POST['email']));
			$subject = smart_stripslashes(trim($_POST['subject']));  
			
			$subject = str_replace("\r",'',$subject);			
			$subjectArr = explode("\n", $subject);
			
			
			$message = smart_stripslashes(trim($_POST['message']));
			
			if($_POST['antispamkey']!=$_SESSION['GO_SESSION']['antispamkey'])
			{
				die();
			}elseif(stristr($_SERVER['HTTP_REFERER'],$_SERVER['HTTP_HOST'])===false)
			{
				//echo $_SERVER['HTTP_REFERER'].' -> '.$_SERVER['HTTP_HOST'];
				die('Referrer check failed');
			}elseif(count($subjectArr)>1)
			{
				//something posted a multi line subject
				//lets just die
				die();
			}elseif ($name == '' || $email == '' || $subject == '' || $message == '')
			{
				$feedback = $GLOBALS['error_missing_field'];
			}elseif(!validate_email($email))
			{
				$feedback = $GLOBALS['error_email'];
			}else
			{
				$email_to = !empty($this->attributes['email_to'])  ? $this->attributes['email_to'] : $this->cms_site->site['webmaster'];
				if(!sendmail($email_to, $email, $name, $subject, $message))
				{
					$feedback = $cms_sendmail_error;
				}else
				{
					return $GLOBALS['cms_sendmail_success'];									
				}    
			}			
		}			
		
		$form = new form('contact_form');
		$form->add_html_element(new input('hidden','contact_task', 'contact'));		
		$form->add_html_element(new input('hidden','file_id', $this->cms_site->file_id));
		$form->add_html_element(new input('hidden','folder_id', $this->cms_site->folder_id));
		$form->add_html_element(new input('hidden','antispamkey', $_SESSION['GO_SESSION']['antispamkey']));
		
		//require($GO_LANGUAGE->get_base_language_file('contact'));

		$table = new table();
		$table->set_attribute('style','width:100%');
		
		
		
		if (isset($feedback))
		{
			$row = new table_row();
			
			$p = new html_element('p', $feedback);
			$p->set_attribute('style', 'color:red');			
		
			$cell = new table_cell($p->get_html());
			$cell->set_attribute('colspan','2');			
			
			$row->add_cell($cell);
			$table->add_row($row);
		}
		
		
		
		
		$row = new table_row();
		$cell = new table_cell($GLOBALS['strName'].':');
		$cell->set_attribute('style', 'whitespace:nowrap;');
		$row->add_cell($cell);		
		$cell = new table_cell();
		$cell->set_attribute('style','width:100%');
		$name = isset($_REQUEST['name']) ? smart_stripslashes($_REQUEST['name']) : '';
		$input = new input('text', 'name', $name);
		$input->set_attribute('style','width:100%');
		$cell->add_html_element($input);
		$row->add_cell($cell);
		$table->add_row($row);
		
		
		$row = new table_row();
		$cell = new table_cell($GLOBALS['strEmail'].':');
		$cell->set_attribute('style', 'whitespace:nowrap;');
		$row->add_cell($cell);		
		$cell = new table_cell();
		$email = isset($_REQUEST['email']) ? smart_stripslashes($_REQUEST['email']) : '';
		$input = new input('text', 'email', $email);
		$input->set_attribute('style','width:100%');
		$cell->add_html_element($input);
		$row->add_cell($cell);
		$table->add_row($row);
		
		$row = new table_row();
		$cell = new table_cell($GLOBALS['cms_subject'].':');
		$cell->set_attribute('style', 'whitespace:nowrap;');
		$row->add_cell($cell);		
		$cell = new table_cell();
		$subject = isset($_REQUEST['subject']) ? $_REQUEST['subject'] : '';
		$input = new input('text', 'subject', $subject);
		$input->set_attribute('style','width:100%');
		$cell->add_html_element($input);
		$row->add_cell($cell);
		$table->add_row($row);
		
		
		$row = new table_row();
		$cell = new table_cell($GLOBALS['cms_message'].':');
		$cell->set_attribute('style', 'whitespace:nowrap;vertical-align:top;');
		$row->add_cell($cell);		
		$cell = new table_cell();
		$message = isset($_REQUEST['message']) ? smart_stripslashes($_REQUEST['message']) : '';
		$input = new textarea('message', $message);
		
		$height= isset($this->attributes['height']) ? $this->attributes['height'] : 100;
		
		$input->set_attribute('style','width:100%;height:'.$height.'px;');
		$cell->add_html_element($input);
		$row->add_cell($cell);
		$table->add_row($row);
		
		
		$row = new table_row();		
		
		$reset = new input('reset', 'reset', $GLOBALS['cmdReset']);
		
		$submit = new input('submit','submit', $GLOBALS['cms_send_message']);
		$cell = new table_cell($reset->get_html().$submit->get_html());
		$cell->set_attribute('style','text-align:right;');
		$cell->set_attribute('colspan','2');

		$row->add_cell($cell);
		$table->add_row($row);
		$form->add_html_element($table);
		return $form->get_html();

	}
}
