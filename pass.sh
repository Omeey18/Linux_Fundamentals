
pass_file=/etc/passwd
read -p "Enter UserName: " username
grep "^$username" $pass_file>/dev/null
status=$?
if test $status -eq 0
then 	
	echo "User is found."
else
	echo "User not found."
fi
#if test "$pass" == "om"
#then 
#	echo Password is correct
#else
#	echo Wronge PAssword
#fi


#read -p "Enter number: " num
#if test $(($num%2)) == 0
#then 
#	echo Even num
#else 
#	echo odd num
#fi
