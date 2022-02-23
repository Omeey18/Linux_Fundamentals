#!/bin/bash 
#for command in date pwd df
#do 
#echo " Output of command"
#	$command
#done


#for file in $(ls /home/ompatel/*.sh)
#do 
#echo " Script files are"
#	$file
#done

file=/etc/passwd /etc/group
user=$1
for user in $file
do 
 [ -f $user ] && echo "$user found " || echo "$user not found in $file "

done
