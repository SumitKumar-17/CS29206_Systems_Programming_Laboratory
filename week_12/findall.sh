#!/bin/bash

echo -n "Enter the name of the file you want to search for: "
read  extn
echo "The files with the extension $extn are:"
ls -R ~ | grep "\.$extn$"
echo "The files with the extension $extn are found in the above directories."