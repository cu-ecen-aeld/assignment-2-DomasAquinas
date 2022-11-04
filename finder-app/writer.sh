#!/usr/bin/bash

if [$# < 2]
then
    echo "Not enough arguments provided."
    exit 1
fi

WRITEFILE = $1
WRITESTR = $2

cat $WRITESTR > $WRITEFILE

if [$?]
then
    echo "File write unsuccessful."
    exit 1
fi
