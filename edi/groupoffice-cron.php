<?php
/**
 * Copyright Intermesh 2005
 *  Author: Merijn Schering <mschering@intermesh.nl>
 *  Version: 1.0 Release date: 29 June 2005
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 *
 * Run this script in a cronjob as root every minute.
 */ 
 

require_once('Group-Office.php');

load_basic_controls();

require($GO_CONFIG->class_path.'mail/RFC822.class.inc');
$RFC822 = new RFC822;

$email_module = $GO_MODULES->get_module('email');
$cal_module = $GO_MODULES->get_module('calendar');


require_once($cal_module['class_path'].'calendar.class.inc');
$cal = new calendar();
$cal2 = new calendar();

require_once ($GO_LANGUAGE->get_language_file('calendar'));


$GO_USERS->get_users();	
while($GO_USERS->next_record())
{
	
	if($cal_module)
	{
		$cal_settings=$cal->get_settings($GO_USERS->f('id'));
		if($cal_settings['email_reminders']=='1')
		{		
			if($cal->get_events_to_remind($GO_USERS->f('id'), true,true,true))
			{
				while($cal->next_record())
				{
					$date_format = get_dateformat($GO_USERS->f('date_format'), $GO_USERS->f('date_seperator'));
					$start_time = date($date_format, $cal->f('start_time'));
					$subject = $sc_reminder.': '.$start_time.' '.$cal->f('name');
					
					$link = new hyperlink($GO_CONFIG->full_url.'index.php?return_to='.urlencode($cal_module['url'].'event.php?event_id='.urlencode($cal->f('id'))), $cal_event_mail_open);
					$link->set_attribute('target','_blank');
					$link->set_attribute('class','blue');
					$body = $link->get_html();
					
					sendmail($GO_USERS->f('email'), $GO_CONFIG->webmaster_email, $GO_CONFIG->title, $subject, $body, '3', 'text/HTML');
					
					if($event = $cal2->get_event($cal->f('id')))
					{
						$cal2->reminder_mail_sent($GO_USERS->f('id'), $event['id']);
					}
				}		
			}
		}
	}	
}

