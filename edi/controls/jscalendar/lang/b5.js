// ** I18N

// Calendar EN language
// Author: Mihai Bazon, <mishoo@infoiasi.ro>
// Encoding: any
// Distributed under the same terms as the calendar itself.

// For translators: please use UTF-8 if possible.  We strongly believe that
// Unicode is the answer to a real internationalized world.  Also please
// include your contact information in the header, as can be seen above.

// full day names
Calendar._DN = new Array
("�P����",
 "�P���@",
 "�P���G",
 "�P���T",
 "�P���|",
 "�P����",
 "�P����",
 "�P����");

// Please note that the following array of short day names (and the same goes
// for short month names, _SMN) isn't absolutely necessary.  We give it here
// for exemplification on how one can customize the short day names, but if
// they are simply the first N letters of the full name you can simply say:
//
//   Calendar._SDN_len = N; // short day name length
//   Calendar._SMN_len = N; // short month name length
//
// If N = 3 then this is not needed either since we assume a value of 3 if not
// present, to be compatible with translation files that were written before
// this feature.

// short day names
Calendar._SDN = new Array
("��",
 "�@",
 "�G",
 "�T",
 "�|",
 "��",
 "��",
 "��");

// full month names
Calendar._MN = new Array
("�@��",
 "�G��",
 "�T��",
 "�|��",
 "����",
 "����",
 "�C��",
 "�K��",
 "�E��",
 "�Q��",
 "�Q�@��",
 "�Q�G��");

// short month names
Calendar._SMN = new Array
("�@��",
 "�G��",
 "�T��",
 "�|��",
 "����",
 "����",
 "�C��",
 "�K��",
 "�E��",
 "�Q��",
 "�Q�@��",
 "�Q�G��");

// tooltips
Calendar._TT = {};
Calendar._TT["INFO"] = "����o�Ӥ��";

Calendar._TT["ABOUT"] =
"DHTML ���/�ɶ� ��ܾ�\n" +
"(c) dynarch.com 2002-2003\n" + // don't translate this this ;-)
"�̷s�������s��: http://dynarch.com/mishoo/calendar.epl\n" +
"Distributed under GNU LGPL.  See http://gnu.org/licenses/lgpl.html for details." +
"\n\n" +
"Date selection:\n" +
"- Use the \xab, \xbb buttons to select year\n" +
"- Use the " + String.fromCharCode(0x2039) + ", " + String.fromCharCode(0x203a) + " buttons to select month\n" +
"- Hold mouse button on any of the above buttons for faster selection.";
Calendar._TT["ABOUT_TIME"] = "\n\n" +
"��ܮɶ�:\n" +
"- ���U����ɶ������ӼW�[\n" +
"- �Ϋ��UShift��Ӵ��\n" +
"- �Ϋ��U�즲�ӧֳt���";

Calendar._TT["PREV_YEAR"] = "�W�@�~ (�κ���b�C)";
Calendar._TT["PREV_MONTH"] = "�W�@�� (�κ���b�C)";
Calendar._TT["GO_TODAY"] = "�줵��";
Calendar._TT["NEXT_MONTH"] = "�U�@�� (�κ���b�C)";
Calendar._TT["NEXT_YEAR"] = "�U�@�~ (�κ���b�C)";
Calendar._TT["SEL_DATE"] = "��ܤ��";
Calendar._TT["DRAG_TO_MOVE"] = "�즲����";
Calendar._TT["PART_TODAY"] = " (����)";

// the following is to inform that "%s" is to be the first day of week
// %s will be replaced with the day name.
Calendar._TT["DAY_FIRST"] = "��� %s ��";

// This may be locale-dependent.  It specifies the week-end days, as an array
// of comma-separated numbers.  The numbers are from 0 to 6: 0 means Sunday, 1
// means Monday, etc.
Calendar._TT["WEEKEND"] = "0,6";

Calendar._TT["CLOSE"] = "����";
Calendar._TT["TODAY"] = "����";
Calendar._TT["TIME_PART"] = "(Shift-)���U�즲���ܧ�ƭ�";

// date formats
Calendar._TT["DEF_DATE_FORMAT"] = "%Y-%m-%d";
Calendar._TT["TT_DATE_FORMAT"] = "%Y�~ %m�� %d��, %A";

Calendar._TT["WK"] = "�g";
Calendar._TT["TIME"] = "�ɶ�:";
