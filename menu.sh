opt=$1;
file=$2

shopt -s nocasematch
case $opt in
tar)
	echo " compressing the $file for editing"
	;;
gzip) 
	echo " Zipping the content of $file"
	;;
*)
	echo " Arguments are missing"
	echo " usage: command -e-E or -c|C filename "
	;;
esac 
