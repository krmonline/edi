<?php
//Uncomment this line in new translations!
require($GO_LANGUAGE->get_fallback_language_file('addressbook'));

//contacts
$contacts_title = "�������� �����";
$contacts_no_contacts = "�������� �� �������.";
$contacts_members = "������������";
$contacts_contacts = "��������";
$contacts_add = "����� �������";
$contacts_groups = "������";
$contacts_other = "������ ��������";
$contacts_move_to_group = "����������� ��������� �������� � ������...";
//$groups_no_groups = "You don't have any groups";
$groups_no_groups = "�� �� ������ �� ����� ������";
$contacts_group = "������";
$contacts_empty_group = "����������� ���������� ���� ��� ����������� ��������� ��������� � ������ ������.";
$contacts_this_group = '��� ������';

$add_contacts_text = "Fill in the members E-mail adress and authorization code and click on 'Ok'";
$add_contacts_success = "������������ ������� ��������";
$add_contacts_wrong = "Wrong E-mail or authorization code.";
$add_personal_text = "������� '���������' ��� ���������� ��������. ���� ���������� * ����������� ��� ����������.";
$contacts_select = "�������� �������� ��� ���������� � ������� 'Ok'.";
$contacts_select_title = "��������";
$contact_profile = "�������";
$user_profile = "������� ������������";
$contacts_authorise = "�����������";
$contacts_add_member = "�������� ����� ������������ � ���� ��������";
$strConfirmSynchronise = "This will update this contact with data the user has entered himself. Manual changes by you will be lost. Are you sure you want to continue?";
$contacts_import = "������";
$contacts_export = "�������";
$contacts_export_text = "Select the type of CSV you would like to create.";
$contacts_delete = "�������";

$contacts_import_text_group = "Select a group and the CSV file. Click on 'Ok'.";
$fbNoFile = "No file was not recieved";
$fbPleaseWait = "���������� �����. ���� �����������...";

$strNotIncluded = "Do not import";
$contacts_import_feedback = "The following columns where found in your CSV file.<br />";
$contacts_import_feedback .= "Select the group you wish to import to or automatically create groups based on a column of the file.<br />";
$contacts_import_feedback .= " Match corrosponding Group-Office columns with the columns from the file and make sure that you don't select columns twice.";
$contacts_separator = "Values are seperated by";
$contacts_no_separator = "You didn't enter a separator character.";
$fbFilename = "��� �����";
$contacts_import_title = "������ �������� �����";
$contacts_import_success = "������ ������� ��������������";
$contacts_import_double = "�� ������� ���� ��� ������ ������� ������e. �������� ��� � ���������.";
//changed:
$contacts_import_noname = 'You must select the fields \'First_name\' and \'Last name\' ';
$contacts_import_incompatible = "������������� ������ �����.<br /><br />CSV ���� �������� �������� ����������� �������.";
$strMember = "��������";
$contact_exist_warning = "<b>���������:</b> ���� ������������ ��� ��������� � ���������� �����.";
$contacts_add_to_group = "�������� ��������� ������������� � ������...";
$contacts_add_to = "�������� ��������� ������������� � �������";
$contacts_add_user = "��������";
$contacts_edit = "�������������";
$contacts_no_select = "�� ������ �� �������";
$contacts_this_contact = "���� �������";

$contacts_seperator_text = '�������� ��������� ��������';
$contacts_quote = '�������� ��������� � �������';
$contacts_clrf = '������ �������������';
$contacts_auto_group = 'Automatically create groups from file';
$contacts_import_to_group = '������ � ������';

$contacts_search = '�����';
$cmdSearch = '�����';
$contacts_search_text = "Click on a letter or enter a search phrase and click on 'search'. You can use * as a wild character.";
$contacts_results = '���������';
$contacts_result = '���������';


$contacts_color = '����';

$contacts_colors['black'] = '������';
$contacts_colors['red'] = '�������';
$contacts_colors['green'] = '�������';
$contacts_colors['blue'] = '�����';
$contacts_colors['pink'] = '�������';
$contacts_colors['orange'] = '���������';
$contacts_colors['brown'] = '����������';

$ab_addressbooks = '�������� �����';
$ab_owner = '��������';
$ab_subscribed = '������������';
$ab_new_ab = '��� �������� �����';
$ab_addressbook_exists = '�������� ����� � ����� ������ ��� ����������';
$ab_addressbook = '�������� �����';
$contacts_select_single = '�������� �� ������� ��� ������ �������';

$ab_group_exists = 'There already is an addressbook with this name';
$ab_group_on_file = 'Group contacts based on file';
$ab_default = '�������� (default)';

//translation required
$ab_edit_contact = '������� �� \'Ok\' ��� ���������� ���������. ���� ������������ ��� * ����������� ��� ����������';
$ab_group_on_file = 'Group contacts based on the file';
$ab_default = '��������';
$ab_browse = '��������';
$ab_comment = '�����������';

