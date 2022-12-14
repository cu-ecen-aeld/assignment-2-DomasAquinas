#!/usr/bin/bash

if [ $# -lt 2 ]
then
    echo "Not enough arguments provided."
    exit 1
fi

FILESDIR=$1
SEARCHSTR=$2

if [ ! -d $FILESDIR ]
then
    echo "Provided filesdir is not a directory."
    exit 1
fi

FILECOUNT=$(ls $FILESDIR | wc -l)
MATCHCOUNT=$(grep -lr "$SEARCHSTR" $FILESDIR/* | wc -l)

echo "The number of files are $FILECOUNT "
echo "and the number of matching lines are $MATCHCOUNT"
