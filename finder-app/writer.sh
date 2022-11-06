#!/usr/bin/bash

if [ $# -lt 2 ]
then
    echo "Not enough arguments provided."
    exit 1
fi

WRITEFILE=$1
WRITESTR=$2

echo "$WRITESTR" > "$WRITEFILE"

if [ $? -ne 0 ]
then
    echo "File write unsuccessful."
    exit 1
fi
