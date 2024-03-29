<?php
//Uncomment this line in new translations!
require($GO_LANGUAGE->get_fallback_base_language_file('common'));

#$charset = 'UTF-8';
$charset = 'koi8-r';
//$charset = 'KOI-8';
//main language menu file register login and other non logged in pages
//common
$cmdLogin = "����";
$cmdSave = "��������";
$cmdBack = "�����";
$cmdCancel = "������";
$cmdClose = "�������";
$cmdOk = "Ok";
$cmdDelete = "�������";
$cmdNext = "�����";
$cmdPrevious = "�����";
$cmdContinue = "����������";
$cmdUpdate = "�������������";
$cmdApply = "��������";
$cmdYes = "��";
$cmdNo = "���";
$cmdAdd = '��������';
$cmdEdit = '�������������';
$cmdInvertSelection = 'Invert selection';

$strEdit = "�������������";
$strThis = '����';
$strItems = '�������';
$strDescription = '��������';

$strName = "���";
$strUser = "������������";
$strUsername = "��� ������������";
$strPassword = "������";
$strAuthcode = "���������������� ���";
$strCountry = "������";
$strState = "�������/����";
$strCity = "�����";
$strZip = "ZIP/�������� ������";
$strAddress = "�������� �����";
$strEmail = "E-mail";
$strPhone = "�������";
$strWorkphone = "������� �������";
$strCellular = "������� �������";
$strCompany = "�����������";
$strDepartment = "�����";
$strFunction = "���������";
$strQuestion = "��������� ������";
$strAnswer = "�����";
$strFax = "����";
$strWorkFax = "������� ����";
$strHomepage = "�������� ��������";
$strWorkAddress = "�������� ����� (�������)";
$strWorkZip = "ZIP/�������� ������ (�������)";
$strWorkCountry = "������ (������)";
$strWorkState = "�������/���� (�������)";
$strWorkCity = "����� (������)";
$strPhoto = "����";
$strComments = "����������";
$strProperties = '���������';
$strDeleteItem = "��������";
$strDate = "����";
$strSaveSuccess = "������ ������� ���������";
$strSaveError = "��������� �������������� ������ ��� ���������� ������.";
$strDataError = "��������� �������������� ������ ��� ������ ������.";
$strDeleteError = "������ �� �������.";
$strAclError = "������ �������";
$strDateError = "�� ����� ����������� ������";
$strAccessDenied = "������ ��������";
$AccessDenied_text = "You are not allowed to view this section of the site or to perform this action.<br />Another user has restricted access to the information you requested.";
$invalid_chars = "The following characters are not allowed";
$strGroups = "������";
$strOwner = "��������";
$strDeletePrefix = "�� ������������� ������ ������� ";
$strDeleteSuffix = "?";
//menu
$menu_logout = "�����";
$menu_applications = "����������";
$menu_help = "������";
$menu_about = "� ����������";
$menu_documentation = "������������";
$menu_configuration = "������������";
$menu_groups = "���������� ��������";
$menu_accounts = "��������� �������� ����� ������� ������";
$menu_preferences = "������������ ���������";
$menu_search_discussions = "���������";
$menu_search_files = "�����&nbsp;�&nbsp;�����";
$menu_search_web = "WEB";
$menu_filetypes = "��������&nbsp;�������";
$menu_discussions = "���������";

$menu_users = "�������������� �������������";
$menu_new = "�����";
$menu_message = "���������";
$menu_contact = "�������";
$menu_event = "�������";
$menu_bookmark = "Bookmark";
$menu_topics = "Topics";
$menu_support = "���������";
$menu_projects = "�������";
$menu_sysinfo = "�������� ��������� ����������";
$menu_admin = '���������������� ����';
$menu_modules = '��������/������� ������';
$menu_manual = 'Manual';

//class validate
$error_required = "You didn't specify the required field below.";
$error_match_auth = "The authorisation codes didn't match.";
$error_match_pass = "The passwords didn't match.";
$error_min_length = "Minimum characters of the field below:";
$error_max_length = "Maximum characters of the field below:";
$error_email = "The E-mail address you specified was invalid.";
$error_email_exists = "The E-mail address you entered already exists.";
$error_username_exists = "Sorry, the username you entered already exists. Please choose another one.";
$errors_in_form = "There were errors in the form. Correct them and try again.";
$error_missing_field = "You didn't fill in all the required fields.";

//acl control
$acl_control_auth_groups = "�������������� (����������) ������";
$acl_control_auth_users = "�������������� (����������) ������������";
$acl_control_no_contacts = "You don't have any member contacts to select.<br /> Use the Addressbook to add members to your contacts.";

$strShowProfile = "�������� �������";
$strShowGroup = "�������� ���������� ������";
$strProcessingTime = "The processing of this page took ";
$strLoggedInAs = "���� �������� ��� ";
$strAt = " at ";
$strEmailTo = "������� E-mail ���������: ";
$strProtectedUser = "���������� ������������";

$http_not_found = "�������� �� ������";
$http_not_found_text = "������������� �������� �� ������. ����� ���� ����������� ������ URL.";
$http_error = "������ �������";
$http_bad_request = "������������ ������";
$strAddContact = "�������� � ��������";

