<?php
//Uncomment this line in new translations!
require($GO_LANGUAGE->get_fallback_language_file('calendar'));

$sc_title = "���������";
$sc_description = "��������";
$sc_participants = "������������";

$sc_location = "������������";

$month_times[0] = "������ ������";
$month_times[1] = "������ ������";
$month_times[2] = "������ ������";
$month_times[3] = "��������� ������";

$sc_new_app = "����� �������";
$sc_calendars = "���������";
$sc_invited = 'You are invited to join the event described below.';

$sc_types1[0] = '�� ����������';
$sc_types1[1] = '����';
$sc_types1[2] = '������';
$sc_types1[3] = '�� �������� ����';
$sc_types1[4] = '���� ������';
$sc_types1[5] = '���';


$sc_types[0] = 'Once';
$sc_types[1] = '������';
$sc_types[2] = 'Weekly';
$sc_types[3] = 'Monthly by date';
$sc_types[4] = 'Monthly by day';
$sc_types[5] = '����';


$sc_start_at = '������ �';
$sc_end_at = '��������� �';
$sc_start_time = '����� ������';
$sc_end_time = '����� �����';

$sc_at_days = '���� ������';
$sc_of_month = 'of the month.';

$sc_cycle_start = 'Cycle starts at';
$sc_cycle_end = '�������� ����';
$sc_accept_question = 'Do you wish to accept and schedule this event?';

$sc_accept = 'accept';
$sc_decline = 'decline';

$sc_notime = '����� �� ��������';
$sc_noend = '��� ���� ���������.';

$sc_never_happens = 'Bad input! This event never happens.';
$sc_start_later = 'Bad input!! The starting time is later then the ending time.';

$sc_add_self = '������ ����';

$sc_select_calendar = 'Select the calendar to schedule this event in';
$sc_accept_confirm = 'The event is accepted and scheduled.';
$sc_no_calendars = 'No valid calendar found to schedule this event in.';
$sc_bad_event = 'No valid event found. The event is probably deleted.';
$sc_accept_title = 'Accept Event';

$sc_decline_confirm = 'The event is declined.';
$sc_decline_title = 'Decline event';

$sc_status = '������';
$sc_not_responded = 'Not responded';
$sc_accepted = 'Accepted';
$sc_declined = 'Declined';
$sc_no_participants = 'No participants';

$sc_person = '�������';
$sc_owner = '���������';
$sc_type = '���';
$sc_subscribed = '����������';

$sc_subscribe = '��������';
$sc_new_calendar = '����� ���������';
$sc_no_calendar = '��������� �� ������. ���������� �������� ���� �� ���� ���������.';
$sc_day_view = '����&nbsp;����';
$sc_week_view = '����&nbsp;������';
$sc_list_view = '���������&nbsp;��������';
$sc_put_in = 'Put event in';
$sc_inherit_permissions ='Inherit permissions from';
$sc_no_inherit = 'Don\'t inherit';

$sc_select_calendar_please = '���������� �������� ���� ���������.';
$sc_events = '�������';

$sc_from_calendar = '�� ���������';
$sc_enitrely = 'Entirely';
$sc_delete_event = '�������� �������';
$sc_delete_pre = '�� ������������� ������ ������� ��� �������';
$sc_delete_suf = 'entirely or just from this calendar?';

$sc_refresh = '��������';
$sc_reminder = '���������';
$sc_mins = '������';
$sc_hour = '���';
$sc_hours = '����';
$sc_day = '����';
$sc_days = '���';
$sc_week = '������';
$sc_weeks = '������';
$sc_reminder_set_to_early = "The reminder cannnot be set to appear before the previous occurence. Please shorten the reminder time or lengthen the recurring period.";
$sc_cycle_start_later = 'The cycle starting date is later or equal then the ending date.';


$cmdGenerate = 'Generate';
$sc_preferences = '���������';
$sc_holidays = '��������';

