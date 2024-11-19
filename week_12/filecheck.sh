#!/bin/bash
[ $# -eq 0 ] && { echo "Run with a command-line argument"; exit 1; }
[ ! -e "$1" ] && { echo "\"$1\" does not exist"; exit 0; }
echo "\"$1\" exists"
[ -f "$1" ] && echo "\"$1\" is a regular file"
[ ! -f "$1" ] && echo "\"$1\" is not a regular file"
[ -d "$1" ] && echo "\"$1\" is a directory"
[ ! -d "$1" ] && echo "\"$1\" is not a directory"
echo -n "Permissions:"
[ -r "$1" ] && echo -n " read"
[ -w "$1" ] && echo -n " write"
[ -x "$1" ] && echo -n " execute"
echo ""
