<?php
/*
$auth_sources[] =
        array(
        'type' => 'sql',
        'name' => 'Group-Office database',
        'user_manager' => 'sql'
        );
*/

$auth_sources[] =
        array(
        'type' => 'email',
        'name' => 'nikon-edisys.com',
        'user_manager' => 'sql',
        'proto' => 'imap',
        'domain' => 'nikon-edisys.com',
        'host' => 'localhost',
        'port' => '143',
        'ssl' => false,
        'novalidate_cert' => true,
        'mbroot' => 'INBOX',
        'add_domain_to_username' => false,
        'create_email_account' => true,
        'auto_check_email' => true,
        'groups' => array('nikon-edisys'),
        'visible_groups' => array('Everyone'),
        'modules_read' => array('email'),
        'modules_write' => array()
        );

?>
