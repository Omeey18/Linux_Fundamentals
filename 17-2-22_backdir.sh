#!/bin/bash 

backupPath=/home/ompatel/linux_Fundamentals/backup
echo This is the dictory $backupPath for $USERNAM

file=/etc/resolv.conf

echo "File is \$file" #abstrct value of variable using \

#read -p"Enter value "n1 n2 n3 #-p fpr prompt means ask value from user
#echo "value  is" $n1 $n2 $n3

#read -p "Enter domain name"
#domain_name
#dig $domain_name

#read -s -p "Enter the password:" my_pass #reading value silently using -s
#echo "  Your password is " $my_pass

#nameserver="ns1.iqb.com ns2.iqb.com ns2.iqb.com" #variable with multiple value in single line
#read -r ns1 ns2 ns3<<<$nameserver #reading values from nameserver and storing in variables  
#echo "name servers are $ns1 $ns2 $ns3"
#echo $IFS


#read -p "Enter value of X & Y: " x y
#echo "Value of X $x and value of Y is $y"
#ans=$((x+y)) #syntax of atrithmatic operations
#echo "Addition of x+y is "$ans

#declare -i y=10
#declare -i x=5
#ans=$((x+y))
#echo "Addition of x+y is "$ans

#x=a
#ans1=$((x+y))
#echo "Addition is "$ans1


#readonly backuppath=/home/ompatel/backup #value of this variable will not change in futher code 
#echo value of path $backuppath
#backuppath=/hello/new
#echo value of path $backuppath

#${varname?Valuecheck} #syntax to check varible is exit or not

path=${1:?path not supplied}
echo path is $path 

