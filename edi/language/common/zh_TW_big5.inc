<?php
require_once($GO_LANGUAGE->get_fallback_base_language_file('common'));

$charset = 'BIG5';

$lang_modules['scheduler'] = "��ƾ�";
$lang_modules['calendar'] = "��ƾ�";
$lang_modules['filesystem'] = '�ɮ�';
$lang_modules['email'] = '�q�l�l��';
$lang_modules['projects'] = '�M��';
$lang_modules['search'] = "�j�M����";
$lang_modules['contacts'] = "�s���H";
$lang_modules['cms'] = "����";
$lang_modules['addressbook'] = "�q�T��";

//main language menu file register login and other non logged in pages
//common
$cmdLogin = "�n�J";
$cmdSave = "�x�s";
$cmdBack = "�W�@�B";
$cmdCancel = "����";
$cmdClose = "����";
$cmdOk = "�T�w";
$cmdDelete = "����";
$cmdNext = "�U�@��";
$cmdPrevious = "�W�@��";
$cmdContinue = "�~��";
$cmdUpdate = "�P�B";
$cmdApply = "�M��";
$cmdYes = "�O";
$cmdNo = "�_";
$cmdAdd = '�s�W';
$cmdEdit = '�ק�';
$cmdInvertSelection = '�ϦV���';

$strEdit = "�ק�";
$strThis = '�o';
$strItems = '����';
$strDescription = "���e";

$strName = "�W��";
$strUser = "�ϥΪ�";
$strUsername = "�ϥΪ̦W��";
$strPassword = "�K�X";
$strAuthcode = "���v�K�X";
$strCountry = "��a";
$strState = "�{�p";
$strCity = "����";
$strZip = "�l���ϸ�";
$strAddress = "��D�a�}";
$strEmail = "�q�l�l��";
$strPhone = "�q��";
$strWorkphone = "�u�@�q��";
$strCellular = "�y�ʹq��";
$strCompany = "���q";
$strDepartment = "����";
$strFunction = "¾��";
$strQuestion = "���K���D";
$strAnswer = "����";
$strFax = "�ǯu";
$strWorkFax = "�u�@�ǯu";
$strHomepage = "����";
$strWorkAddress = "�u�@�a�}";
$strWorkZip = "�u�@�l���ϸ�";
$strWorkCountry = "�u�@��a";
$strWorkState = "�u�@�{�p";
$strWorkCity = "�u�@����";
$strPhoto = "�ۤ�";
$strComments = "�Ƶ�";

$strProperties = '���e';

$strDeleteItem = "����";

$strDate = "���";

$strSaveSuccess = "��Ƥw���\�x�s";
$strSaveError = "����x�s���~�A�Э���";
$strDataError = "���Ū�����~�A�Э��s���J�o��";
$strDeleteError = "��Ƥ��ಾ��";
$strAclError = "�s��������~";
$strDateError = "�A/�p�ҿ�J��������~";


$strAccessDenied = "�ڵ��s��";
$AccessDenied_text = "�A/�p�S���Q���v�[�ݳo�����ΰ���o�Ӱʧ@<br />�t�~���ϥΪ̤w����A/�p�s���o�Ǹ��";

$invalid_chars = "���e�\�H�U���r��";

$strGroups = "�s��";
$strOwner = "�֦���";

$strDeletePrefix = "�A/�p�O�_�T�w����";
$strDeleteSuffix = "?";

//menu
$menu_logout = "�n�X";
$menu_applications = "�{����";
$menu_help = "���U";
$menu_about = "����";
$menu_documentation = "���";
$menu_configuration = "�]�w";
$menu_groups = "�ϥΪ̸s��";
$menu_accounts = "�A/�p���b��";
$menu_preferences = "�ߦn�]�w";
$menu_bookmarks = "����";
$menu_bookmarks_manage = "�ק����";
$menu_add_bookmark = "�s�W����";
$menu_add_current = "�s�W&nbsp;���e&nbsp;�o��";

$menu_invite = "�ܽ�&nbsp;�ϥΪ�";

$menu_search_discussions = "�Q��";
$menu_search_files = "�ɮ�&nbsp;�M&nbsp;��Ƨ�";
$menu_search_web = "�o�Ӻ���";
$menu_scheduler = "��ƾ�";
$menu_filetypes = "�ɮ�����";
$menu_discussions = "�Q�תO";

