#/bin/bash

file=/etc/passwd
while IFS=: read -r user pass uid gid home shell
do 
	
	[ $uid -ge 500 ] && echo "$user has $uid with home home directory $home and shell $shell "]

done <"$file"

