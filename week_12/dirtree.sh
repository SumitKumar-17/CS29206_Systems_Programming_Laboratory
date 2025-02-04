#!/bin/bash

function exploredir () {
    local currentdir=$1
    local currentlev=$2
    local lev=0

    while [ $lev -lt $currentlev ]; do
        echo -n " "
        lev=$((lev+1))
    done

    echo -n "$currentdir"

    if [ ! -r "$currentdir" ] || [ ! -x "$currentdir" ]; then
        echo " [Unable to explore further]"
    else
        echo ""
        for entry in $(ls "$currentdir"); do
            if [ -d "$currentdir/$entry" ]; then
                exploredir "$currentdir/$entry" $((currentlev+1))
            fi
        done
    fi
}

if [ $# -eq 0 ]; then 
    rootdir=.
else 
    rootdir=$1
fi

if [ ! -d "$rootdir" ]; then
    echo "$rootdir is not a directory"
    exit 1
fi

exploredir "$rootdir" 0
