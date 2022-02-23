#!/bin/bash 

#creating 5 diffrent files here
touch "$(date +"%F %T")_"{1..5}.txt

#creating 3 symbolic links 
ln -s "$(date +"%F %T")_1".txt "$(date +"%F %T")_"linked1.txt
ln -s "$(date +"%F %T")_2".txt "$(date +"%F %T")_"linked2.txt
ln -s "$(date +"%F %T")_3".txt "$(date +"%F %T")_"linked3.txt
ln -s "$(date +"%F %T")_4".txt "$(date +"%F %T")_"linked4.txt

#creating 1 hard link
ln "$(date +"%F %T")_5".txt "$(date +"%F %T")_"linked5.txt


#removing some file to create broken links
rm "$(date +"%F %T")_1".txt
rm "$(date +"%F %T")_2".txt
rm "$(date +"%F %T")_3".txt
rm "$(date +"%F %T")_5".txt #Because it is hard link. It will not store in broken links file 

#finding broken links and stroing into different file
find . -xtype l > /home/ompatel/linux_Fundamentals/Project/broken_links.txt
