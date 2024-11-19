#!/bin/bash
function FIB () {
local n=$1
if [ 1 -le $n ]; then echo "$n"; return 0; fi
echo $(( ‘FIB $((n-1))‘ + ‘FIB $((n-2))‘ ))
}
echo -n "Enter n: "; read n
echo "F($n) = ‘FIB $n‘"
