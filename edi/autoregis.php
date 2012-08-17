<?php
/**
 * Copyright Intermesh 2005
 *  Author: Merijn Schering <mschering@intermesh.nl>
 *  Version: 1.1 Release date: 27 June 2005
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 */

$user['id'] = $GO_SECURITY->user_id;
if(isset($_SESSION['GO_SESSION']['username']))
{
	list($username,$dc) = explode("@",$_SESSION['GO_SESSION']['username']);
	$user['first_name'] =  smart_addslashes($username);
}
if(isset($_POST['middle_name']))
{
	$user['middle_name'] = smart_addslashes($_POST["middle_name"]);
}
if(isset($username))
{
	$user['last_name'] = smart_addslashes(substr($username,0,1));
}
if(isset($_POST['initials']))
{
	$user['initials'] = smart_addslashes($_POST["initials"]);
}
if(isset($_POST['title']))
{
	$user['title'] = smart_addslashes($_POST["title"]);
}
if(isset($_POST['birthday']))
{
	$user['birthday'] = date_to_db_date(smart_stripslashes($_POST["birthday"]));
}
if(isset($username))
{
	$user['email'] = smart_addslashes($username."@nikon-edisys.com");
}
if(isset($_POST['home_phone']))
{
	$user['home_phone'] = smart_addslashes($_POST["home_phone"]);
}
if(isset($_POST['work_phone']))
{
	$user['work_phone'] = smart_addslashes($_POST["work_phone"]);
}
if(isset($_POST['fax']))
{
	$user['fax'] = smart_addslashes($_POST["fax"]);
}
if(isset($_POST['cellular']))
{
	$user['cellular'] = smart_addslashes($_POST["cellular"]);
}
if(isset($_POST['country_id']))
{
	$user['country_id'] = "209";
}
if(isset($_POST['state']))
{
	$user['state'] = smart_addslashes("N/A");
}
if(isset($_POST['city']))
{
	$user['city'] = smart_addslashes("N/A");
}
if(isset($_POST['zip']))
{
	$user['zip'] = smart_addslashes("N/A");
}
if(isset($_POST['address']))
{
	$user['address'] = smart_addslashes("N/A");
}
if(isset($_POST['address_no']))
{
	$user['address_no'] = smart_addslashes("N/A");
}
if(isset($_POST['company']))
{
	$user['company'] = "Vender";
}
if(isset($_POST['department']))
{
	$user['department'] = smart_addslashes($_POST["department"]);
}
if(isset($_POST['function']))
{
	$user['function'] =  smart_addslashes($_POST["function"]);
}
if(isset($_POST['work_country_id']))
{
	$user['work_country_id'] = smart_addslashes($_POST["work_country_id"]);
}
if(isset($_POST['work_state']))
{
	$user['work_state'] = smart_addslashes($_POST["work_state"]);
}
if(isset($_POST['work_city']))
{
	$user['work_city'] = smart_addslashes($_POST["work_city"]);
}
if(isset($_POST['work_zip']))
{
	$user['work_zip'] = smart_addslashes($_POST["work_zip"]);
}
if(isset($_POST['work_address']))
{
	$user['work_address'] = smart_addslashes($_POST["work_address"]);
}
if(isset($_POST['work_address_no']))
{
	$user['work_address_no'] = smart_addslashes($_POST["work_address_no"]);
}
if(isset($_POST['work_fax']))
{
	$user['work_fax'] = smart_addslashes($_POST["work_fax"]);
}
if(isset($_POST['homepage']))
{
	$user['homepage'] = smart_addslashes($_POST["homepage"]);
}
if(isset($_POST['sex']))
{
	$user['sex'] = smart_addslashes($_POST["sex"]);
}


$GO_USERS->update_profile($user);
	if(isset($GO_MODULES->modules['email']) && $GO_MODULES->modules['email']['read_permission'])
	{
		require_once($GO_MODULES->modules['email']['class_path'].'email.class.inc');
		$email = new email();

		$email->get_accounts($GO_SECURITY->user_id);
		if($email->next_record())
		{
			$account['id'] = $email->f('id');
			$account['email'] = $user['email'];
			$account['name'] = format_name($user['last_name'], $user['first_name'], $user['middle_name'], 'first_name');
			$email->_update_account($account);
		}
	}
	header('Location: '.$GO_CONFIG->host);
	exit();