$ab_contact = '�������';
$ab_send_message = 'E-mail';
$ab_new_event = '�������';

$ab_templates = '�������';
$ab_your_templates = '��';
$ab_all_templates = '���';

$template_type[0] = 'E-mail';
$template_type[1] = 'OpenOffice.Org';
$ab_type = '���';
$ab_template_exists = '������ � ����� ������ ��� ����������.';

$sir_madam['M'] = '���������';
$sir_madam['F'] = '���������';

$ab_upload_oo = '�������� OpenOffice.org �������';
$ab_upload_nofile = '������ ��� �������� �����.';

$ab_oo_doc = '��������� ��������';
$ab_select_template = 'Select the template for this document:';
$ab_add_field_data = 'You can use the following values in your document:';
$ab_datafield = 'Datafield';

$ab_no_template = '��� �������';
$ab_new_note = 'Note';

$ab_events = '���������� (���������)';

$ab_new_contact = '�����&nbsp;�������';
$ab_new_company = '�����&nbsp;�����������';
$ab_companies = '�����������';
$ab_company_properties = '�������&nbsp;�����������';
$ab_bank_no = '����������&nbsp;����';
$ab_companies_count_single = '�����������';
$ab_companies_count = '�����������';
$ab_no_companies = '����������� �� �������';
$ab_no_company = '��� �����������';

$ab_import_type = '������';
$ab_no_company_found = '����������� �� �������';
$ab_search_company = '�������� �����������';
$ab_edit_company = '�������� ������� �����������';
$ab_new_group = '����� ������';
$ab_export_type = '�������';

$ab_custom_fields = 'Extra&nbsp;datafields';
$ab_field_size = '������';

$ab_new_field = 'New datafield';
$ab_invalid_field_size = '������������ �������. �������� �������� ����� 10 � 255.';
$ab_field_exists = '���� � ����� ������ ��� ����������.';

$ab_employees = '��������';
$ab_no_employees = '�������� �� �������';

$ab_employee_count_single = '��������';
$ab_employee_count_multiple = '��������';
$ab_vat_no = 'VAT number';

$ab_add_new = '�������� ������';
$ab_add_existing = '������� �������������';

$ab_access = '������';
//1.98
$ab_mailings = '�����������';
$ab_mailing_groups = '������ �����������';
$ab_no_mailing_groups = '�� ������� ������ �����������';
$ab_no_templates = '������ �� ������';
$ab_mailing_group_exists = '������ ����������� � ����� ������ ��� ����������.';
$ab_contacts_count_single = '�������';
$ab_contacts_count_multiple = '��������';
$ab_new_mailing = '����� �����������';
$ab_all_your_addressbooks = '��� ���� �������� �����';

$ab_search_for = '����� ���';
$ab_search_in = '�';
$ab_search_on = '��';
$ab_search_keyword = '����� ��� ������';
$ab_wildcard = '(����������� \'%\' ��� ��������� ������)';

//2.03
$ab_copy_read_acl = '���������� ����� �� ������ �� �������� � �����������';
$ab_copy_write_acl = '���������� ����� �� ������ �� �������� � �����������';

$ab_catagory_exists = '��������� � ����� ������ ��� ����������.';
$ab_add_catagory = '�������� ���������';
$ab_add_field = '�������� ����';
$ab_catagory = '���������';

//2.04
$ab_todos = '������';


//2.05
$ab_download = '�������';
$ab_download_template = 'Click at the \'Download\' button to download the template to your PC for editing.';
$ab_upload = 'Upload';
//modified string:
$ab_upload_oo_text = 'When you finnished with editting your OpenOffice.org template you should transfer it back to Group-Office. Select the file and click at \'Upload\' to transfer your template.';
$ab_file_type = '��� �����';
$ab_import_vcf_file_ok = '������ �� ����� ������� ��������. ���������� ������� \'Ok\' ��� �������� (�����������) �������� ����� .';
$ab_import_failed = '������ ���������� ��������.';
//modified string:
$contacts_import_text = "�������� ����, ���������� ������ ��� ������� � ������� 'Ok'";

//2.06
$ab_select_mailing_groups = 'Select the mailing groups where this contact belongs to';

//2.11
$ab_move_to_ab = '����������� ��������� ��������� � �������� �����...';
$ab_move_com_to_ab = '����������� ��������� �������� � �������� �����...';

//2.12
$ab_search_sender = '����� e-mail';

$ab_contact_exists = '����� ������� ��� ����������. Click %s to go to the existing contact or click \'Ok\' or \'Apply\' again to save this contact anyway.';
$ab_company_exists = '����� �������� ��� ����������. Click %s to go to the existing company or click \'Ok\' or \'Apply\' again to save this company anyway.';
$ab_here = '�����';

//2.13
$ab_search_for_keyword = '���';

$ab_search_in = '����� �'; //changed
$ab_search_on_users = '����� ��';