$menu_users = "�ϥΪ�";
$menu_start = "����";
$menu_reboot = "���s�Ұʦ��A��";
$menu_halt = "�������A��";
$menu_reboot_text = "ĵ�i�I�Ҧ�Group-Office�A�ȱN�|�Ȯɰ���C�A/�p�O�_�T�w�n�~��H";
$menu_halt_text = "ĵ�i�I�Ҧ�Group-Office�A�ȱN�|����C�A/�p�O�_�T�w�n�~��H";
$menu_new = "�s�W";
$menu_message = "�T��";
$menu_contact = "�p���H";
$menu_event = "�ƥ�";
$menu_bookmark = "����";
$menu_topics = "�D�D";
$menu_support = "�䴩";
$menu_projects = "�M��";
$menu_sysinfo = "�t�θ�T";
$menu_admin = '�t�κ޲z��';
$menu_modules = '�Ҳ�';
$menu_manual = '�ϥΤ�U';

//class validate
$error_required = "�A/�p�S�����w�H�U���������";
$error_match_auth = "���v�K�X����";
$error_match_pass = "�K�X����";
$error_min_length = "�H�U��쪺�̤p�r�`";
$error_max_length = "�H�U��쪺�̤j�r�`";
$error_email = "�A/�p�ҫ��w���q�l�a�}�L��";
$error_email_exists = "�A/�p�ҿ�J���q�l�a�}�w�s�b";
$error_username_exists = "�藍�_�A�A/�p�ҿ�J���ϥΪ̦W�٤w�s�b�A�ШϥΨ�L�W�١C";
$errors_in_form = "���榳���~�A�Ч勵�᭫�աC";
$error_missing_field = "�A/�p�S����g�Ҧ����������";

//acl control
$acl_control_auth_groups = "�w���v���s��";
$acl_control_auth_users = "�w���v���ϥΪ�";
$acl_control_no_contacts = "�A/�p�S���p���H�����i�ѿ��<br />�ϥγq�T���s�W������A/�p���p���H";

$strShowProfile = "�˵��]�w��";
$strShowGroup = "�˵��s�զ���";
$strProcessingTime = "�B�z�o���һݮɶ�";
$strLoggedInAs = "�w�n�J��: ";
$strAt = " �b ";
$strEmailTo = "�ǰe�q�l�T����G";
$strProtectedUser = "�w���O�@���ϥΪ�";

$http_not_found = "�䤣����";
$http_not_found_text = "�䤣��n�D�����ο�J�����}���~";
$http_error = "�������A�����~";
$http_bad_request = "���~���n�D";
$strAddContact = "�s�W���p���H";

$strReadRights = "Ū���v��";
$strWriteRights = "�g�J�v��";
$strPermissions = '�v��';

$editor_bold = "����";
$editor_italic = "����";
$editor_underline = "���u";
$editor_left = "�a��";
$editor_right = "�a�k";
$editor_center = "�m��";
$editor_ord_list = "���ǲŸ�";
$editor_bul_list = "���زŸ�";
$editor_txt_color = "��r��m";
$editor_back_color = "�I����m";
$editor_hyperlink = "�W�s��";
$editor_image = "�v��";
$editor_rule = "�����u";

$editor_very_small = "�D�`�p";
$editor_small = "�p";
$editor_medium = "����";
$editor_large = "�j";
$editor_larger = "���j";
$editor_very_large = "�D�`�j";

$editor_strikethrough = "�e��";
$editor_outdent = "���";
$editor_indent = "�Y��";

$editor_superscript = "�W�ū��O��";
$editor_subscript = "�l���O��";
$editor_undo = "�_��";
$editor_redo = "����";
$editor_copy = "�ƻs";
$editor_paste = "�K�W";
$editor_cut = "�ŤU";

$editor_font = "�r��";
$editor_size = "�j�p";
$editor_heading = "���D";
$editor_select = "���";

$editor_mode = "�ର�s�边�Ҧ�";

$days[0]="��";
$days[1]="�@";
$days[2]="�G";
$days[3]="�T";
$days[4]="�|";
$days[5]="��";
$days[6]="��";

$months[0]="�@��";
$months[1]="�G��";
$months[2]="�T��";
$months[3]="�|��";
$months[4]="����";
$months[5]="����";
$months[6]="�C��";
$months[7]="�K��";
$months[8]="�E��";
$months[9]="�Q��";
$months[10]="�Q�@��";
$months[11]="�Q�G��";