$strNoHolidays = '��� ���������� � ���� ������';
$strUnknown = '����������';
$strYear = '���';
$strDeleteHolidaysPrefix = 'Are you sure you want to delete all holiday records of the year ';
$strDeleteHolidaysSuffix = '?';
$strReplaceHolidays = 'Are you sure you want to overwrite all existent holiday records?';
$sc_holidays_text1 = 'Please click on \''.$cmdGenerate.'\' to compute the holiday records for the selected year.';
$sc_holidays_text2 = 'Please click on \''.$cmdApply.'\' to store all computed holiday records in the database.';

//translation required below this
$sc_client = '������';
$sc_no_contact = 'None';

$sc_background = '��� ����';

$sc_colors['red'] = '�������';
$sc_colors['green'] = '�������';
$sc_colors['blue'] = '�����';
$sc_colors['pink'] = '�������';
$sc_colors['orange'] = '���������';
$sc_colors['brown'] = '����������';
$sc_colors['yellow'] = '������';
$sc_colors['grey'] = '�����';
$sc_colors['purple'] = '���������';
$sc_colors['white']= '�����';
$sc_status = '������';

$sc_show_hours = 'Show hours from';
$sc_to = 'to';

$sc_today = '�������';

$sc_recur_every = '���������� ������';
$sc_months = '������';

$sc_private_event = '��������� �������';
$sc_calendar_exists = 'A calendar with this name already exists';
//translate
$sc_month = '�����';
$sc_view = '��������';
$sc_calendar = '���������';
$sc_default = '�� ���������';
$sc_month_view = '�����';

//text changed, needs new translation
$sc_holidays_no_file_prefix = 'The holidays couldn\'t be generated, because the file containing holidays information for the ';
$sc_holidays_no_file_suffix = ' language is either empty or doesn\'t exist.';

$sc_no_events = '������� �� �������';

//2.03
$cal_export = '�������';
$cal_import = '������';
$cal_please_wait = '���������� �����...';
$cal_import_text = 'Select an iCal (*.ics) file and click at \'Ok\'';
$cal_filename = '����';
$cal_import_success = '������ �������������';

//2.04
$cal_add_todo = '����� ������';
$cal_todos = '������';

$cal_hide_completed = '������ �����������';
$cal_show_all = '�������� ��� ������';
$cal_show_own = '������ ���� ������';
$cal_show_responsible = 'Show reponsible tasks';

$cal_priority = '���������';
$cal_priority_values[0] = '������';
$cal_priority_values[1] = '����������';
$cal_priority_values[2] = '�������';

$cal_status = '������';
$cal_canceled = '�������';
$cal_completed = '��������';
$cal_percent_completed = '% ���������';

$cal_before_task_start = 'Before the task starts';
$cal_before_task_due = 'Before the task should be finnished';
$cal_responsible = 'Responsible';
$cal_due_at = 'Due at';
$cal_no_todos= '������ �� �������';
$cal_resend_invitation = 'Resend invitation';

//2.05
$cal_everybody_write = '��� ������ ����� �������������� ��� �������';
$cal_everybody_read = '������ � ���� �������������� ��� �������';

$cal_view = '��������';
$cal_views = '��������';
$sc_view_exists = '�������� � ����� ������ ��� ����������';
$cal_new_view = '����� ��������';
$cal_event_calendars = '���������(�)';

//2.06
$cal_view_merged = 'merged';
$cal_view_emerged = 'emerged';

//2.07
$cal_display = '�����������';
$sc_new_task = "����� ������";
$sc_all_day_events = 'all day events';
$sc_all_day_event = 'all day event';
$sc_usual_events = '�������';
$sc_usual_event = '�������';

//2.08
$sc_recur_section = '�����������';
$sc_options_section = '�����';
$sc_close = '�������';

$cal_count_single = '�������';
$cal_count_multiple = '�������';

$cal_until = 'until';
$cal_forever = '������';

//2.09
$cal_merged_overview = 'Merged overview';
$cal_own_availability = 'Own availability';

//2.11
$cal_no_file = 'No file was recieved';
$cms_no_calendars_in_view = 'This view can\'t be displayed because there are no calendars in this view. Click at \'Views\' to manage views.';
$cal_no_reminder = '�� ����������';

//2.13
$cal_refresh_rate = '������� ����������';
$sc_seconds = 'seconds (Leave empty for no refresh)';
$cal_default_reminder = '����������� �� ���������';