$strReadRights = "���������� �� ������";
$strWriteRights = "���������� �� ������";
$strPermissions = '����������';

$days[0]="��";
$days[1]="��";
$days[2]="��";
$days[3]="��";
$days[4]="��";
$days[5]="��";
$days[6]="��";

$months[0]="������";
$months[1]="�������";
$months[2]="����";
$months[3]="������";
$months[4]="���";
$months[5]="����";
$months[6]="����";
$months[7]="������";
$months[8]="��������";
$months[9]="�������";
$months[10]="������";
$months[11]="�������";

$full_days[0] = "�����������";
$full_days[1] = "�����������";
$full_days[2] = "�������";
$full_days[3] = "�����";
$full_days[4] = "�������";
$full_days[5]= "�������";
$full_days[6] = "�������";
$strLoadTime = '�������� ';
$strDescription = '��������';



$lang_modules['addressbook'] = "�������� �����";
$cmdShowAll = '�������� ���';
$cmdSearch = '�����';

//translation required
$cmdYesToAll = '�� ��� ����';
$cmdNoToAll = '��� ��� ����';

$short_months[0]="���";
$short_months[1]="���";
$short_months[2]="���";
$short_months[3]="���";
$short_months[4]="���";
$short_months[5]="���";
$short_months[6]="���";
$short_months[7]="���";
$short_months[8]="���";
$short_months[9]="���";
$short_months[10]="���";
$short_months[11]="���";

$strToday = '�������';

$cmdPrint = '������';
$strFirstName = '���';
$strLastName = '�������';
$strInitials = '��������';
$strSex = '���';
$strBirthday = '���� ��������';
$strSexes['M'] = '���';
$strSexes['F'] = '���';

$strTitle = '���������';
$strBeginning = 'Beginning';
$strMiddleName = '��������';
$sir_madam['M'] = '���������';
$sir_madam['F'] = '���������';
$strModifiedAt = '�������';
$strCreatedAt = '������';

$htmlarea_language_name = 'ru';
$strLocalization = 'Localization';


//look up the language in controls/jscalendar/lang
$jscalendar_language_name = 'calendar-en.js';


//2.01 translations

//look up language in 'classes/phpmailer/language'
$php_mailer_lang = 'ru';
$strEmailFail = '������ ��� �������� e-mail ���������.';

//for people that want to use ktmlarea
$ktml_language = 'russian';

$ml_host_unreachable = ' is unreachable. Automatic checking of e-mail is disabled.';
$strRegion = '������';

//2.05
$cmdReset = '�����';
$strMyName = '��� ���';

//2.06
$strDeleteRow = 'Are you sure you want to delete this row?';
$strAddressNo = 'number of house';
$strWorkAddressNo = 'Work number of house';

$strPostAddress = '�������� �����';
$strPostAddressNo = 'Post number of house';
$strPostCity = '�����';
$strPostState = '�������/����';
$strPostCountry = '������';
$strPostZip = '�������� ������';
$strVisitAddress = '���������� �����';
$strPostAddress = '�������� �����';


//modules
$lang_modules['scheduler'] = '�����������';
$lang_modules['calendar'] = "���������";
$lang_modules['filesystem'] = '�����';
$lang_modules['email'] = 'E-mail';
$lang_modules['projects'] = '�������';
$lang_modules['search'] = '�����';
$lang_modules['contacts'] = "������";
$lang_modules['cms'] = "Web �����";
$lang_modules['notes'] = "�������";
$lang_modules['bookmarks'] = "��������";
$lang_modules['summary'] = "������";
$lang_modules['todos'] = "������";
$lang_modules['opentts'] = "������";

$cmdVcard = 'vCard';


//2.07
$strNotEnoughLicenses = 'You don\'t have enough licenses to use this section of'.
												' Group-Office. Contact sales@intermesh.nl if you want '.
												'to purchase additional licenses.';
												
//2.08
$alphabet = array('�','�','�','�','�','�','�','�','�','�','�','�','�','�','�',
									'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�');
									
$strContact = '�������';
$strRelatedTo = 'Related to';
$strProject = '������';

$strNewProject = '����� ������';
$strNewEvent = '����� �������';
$strNewTodo = '����� ToDo (�������)';
$strNewNote = '����� �������';

$strActivities = 'Activities';
$strFile = '����';

//2.10
$cmdCopy = '�����';
$strProjects = '�������';
$strFiles = '�����';
$cmdSaveNew = '���������� & �����';
$strAvailability = '���������';
$strCheckAvailabilityFor = '�������� ���������� ���';
$cmdPleaseSelect = '���������� ��������...';

//2.11
$strNewEmail = '����� ��������� (e-mail)';
$strConsistencyCheck = "Consistency Check";
$strSearchAll = '��� ����';
$sync_download_clients = '��������� �������� �������������';

//2.12
$strNoData = '������ �� �������';
//2.13
$strSynchronization = '�������������';
$strSnooze = 'Snooze';
$strDismiss = 'Dismiss';