$full_days[0] = "�P����";
$full_days[1] = "�P���@";
$full_days[2] = "�P���G";
$full_days[3] = "�P���T";
$full_days[4] = "�P���|";
$full_days[5]= "�P����";
$full_days[6] = "�P����";
$strLoadTime = "���ͩ�";
$strDescription = "���e";
$strTitle = "���D";


//translation required
$editorCmd['undo'] = "�_��";
$editorCmd['redo'] = "����";
$editorCmd['bold'] = "����";
$editorCmd['italic'] = "����";
$editorCmd['underline'] = "���u";
$editorCmd['left'] = "�����";
$editorCmd['right'] = "����k";
$editorCmd['full'] = "��";
$editorCmd['center'] = "�����";
$editorCmd['ord_list'] = "�s���Ÿ�";
$editorCmd['bul_list'] = "���زŸ�";
$editorCmd['txt_color'] = "��r�C��";
$editorCmd['back_color'] = "�I���C��";
$editorCmd['hyperlink'] = "�W�s��";
$editorCmd['image'] = "���J�Ϲ�";
$editorCmd['rule'] = "�����u";
$editorCmd['table'] = "���J����";

$editorCmd['strikethrough'] = "�R���u";
$editorCmd['outdent'] = "����Y��";
$editorCmd['indent'] = "�W�[�Y��";

$editorCmd['superscript'] = "�W��";
$editorCmd['subscript'] = "�U��";
$editorCmd['undo'] = "�_��";
$editorCmd['redo'] = "����";
$editorCmd['copy'] = "�ƻs";
$editorCmd['paste'] = "�K�W";
$editorCmd['cut'] = "�ŤU";

$editorCmd['font'] = "�r��";
$editorCmd['size'] = "�j�p";
$editorCmd['heading'] = "���D";
$editorCmd['select'] = "���";
$editorCmd['mode'] = "�ഫ�Ҧ�";
$editorCmd['textindicator'] = "���e����";



$cmdShowAll = '��ܩҦ�';
$cmdSearch = '�j�M';

//translation required
$cmdYesToAll = '�O�Ҧ�';

$cmdNoToAll = '���O�Ҧ�';
$short_months[0]="�@��";
$short_months[1]="�G��";
$short_months[2]="�T��";
$short_months[3]="�|��";
$short_months[4]="����";
$short_months[5]="����";
$short_months[6]="�C��";
$short_months[7]="�K��";
$short_months[8]="�E��";
$short_months[9]="�Q��";
$short_months[10]="�Q�@��";
$short_months[11]="�Q�G��";

$strToday = '����';

$strShortWeek = '�g';

$cal_prev_year = "�W�~ (hold for menu)";
$cal_prev_month  = "�W�� (hold for menu)";
$cal_go_today = "�줵��";
$cal_next_month = "�U�� (hold for menu)";
$cal_next_year  = "�U�~ (hold for menu)";
$cal_drag_to_move = "�즲";
$cal_part_today = " (����)";
$cal_monday_first = "��ܬP���@���Ĥ@��";
$cal_sunday_first  = "��ܬP���鬰�Ĥ@��";
$cal_select_date = "��ܤ��";

$cmdPrint = '�C�L';
$strFirstName = '�W�r';
$strLastName = '�m��';
$strInitials = '�m�W²��';
$strSex = '�ʧO';
$strBirthday = '�X�ͤ��';
$strSexes['M'] = '�k';
$strSexes['F'] = '�k';

$strTitle = '�ٿ�';

$strBeginning = '�}�l';

$strMiddleName = "����&nbsp;�W�r";

$sir_madam['M'] = '����';
$sir_madam['F'] = '�k�h';

$strModifiedAt = '�ק��';
$strCreatedTAt = '�إߩ�';

$htmlarea_language_name = "big5";

$strLocalization = "���a��";

$lang_modules['notes'] = "�Ƨѿ�";
//look up the language in controls/jscalendar/lang
$jscalendar_language_name = "calendar-zh.js";
$lang_modules['bookmarks'] = "����";

//look up language in 'classes/phpmailer/language'
$php_mailer_lang = 'en';
$strEmailFail = 'Failed sending the e-mail.';