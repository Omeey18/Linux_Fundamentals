#!/bin/bash

DEST=/home/ompatel/backup
SRC=/home/ompatel
[!-d $DEST] && mkdir -p $DEST

[!-d $SRC] && {echo "$SRC does not exit, can not initiae backup to $DEST " exit 1;}
echo " Backuping in the dictionary $DEST"
ter zcvf $DEST/backup.tar.gz $SRC 2>/dev/null
status=$?
[$status -eq 0] && echo "Back is done" || echo"Backup failed"
