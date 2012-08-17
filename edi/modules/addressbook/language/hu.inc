<?php
//Translated with Group-Office translate module
require_once($GO_LANGUAGE->get_fallback_language_file('addressbook'));
$contacts_title='Névjegyalbum';
$contacts_no_contacts='Nincs találat.';
$contacts_members='Felhasználók';
$contacts_contacts='Névjegyek';
$contacts_add='Új névjegy';
$contacts_groups='Csoportok';
$contacts_other='Egyéb névjegyek';
$contacts_move_to_group='A kijelölt névjegyek áthelyezése egy adott csoportba...';
$groups_no_groups='Nem rendelkezik csoportokkal';
$contacts_group='Csoport';
$contacts_empty_group='Használja a legördülő menüt a névjegyek ebbe a csoportba történő mozgatásához.';
$contacts_this_group='ez a csoport';
$add_contacts_text='Töltse ki a felhasználók E-mail címét és jóváhagyási kódot, majd kattintson az \'Ok\'-ra';
$add_contacts_success='Felhasználó sikeresen hozzáadva';
$add_contacts_wrong='Érvénytelen E-mail cím vagy jóváhagyási kód.';
$add_personal_text='Kattintson a \'Mentés\' gombra a névjegy hozzáadásához. A *-gal jelölt mezők kitöltése kötelező.';
$contacts_select='Válassza ki a hozzáadni kívánt névjegyeket, majd kattintson az \'Ok\'-ra.';
$contacts_select_title='Névjegyek';
$contact_profile='Profil';
$user_profile='Felhasználói profil';
$contacts_authorise='Jóváhagyás';
$contacts_add_member='Az adott felhasználó hozzáadása a névjegyalbumhoz';
$strConfirmSynchronise='Ez felülírja ezt a névjegyet azokkal az adatokkal, amiket a felhasználó írt be. Az Ön által végzett kézi változtatások el fognak veszni. Biztosan folytatni szeretné?';
$contacts_import='Importálás';
$contacts_export='Exportálás';
$contacts_export_text='Válassza ki, hogy milyen típusú CSV-t kíván létrehozni.';
$contacts_delete='Törlés';
$contacts_import_text_group='Válassza ki a csoportot és a CSV fájlt. Kattintson az \'Ok\'-ra.';
$fbNoFile='Nincs fogadott fájl';
$fbPleaseWait='Kérem várjon, feltöltés folyamatban...';
$strNotIncluded='Ne importálja';
$contacts_import_feedback='A következő oszlopokat találtam a CSV fájlban.<br />';
$contacts_import_feedback .=' Egyeztesse a Group-Office oszlopait a fájlban találhatókkal, és győződjön meg arról, hogy egy oszlopot sem választott ki kétszer.';
$contacts_separator='A különböző értékek elválasztó karaktere';
$contacts_no_separator='Nem adott meg elválasztó karaktert.';
$fbFilename='Fájlnév';
$contacts_import_title='Névjegyalbum importálása';
$contacts_import_success='A fájl sikeresen importálva';
$contacts_import_double='Egy vagy több oszlopot kétszer választott ki. Javítsa ki a hibát, és próbálja meg újból.';
$contacts_import_noname='Az \'Utónév\' és \'Vezetéknév\' mezőket ki kell választania';
$contacts_import_incompatible='Nem kompatibilis fájlformátum.<br /><br />A CSV fájl értékeit (pontos)vesszők választják el egymástól.';
$strMember='Felhasználó';
$contact_exist_warning='<b>Megjegyzés:</b> Ez a felhasználó már szerepel az Ön névjegyalbumában.';
$contacts_add_to_group='A kiválasztott felhasználók hozzáadása a következő csoport névjegyeihez...';
$contacts_add_to='A kiválasztott felhasználók hozzáadása a névjegyekhez';
$contacts_add_user='hozzáadás';
$contacts_edit='Szerkesztés';
$contacts_no_select='Nem választott ki semmit sem';
$contacts_this_contact='ez a névjegy';
$contacts_seperator_text='A különböző értékek elválasztó karaktere';
$contacts_quote='A különböző értékeket a következő karakterek határolják';
$contacts_clrf='A sorvégeket ilyen karakterek jelölik';
$contacts_auto_group='Csoportok automatikus létrehozása a fájl alapján';
$contacts_import_to_group='Csoportba történő importálás';
$contacts_search='Keresés';
$cmdSearch='Keres';
$contacts_search_text='Kattintson egy kezdőbetűre, vagy adjon meg egy kulcsszót, majd kattintson a \'Keresés\' gombra. Használhat *-ot helyettesítő jelként.';
$contacts_results='találatok';
$contacts_result='találat';
$contacts_color='Szín';
$contacts_colors['black']='Fekete';
$contacts_colors['red']='Piros';
$contacts_colors['green']='Zöld';
$contacts_colors['blue']='Kék';
$contacts_colors['pink']='Rózsaszín';
$contacts_colors['orange']='Narancs';
$contacts_colors['brown']='Barna';
$ab_addressbooks='Névjegyalbumok';
$ab_owner='Tulajdonos';
$ab_subscribed='Feliratkozva';
$ab_new_ab='Új névjegyalbum';
$ab_addressbook_exists='Már létezik névjegyalbum ilyen néven';
$ab_addressbook='Névjegyalbum';
$ab_no_addressbook='Nincs névjegyalbum';
$contacts_select_single='Kattintson egy névjegyre az adott személy kijelöléséhez';
$ab_group_exists='Már létezik névjegyalbum ilyen néven';
$ab_group_on_file='Névjegyek csoportosítása fájl alapján';
$ab_default='Alapértelmezett';
$ab_edit_contact='A változtatások mentéséhez kattintson az \'Ok\' gombra. A *-gal jelölt mezők kitöltése kötelező';
$ab_browse='Tallózás';
$ab_comment='Megjegyzés';
$ab_contact='Névjegy';
$ab_send_message='Új E-mail';
$ab_new_event='Új esemény';
$ab_templates='Sablonok';
$ab_your_templates='Saját';
$ab_all_templates='Összes';
$template_type[0]='E-mail';
$template_type[1]='OpenOffice.Org';
$ab_type='Típus';
$ab_template_exists='Ilyen néven már létezik sablon.';
$sir_madam['M']='úr';
$sir_madam['F']='úrhölgy';
$ab_upload_oo='Feltöltés';
$ab_upload_nofile='Adatátviteli hiba.';
$ab_oo_doc='Szöveges dokumentum';
$ab_select_template='Válasszon sablont ehhez a dokumentumhoz:';
$ab_add_field_data='A következő értékeket használhatja a dokumentumban:';
$ab_datafield='Adatmező';
$ab_no_template='Nincs sablon';
$ab_new_note='Feljegyzés';
$ab_events='Találkozók';
$ab_new_contact='Új névjegy';
$ab_new_company='Új cég';
$ab_companies='Cégek';
$ab_company_properties='Cégadatok';
$ab_bank_no='Bankszámla&nbsp;szám';
$ab_companies_count_single='cég';
$ab_companies_count='cégek';
$ab_no_companies='Nem találtam cégeket';
$ab_no_company='Nincs cég';
$ab_import_type='Importálás';
$ab_no_company_found='Nem találtam cégeket';
$ab_search_company='Cég keresése';
$ab_edit_company='Cégadatok módosítása';
$ab_new_group='Új csoport';
$ab_export_type='Exportálás';
$ab_custom_fields='További&nbsp;adatmezők';
$ab_field_size='Méret';
$ab_new_field='Új adatmező';
$ab_invalid_field_size='Érvénytelen méret. Válasszon egy értéket 10 és 255 között.';
$ab_field_exists='Már létezik mező ilyen néven.';
$ab_employees='Alkalmazottak';
$ab_no_employees='Nem találtam alkalmazottakat';
$ab_employee_count_single='alkalmazott';
$ab_employee_count_multiple='alkalmazottak';
$ab_vat_no='Adószám';
$ab_add_new='Új hozzáadása';
$ab_add_existing='Meglévő hozzáadása';
$ab_access='Hozzáférés';
$ab_mailings='Körlevelek';
$ab_mailing_groups='Körlevél csoportok';
$ab_no_mailing_groups='Nem találtam körlevél csoportokat';
$ab_no_templates='Nem találtam sablonokat';
$ab_mailing_group_exists='Már létezik körlevél csoport ezen a néven.';
$ab_contacts_count_single='névjegy';
$ab_contacts_count_multiple='névjegyek';
$ab_new_mailing='Új körlevél';
$ab_all_your_addressbooks='összes névjegyalbum';
$ab_search_for='Keresés erre';
$ab_search_on='szűrő';
$ab_search_keyword='Keresendő kifejezés';
$ab_wildcard='(Használjon \'%\'-ot helyettesítő jelként)';
$ab_copy_read_acl='Olvasási jogok másolása a névjegyhez és cégekhez';
$ab_copy_write_acl='Írási jogok másolása a névjegyhez és cégekhez';
$ab_catagory_exists='Már létezik kategória ezen a néven.';
$ab_add_catagory='Kategória hozzáadása';
$ab_add_field='Mező hozzáadása';
$ab_catagory='Kategória';
$ab_todos='Feladatok';
$ab_download='Letöltés';
$ab_download_template='Kattintson a \'Letöltés\' gombra a sablonnak az Ön PC-jére történő letöltéséhez. Ez szükséges a szerkesztéshez.';
$ab_upload='Feltöltés';
$ab_upload_oo_text='Ha végzett az OpenOffice.org sablon szerkesztésével, vissza kell másolnia azt a Group-Office rendszerébe. Válassza ki a fájlt, majd kattintson a \'Feltöltés\' gombra.';
$ab_file_type='Fájltípus';
$ab_import_vcf_file_ok='A feltöltött fájl jónak tűnik. Kattintson az \'Ok\'-ra a névjegyalbumban történő rögzítéshez.';
$ab_import_failed='Sikertelen importálás.';
$contacts_import_text='Válassza ki az importálni kívánt fájlt, majd kattintson az \'Ok\'-ra';
$ab_select_mailing_groups='Válassza ki azt a körlevél csoportot, amelyhez ez a névjegy tartozik';
$ab_move_to_ab='A kiválasztott névjegyek áthelyezése névjegyalbumba...';
$ab_move_com_to_ab='A kiválasztott cégek áhelyezése névjegyalbumba...';
$ab_search_sender='E-mail cím keresése';
$ab_contact_exists='Ez a névjegy már létezik. Kattintson ide: %s a meglévő névjegy megtekintéséhez, vagy kattintson az \'Ok\' / \'Alkalmaz\' gombok valamelyikére a jelenlegi névjegyadatok elmentéséhez.';
$ab_company_exists='Ez a cég már létezik. Kattintson ide: %s a meglévő névjegy megtekintéséhez, vagy kattintson az \'Ok\' / \'Alkalmaz\' gombok valamelyikére a jelenlegi cégadatok elmentéséhez.';
$ab_here='itt';
$ab_search_for_keyword='kulcsszó';
$ab_search_in='Keresés itt';
$ab_users_count_single='felhasználó';
$ab_users_count_multiple='felhasználók';
$ab_no_users='Nem találtam felhasználókat';
$ab_select_addressbook='Válasszon névjegyalbumot';
$ab_move='Áthelyezés';
$ab_file='Fájl';
$ab_template_uploaded='Dokumentum elmentve';
$ab_select_mailing_group='Válassza ki azt a körlevél csoportot, amelynek levelet szeretne küldeni';
$ab_id='sorszám';
?>