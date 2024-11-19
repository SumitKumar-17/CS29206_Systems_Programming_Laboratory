#!/bin/bash

if [ $# -eq 0 ]; then 
    echo "Run with a command line argument"
    exit 1
fi

fname=$1
if [ ! -e "$fname" ];  then
    echo "\"$fname\" does not exist"
    exit 2
else
if [ -f "$fname" ];then echo "\"$fname\" is a regular file"
elif [ -d "$fname" ]; then echo "\"$fname\" is a directory"
else echo "\"$fname\" is not a regular file or directory"
fi

echo -n "Permissions:"
if [ -r "$fname" ]; then echo -n " read" ;fi
if [ -w "$fname" ]; then echo -n " write" ;fi
if [ -x "$fname" ]; then echo -n " execute" ;fi
echo ""
fi
