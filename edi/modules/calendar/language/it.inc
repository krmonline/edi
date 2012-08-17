<?php
//Translated with Group-Office translate module
require_once($GO_LANGUAGE->get_fallback_language_file('calendar'));
$sc_title='Titolo';
$sc_description='Descrizione';
$sc_participants='Partecipanti';
$sc_location='Luogo';
$month_times[0]='Primo';
$month_times[1]='Secondo';
$month_times[2]='Terzo';
$month_times[3]='Quarto';
$sc_new_app='Nuovo appuntamento';
$sc_calendars='Calendari';
$sc_invited='Sei stato invitato a partecipare all\'evento descritto di seguito.';
$sc_types1[0]='Nessuna ricorrenza';
$sc_types1[1]='giorni';
$sc_types1[2]='settimane';
$sc_types1[3]='mesi per data';
$sc_types1[4]='mesi per giorno';
$sc_types1[5]='anni';
$sc_types[0]='Unico';
$sc_types[1]='Giornaliero';
$sc_types[2]='Settimanale';
$sc_types[3]='Mensile per data';
$sc_types[4]='Mensile per giorno';
$sc_types[5]='Annuale';
$sc_start_at='Inizio';
$sc_end_at='Fine';
$sc_start_time='Ora inizio';
$sc_end_time='Ora fine';
$sc_at_days='Nei giorni';
$sc_of_month='del mese.';
$sc_cycle_start='Inizio ciclo il';
$sc_cycle_end='Ricorre fino al';
$sc_accept_question='Desideri accettare e inserire questo evento?';
$sc_accept='accetto';
$sc_decline='rinuncio';
$sc_notime='L\'ora non è applicabile';
$sc_noend='Nessuna data finale';
$sc_never_happens='Inserimento errato! Questo evento non accade mai.';
$sc_start_later='Inserimento errato!! L\'ora iniziale è posteriore all\'ora finale.';
$sc_add_self='Inserimento manuale';
$sc_select_calendar='Seleziona il calendario in cui inserire l\'evento';
$sc_accept_confirm='L\'evento è stato inserito ed elaborato.';
$sc_no_calendars='Nessun calendario valido per inserire l\'evento.';
$sc_bad_event='Nessun evento valido trovato. L\'evento probabilmente è stato cancellato.';
$sc_accept_title='Accetta evento';
$sc_decline_confirm='L\'evento è .';
$sc_decline_title='Rifiuta evento';
$sc_status='stato';
$sc_not_responded='Nessuna risposta';
$sc_accepted='Accettato';
$sc_declined='Rifiutato';
$sc_no_participants='Nessun partecipante';
$sc_person='Persona';
$sc_owner='Proprietario';
$sc_type='Tipo';
$sc_subscribed='Sottoscritto';
$sc_subscribe='Sottoscrivi';
$sc_new_calendar='Nuovo calendario';
$sc_no_calendar='Nessun calendario trovato. Creane uno ora oppure lascia che Group-Office te ne crei uno automaticamente.';
$sc_day_view='Visualizza&nbsp;giorno';
$sc_week_view='Visualizza&nbsp;settimana';
$sc_list_view='Visualizza&nbsp;lista';
$sc_put_in='Inserisci in';
$sc_inherit_permissions='Eredita permessi da';
$sc_no_inherit='Non ereditare';
$sc_select_calendar_please='Seleziona almeno un calendario.';
$sc_events='Eventi';
$sc_from_calendar='dal calendario';
$sc_enitrely='Interamente';
$sc_delete_event='Elimina evento';
$sc_delete_pre='Vuoi eliminare questo evento';
$sc_delete_suf='interamente o solo da questo calendario?';
$sc_refresh='Aggiorna';
$sc_reminder='Promemoria';
$sc_mins='min';
$sc_hour='ora';
$sc_hours='ore';
$sc_day='giorno';
$sc_days='giorni';
$sc_week='settimana';
$sc_weeks='settimane';
$sc_reminder_set_to_early='The reminder cannnot be set to appear before the previous occurence. Please shorten the reminder time or lengthen the recurring period.';
$sc_cycle_start_later='The cycle starting date is later or equal then the ending date.';
$cmdGenerate='Genera';
$sc_preferences='Preferenze';
$sc_holidays='Festività';
$strNoHolidays='Nessuna festività nel database.';
$strUnknown='Sconosciuto';
$strYear='Anno';
$strDeleteHolidaysPrefix='Sei sicuro di voler modificare tutte le festività dell\'anno ';
$strDeleteHolidaysSuffix='?';
$strReplaceHolidays='Sei sicuro di voler sovrascrivere tutte le festività esistenti?';
$sc_holidays_text1='Seleziona \'\'.$cmdGenerate.\'\' per elaborare le festività dell\'anno selezionato.';
$sc_holidays_text2='Seleziona \'\'.$cmdApply.\'\' per memorizzare tutte le festività generate nel database.';
$sc_client='Cliente';
$sc_no_contact='Nessuno';
$sc_background='Sfondo';
$sc_colors['red']='Rosso';
$sc_colors['green']='Verde';
$sc_colors['blue']='Blu';
$sc_colors['pink']='Rosa';
$sc_colors['orange']='Arancione';
$sc_colors['brown']='Marrone';
$sc_colors['yellow']='Giallo';
$sc_colors['grey']='Grigio';
$sc_colors['purple']='Viola';
$sc_colors['white']='Bianco';
$sc_show_hours='Mostra ora dalle';
$sc_to='alle';
$sc_today='Oggi';
$sc_recur_every='Ricorre ogni';
$sc_months='mesi';
$sc_private_event='Evento privato';
$sc_calendar_exists='Un calendario con questo nome esiste già';
$sc_month='mese';
$sc_view='Visualizza';
$sc_calendar='Calendario';
$sc_default='Predefinito';
$sc_month_view='Visualizza&nbsp;mese';
$sc_holidays_no_file_prefix='Le festività non possono essere generate, poiché il file contenente le informazioni della vostra regione [\'';
$sc_holidays_no_file_suffix='\'] è vuoto oppure non esiste.';
$sc_no_events='Nessun evento trovato.';
$cal_export='Esporta';
$cal_import='Importa';
$cal_please_wait='Attendere prego...';
$cal_import_text='Seleziona un file iCal (*.ics) e premi \'Ok\'';
$cal_filename='File';
$cal_import_success='Importazione conclusa';
$cal_add_todo='Nuova attività';
$cal_todos='Attività';
$cal_hide_completed='Nascondi le attività completate';
$cal_show_all='Tutte le attività';
$cal_show_own='Le mie attività';
$cal_show_responsible='Attività di mia responsabilità';
$cal_priority='Priorità';
$cal_priority_values[0]='Bassa';
$cal_priority_values[1]='Normale';
$cal_priority_values[2]='Alta';
$cal_status='Stato';
$cal_canceled='Cancellata';
$cal_completed='Completata';
$cal_percent_completed='% completato';
$cal_before_task_start='Prima dell\'inizio';
$cal_before_task_due='Prima della prevista scadenza';
$cal_responsible='Responsabile';
$cal_due_at='Scadenza prevista';
$cal_no_todos='Nessuna attività presente';
$cal_resend_invitation='Rispedisci gli inviti';
$cal_view='Vista';
$cal_views='Viste';
$sc_view_exists='Una vista con questo nome esiste già';
$cal_new_view='Nuova vista';
$cal_event_calendars='Calendari';
$cal_view_merged='unificati';
$cal_view_emerged='distinti';
$cal_display='Mostra';
$sc_new_task='Nuovo lavoro';
$sc_all_day_events='avvenimenti per tutto il giorno';
$sc_all_day_event='avvenimento per tutto il giorno';
$sc_usual_events='avvenimenti';
$sc_usual_event='avvenimento';
$sc_recur_section='Ricorrenza';
$sc_options_section='Opzioni';
$sc_close='Chiudi';
$cal_count_single='Conteggio singolo';
$cal_count_multiple='Conteggio multiplo';
$cal_until='fino a';
$cal_forever='per sempre';
$cal_merged_overview='Sommario unificato';
$cal_own_availability='Propria disponibilità';
$cal_no_file='Nessun file ricevuto';
$cms_no_calendars_in_view='Questa vista non può essere mostrata perché non ci sono calendari. Seleziona \'Viste\' per la gestione.';
$cal_no_reminder='Nessuno';
$cal_refresh_rate='Frequenza di aggiornamento';
$sc_seconds='secondi (lasciare vuoto per nessun aggiornamento)';
$cal_default_reminder='Promemoria predefinito';
$cal_event='Evento';
$cal_todo='Attività';
$cal_participants_write='I partecipanti possono modificare l\'evento';
$cal_everybody_write='Tutti possono modificare l\'evento';
$cal_default_permissions='Premessi predefiniti';
$cal_show_todos='Mostra le attività nel calendario';
$cal_edit_series_or_single='Modifica solo questo o tutte le serie?';
$cal_single='Singolo';
$cal_series='Serie intera';
$cal_legend='Legenda';
$cal_multiple_calendars='Calendari multipli';
$cal_cumulative='Input non valido! L\'evento è più lungo dell\'intervallo della ricorrenza.';
$cal_weekview='Visualizzazione della settimana';
$cal_mo_to_fr='da lunedì a venerdì';
$cal_mo_to_su='da lunedì a domenica';
$cal_batchcalendars='Crea calendari per tutti gli utenti';
$cal_create_all_calendars='Crea calendari per tutti gli utenti o autorizza il gruppo';
$cal_no_views='Nessuna "vista" trovata';
$cal_my_cals='Le mie agende';
$cal_event_colors_override='Usa l\'impostazione colori manuale per gli eventi';
$cal_groups='Gruppi';
$cal_new_group='Nuovo gruppo';
$cal_group_exists='Il nome del gruppo esiste gi&agrave;. Prego inserire un altro nome';
$cal_no_calendars='Nessun\'agenda trovata in questo gruppo';
$cal_group='Gruppo';
$cal_resources='Risorse';
$cal_event_mail_subject='Evento \'%s\' creato nell\'agenda';
$cal_add_custom_field='Aggiungi campo personalizzato';
$cal_event_modified_mail_subject='L\'evento \'%s\' &egrave; stato modificato nella tua agenda';
$cal_your_event_modified_mail_subject='L\'evento \'%s\' da te creato &egrave; stato modificato';
$cal_add_field='Aggiungi campo';
$cal_resource_mail_subject='Risorsa \'%s\' prenotata';
$cal_resource_modified_mail_subject='Prenotazione risorsa \'%s\' modificata';
$cal_your_resource_modified_mail_subject='La prenotazione per \'%s\' &egrave; stata modificata';
$cal_accept_mail_subject='Invito per \'%s\' accettato';
$cal_accept_mail_body='%s ha accettato il tuo invito per \'%s\'';
$cal_decline_mail_subject='Invito per \'%s\' NON &egrave; stato accettato';
$cal_decline_mail_body='%s NON ha accettato il tuo invito per \'%s\'';
$cal_statuses['NEEDS-ACTION']='Serve un\'azione';
$cal_statuses['ACCEPTED']='Accettato';
$cal_statuses['DECLINED']='NON Accettato';
$cal_statuses['TENTATIVE']='Tentativo';
$cal_statuses['DELEGATED']='Delegato';
$cal_statuses['COMPLETED']='Completato';
$cal_statuses['IN-PROCESS']='In corso';
$cal_booking='Prenotazione per \'%s\'';
$cal_group_admins='Amministratori';
$cal_no_admins='admins non definiti';
$cal_add_admin='Aggiungi un amministratore';
$cal_scale='Ridimensiona';
$cal_show_completed='Mostra attivit&agrave; completate';
$cal_resource='Risorsa';
$cal_grid_view='Vista a griglia';
$cal_field_types['checkbox']='Pulsante di spunta';
$cal_field_types['text']='Testo';
$cal_field_types['textarea']='Area di testo';
$cal_field_types['date']='Campo data';
$cal_conflict='L\'evento &egrave; in conflitto con un altro evento o prenotazione di risorsa. Clicca su \'Ok\' o \'Applica\' ancora per ingorare o clicca su \'Controlla disponibilit&agrave;\' per trovare un orario adatto';
$cal_select_calendar='Seleziona agenda';
$cal_check_conflicts='Avvisami sui conflitti quando creo un evento';
$cal_email_changes='Avvisami via e-mail quando qualcuno fa modifiche sul mio calendario';
$cal_shared_calendars='Agende condivise';
$cal_admin='Amministrazione';
$cal_resource_groups='Gruppi di risorse';
$cal_open_calendar='Apri un\'altra agenda';
$cal_email_reminders='Mandami le notifiche degli eventi via mail';
$cal_favourites='Preferiti';
$cal_your_resource_accepted_mail_subject='La prenotazione per \'%s\' &egrave; stata accettata';
$cal_your_resource_declined_mail_subject='La prenotazione per \'%s\' NON &egrave; stata accettata';
$cal_resource_deleted_mail_subject='La prenotazione per \'%s\' &egrave; stata cancellata';
$cal_repeats_at='Ripeti ogni %s a %s';
$cal_repeats='Ripeti ogni %s';
$cal_and='e';
$sc_year='anno';
$sc_years='anni';
$cal_another_resource='La risorsa &grave; stata modificata a %s';
$cal_background_colors='Colori di sfondo';
$cal_weekday='Giorno della settimana';
$cal_background_color='Colore di sfondo';
$cal_background='Sfondo';
?>