#!/bin/bash
INSPECT_DIR=/var/spool/filter
SENDMAIL="/usr/sbin/sendmail -G -i"
EX_TEMPFAIL=75
EX_UNAVAILABLE=69
cat >/tmp/in.$$ || { 
	echo Cannot save mail to file; exit $EX_TEMPFAIL; }
sudo /usr/local/softnix/apache2/htdocs/edi/duplicateMasterFilter.php  $@ /tmp/in.$$ 
