<?php
//Translated with Group-Office translate module
require_once($GO_LANGUAGE->get_fallback_language_file('calendar'));
$sc_title='Títol';
$sc_description='Descripció';
$sc_participants='Convidats';
$sc_location='Lloc';
$month_times[0]='Primer';
$month_times[1]='Segón';
$month_times[2]='Tercer';
$month_times[3]='Quart';
$sc_new_app='Nova cita';
$sc_calendars='Calendaris';
$sc_invited='Heu estat convidat a unir-vos a la cita descrita a sota.';
$sc_types1[0]='No repeteixis';
$sc_types1[1]='dies';
$sc_types1[2]='setmanes';
$sc_types1[3]='mesos per data';
$sc_types1[4]='mesos per dia';
$sc_types1[5]='anys';
$sc_types[0]='Un cop';
$sc_types[1]='Diàriament';
$sc_types[2]='Setmanalment';
$sc_types[3]='Mensualment per data';
$sc_types[4]='Mensualment per dia';
$sc_types[5]='Anualment';
$sc_start_at='Comença el';
$sc_end_at='Acaba el';
$sc_start_time='Hora d\'inici';
$sc_end_time='Hora final';
$sc_at_days='Els dies';
$sc_of_month='del mes..';
$sc_cycle_start='El cicle comença el';
$sc_cycle_end='Repeteix fins';
$sc_accept_question='Voleu acceptar i programar aquesta cita?';
$sc_accept='accepta';
$sc_decline='rebutja';
$sc_notime='L\'hora no és aplicable';
$sc_noend='Sense data d\'acabament.';
$sc_never_happens='Entrada incorrecta! Aquesta cita mai succeirà.';
$sc_start_later='Entrada incorrecta! L\'hora d\'inici és superior a l\'hora d\'acabament.';
$sc_add_self='Entrada manual';
$sc_select_calendar='Seleccioneu el calendari on programar aquesta cita';
$sc_accept_confirm='La cita ha estat acceptada i programada.';
$sc_no_calendars='No s\'ha trobat cap calendari vàlid per programar aquesta cita.';
$sc_bad_event='No s\'ha trobat cap cita vàlida. Probablement està suprimida.';
$sc_accept_title='Acepta la cita';
$sc_decline_confirm='La cita està rebutjada.';
$sc_decline_title='Rebutja la cita';
$sc_status='estat';
$sc_not_responded='No respost';
$sc_accepted='Acceptat';
$sc_declined='Rebutjat';
$sc_no_participants='Sense participants';
$sc_person='Persona';
$sc_owner='Propietari';
$sc_type='Tipus';
$sc_subscribed='Subscrit';
$sc_subscribe='Subscriu';
$sc_new_calendar='Nou calendari';
$sc_no_calendar='No s\'ha trobat cap calendari. Si us plau, creeu-ne un ara o deixeu que Group-Office us en crei un.';
$sc_day_view='Vista&nbsp;diària';
$sc_week_view='Vista&nbsp;setmanal';
$sc_list_view='Vista&nbsp;en&nbsp;llista';
$sc_put_in='Posa-hi';
$sc_inherit_permissions='Hereta els permisos de';
$sc_no_inherit='No heretis';
$sc_select_calendar_please='Seleccioneu al menys un calendari si us plau.';
$sc_events='Cites';
$sc_from_calendar='del calendari';
$sc_enitrely='Completament';
$sc_delete_event='Suprimeix cita';
$sc_delete_pre='Voleu suprimir la cita';
$sc_delete_suf='completament o només d\'aquest calendari?';
$sc_refresh='Refresca';
$sc_reminder='Recordatori';
$sc_mins='minuts';
$sc_hour='hora';
$sc_hours='hores';
$sc_day='dia';
$sc_days='dies';
$sc_week='setmana';
$sc_weeks='setmanes';
$sc_reminder_set_to_early='El recordatori no pot ser posat per aparèixer abans de l\'anterior ocurrència. Si us plau, escurceu l\'hora del recordatori o allargueu la periodicitat de la repetició.';
$sc_cycle_start_later='La data d\'inici del cicle és superior o igual a la data d\'acabament.';
$cmdGenerate='Genera';
$sc_preferences='Preferències';
$sc_holidays='Vacances';
$strNoHolidays='No hi ha vacances a la base de dades';
$strUnknown='Desconegut';
$strYear='Any';
$strDeleteHolidaysPrefix='Esteu segurs de suprimir tots els registres de vacances de l\'any ';
$strDeleteHolidaysSuffix='?';
$strReplaceHolidays='Esteu segurs de sobreescriure els actuals registres de vacances?';
$sc_holidays_text1='Si us plau, feu clic a \'\'.$cmdGenerate.\'\' per calcular els registres de vacances de l\'any seleccionat.';
$sc_holidays_text2='Si us plau, feu clic a \'\'.$GLOBALS[\'cmdApply\'].\'\' per desar tots els registres calculats a la base de dades.';
$sc_client='Client';
$sc_no_contact='Cap';
$sc_background='Color de fons';
$sc_colors['red']='Vermell';
$sc_colors['green']='Verd';
$sc_colors['blue']='Blau';
$sc_colors['pink']='Rosa';
$sc_colors['orange']='Taronja';
$sc_colors['brown']='Marró';
$sc_colors['yellow']='Groc';
$sc_colors['grey']='Gris';
$sc_colors['purple']='Púrpura';
$sc_colors['white']='Blanc';
$sc_show_hours='mostra hores des de';
$sc_to='fins';
$sc_today='Avui';
$sc_recur_every='Repeteix cada';
$sc_months='mesos';
$sc_private_event='Cita privada';
$sc_calendar_exists='Ja existeix un calendari amb aquest nom';
$sc_month='Mes';
$sc_view='Vista';
$sc_calendar='Calendari';
$sc_default='Per defecte';
$sc_month_view='Vista&nbsp;mensual';
$sc_holidays_no_file_prefix='Les vacances no poden ser generades, perque el fitxer que conté la informació de vacances per a l\'idioma ';
$sc_holidays_no_file_suffix=' és buit o no existeix.';
$sc_no_events='No s\'ha trobat cap cita';
$cal_export='Exporta';
$cal_import='Importa';
$cal_please_wait='Espereu si us plau...';
$cal_import_text='Seleccioneu un fitxer iCal (*.ics) i feu clic a \'D\'acord\'';
$cal_filename='Fitxer';
$cal_import_success='Dades importades';
$cal_add_todo='Nova feina';
$cal_todos='Feines';
$cal_hide_completed='Amaga les completades';
$cal_show_all='Mostra totes les feines';
$cal_show_own='Mostra les feines pròpies';
$cal_show_responsible='Mostra feines de responsabilitat';
$cal_priority='Prioritat';
$cal_priority_values[0]='Baixa';
$cal_priority_values[1]='Normal';
$cal_priority_values[2]='Alta';
$cal_status='Estat';
$cal_canceled='Cancel·lat';
$cal_completed='Completat el';
$cal_percent_completed='% completat';
$cal_before_task_start='Abans que la feina comenci';
$cal_before_task_due='Abans que la feina s\'acabi';
$cal_responsible='Responsable';
$cal_due_at='Pel';
$cal_no_todos='No s\'ha trobat cap feina';
$cal_resend_invitation='Reenvia la invitació';
$cal_view='Vista';
$cal_views='Vistes';
$sc_view_exists='Ja existeix una vista amb aquest nom';
$cal_new_view='Nova vista';
$cal_event_calendars='Calendari(s)';
$cal_view_merged='combinat';
$cal_view_emerged='separat';
$cal_display='Visualitza';
$sc_new_task='Nova feina';
$sc_all_day_events='tots els dies citats';
$sc_all_day_event='tot el dia citat';
$sc_usual_events='cites';
$sc_usual_event='cita';
$sc_recur_section='Periodicitat';
$sc_options_section='Opcions';
$sc_close='Tanca';
$cal_count_single='cita';
$cal_count_multiple='cites';
$cal_until='fins';
$cal_forever='per sempre';
$cal_merged_overview='Resum del combinat';
$cal_own_availability='Disponibilitat pròpia';
$cal_no_file='No s\'ha rebut cap fitxer';
$cms_no_calendars_in_view='Aquesta vista no pot ser mostrada perque no hi ha calendaris en aquesta vista. Feu clic a \'Vistes\' per gestionar les vistes.';
$cal_no_reminder='Sense recordatori';
$cal_refresh_rate='Velocitat de refresc';
$sc_seconds='segons (Deixeu-ho buit si no hi voleu cap refresc)';
$cal_default_reminder='Recordatori per defecte';
$cal_event='Cita';
$cal_todo='Per-fer';
$cal_participants_write='Els participants poden modificar la cita';
$cal_everybody_write='Tothom pot modificar la cita';
$cal_default_permissions='Permisos per defecte';
$cal_show_todos='Mostra feines al calendari';
$cal_edit_series_or_single='Edita només aquest cas o la sèrie sencera?';
$cal_single='Cas';
$cal_series='Sèrie sencera';
$cal_legend='Llegenda';
$cal_multiple_calendars='Múltiples calendaris';
$cal_cumulative='Entrada incorrecte! La cita duraria més temps que l\'interval de repetició.';
$cal_weekview='La vista setmanal mostra';
$cal_mo_to_fr='de dilluns a divendres';
$cal_mo_to_su='de dilluns a diumenge';
$cal_batchcalendars='Crea calendaris per tots els usuaris';
$cal_create_all_calendars='Crea calendaris per tots els usuaris o concedeix permisos a grups d\'usuaris';
$cal_no_views='No s\'ha trobat cap vista';
$cal_my_cals='Els meus calendaris';
$cal_event_colors_override='Fés servir els colors manualment definits per les cites';
$cal_groups='Grups';
$cal_new_group='Nou grup';
$cal_group_exists='Aquest nom de grup ja existeix. Si us plau escolliu-ne un altre.';
$cal_no_calendars='No s\'han trobat calendaris en aquest grup';
$cal_group='Grup';
$cal_resources='Recursos';
$cal_event_mail_subject='Cita \'%s\' creada en el vostre calendari';
$cal_add_custom_field='Afegeix camp personalitzat';
$cal_event_modified_mail_subject='La cita \'%s\' s\'ha modificat en el vostre calendari';
$cal_your_event_modified_mail_subject='La cita \'%s\' creada per vostè s\'ha modificat';
$cal_add_field='Afegeix camp';
$cal_resource_mail_subject='Recurs \'%s\' reservat';
$cal_resource_modified_mail_subject='Reserva del recurs \'%s\' modificada';
$cal_your_resource_modified_mail_subject='La vostra reserva per al recurs \'%s\' en estat %s ha estat modificada';
$cal_accept_mail_subject='Invitació per a \'%s\' acceptada';
$cal_accept_mail_body='%s ha acceptat la vostra invitació per a \'%s\'';
$cal_decline_mail_subject='Invitació per a \'%s\' rebutjada';
$cal_decline_mail_body='%s ha rebutjat la vostra invitació per a \'%s\'';
$cal_statuses['NEEDS-ACTION']='Necessita actuació de l\'usuari';
$cal_statuses['ACCEPTED']='Acceptat';
$cal_statuses['DECLINED']='Rebutjat';
$cal_statuses['TENTATIVE']='Provisional';
$cal_statuses['DELEGATED']='Delegat';
$cal_statuses['COMPLETED']='Completat';
$cal_statuses['IN-PROCESS']='En procés';
$cal_booking='Reserva per a \'%s\'';
$cal_group_admins='Administradors';
$cal_no_admins='No s\'han definit administradors';
$cal_add_admin='Afegir administrador';
$cal_scale='Escala';
$cal_show_completed='Mostrar feines acabades';
$cal_resource='Recurs';
$cal_grid_view='Vista de reixeta';
$cal_field_types['checkbox']='Requadre de selecció';
$cal_field_types['text']='Text';
$cal_field_types['textarea']='Àrea de text';
$cal_field_types['date']='Camp de data';
$cal_conflict='Aquesta cita està en conflicte amb una altra cita o reserva de recursos. Feu clic a \'D\'acord\' o \'Aplica\' un altre cop per ignorar, o feu clic a "Comprovar disponibilitat\' per trobar una hora escaient.';
$cal_select_calendar='Seleccioneu calendari';
$cal_check_conflicts='Avisa\'m dels conflictes quan creï una cita';
$cal_email_changes='Envia un missatge de correu electrònic quan algú faci canvis al meu calendari';
$cal_shared_calendars='Calendaris compartits';
$cal_admin='Administració';
$cal_resource_groups='Grups de recursos';
$cal_open_calendar='Obre un altre calendari';
$cal_email_reminders='Envia\'m recordatoris de cita per correu electrònic';
$cal_favourites='Favorits';
$cal_your_resource_accepted_mail_subject='La reserva de \'%s\' ha estat acceptada';
$cal_your_resource_declined_mail_subject='La reserva de \'%s\' ha estat rebutjada';
$cal_resource_deleted_mail_subject='La reserva de \'%s\' ha estat esborrada';
$cal_repeats_at='Es repeteix cada %s a les %s';
$cal_repeats='Es repeteix cada %s';
$cal_and='i';
$sc_year='any';
$sc_years='anys';
$cal_another_resource='El recurs s\'ha canviat a %s';
$cal_background_colors='Colors de rerafons';
$cal_weekday='Dia de la setmana';
$cal_background_color='Color de rerafons';
$cal_background='Rerafons';
?>