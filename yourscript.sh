#!/bin/bash



pa=/etc/password

if test "$1" == ""
then 	
	echo "ERR: format should be $0 username"
	exit 1
else 
	grep "^$1" $pa>/dev/null
	status=$?

	if test $status -eq 0
	then 
		echo "User Exists"
	else
		echo "User not found "
	fi
fi
