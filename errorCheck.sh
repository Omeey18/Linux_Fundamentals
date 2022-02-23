LOGGER=/usr/bin/logger
FILE=/home/ompatel/hwlogfile
AMESS="Warning - Hardware errors found on $(hostname) @ $(date). See log file for $FILE."

OK_MESS="OK: NO Hardware Error Found."
WARN_MESS="ERROR: Hardware Error Found."

if test ! -f "$FILE"
then 
echo "Error - $FILE not found or mcelog is not configured for 64 bit Linux systems."
exit 1
fi

error_log=$(grep -c -i "hardware error" $FILE)
if[ $error_log -gt 0]
then 
echo "$AMESS" 
else 
echo "$OK_MESS"
fi
