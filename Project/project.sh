#!/bin/bash 

#creating 5 diffrent files here
touch "$(date +"%F_%T")_"{1..5}.txt

#creating 4 symbolic links 
for i in {1..4}
do
	ln -s "$(date +"%F_%T")_$i".txt "$(date +"%F_%T")_"linked$i.txt
done

#creating 1 hard link
ln "$(date +"%F_%T")_5".txt "$(date +"%F_%T")_"linked5.txt

#removing some file to create broken links
for i in {1..5}
do
rm "$(date +"%F_%T")_$i".txt
done
#rm "$(date +"%F_%T")_5".txt is hard link. It will not be stored in broken links file. 

#finding broken links and stroing into different file
find . -xtype l > broken_links.txt

