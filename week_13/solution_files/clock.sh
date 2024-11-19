#!/bin/bash

L1=(" --- " "    ." " --- " " --- " ".   ." " --- " " --- " " --- " " --- " " --- ")
L2=("|   |" "    |" "    |" "    |" "|   |" "|    " "|    " "    |" "|   |" "|   |")
L3=("|   |" "    |" " --- " " --- " " ---|" " --- " "|--- " "    |" " --- " " ---|")
L4=("|   |" "    |" "|    " "    |" "    |" "    |" "|   |" "    |" "|   |" "    |")
L5=(" --- " "    ." " --- " " --- " "    ." " --- " " --- " "    ." " --- " " --- ")

ch="o"
pattern="(.*) ([0-9])([0-9]):([0-9])([0-9]):([0-9])([0-9]) ([A-Za-z][A-Za-z])"
while [ true ]; do
   clear
   vskip=$(((LINES - 9) / 2))
   hskip=$(((COLUMNS - 55) / 2))
   h=""; i=0; while [ $i -lt $hskip ]; do h="$h "; i=$((i+1)); done
   t=`date +"%A %d %B %Y %I:%M:%S %p %Z"`
   if [[ $t =~ $pattern ]]; then
      d=${BASH_REMATCH[1]}
      h1=${BASH_REMATCH[2]}
      h2=${BASH_REMATCH[3]}
      m1=${BASH_REMATCH[4]}
      m2=${BASH_REMATCH[5]}
      s1=${BASH_REMATCH[6]}
      s2=${BASH_REMATCH[7]}
      m=${BASH_REMATCH[8]}
      i=0; while [ $i -lt $vskip ]; do echo ""; i=$((i+1)); done
      echo "$h$d"
      echo "$h+-----------------------------------------------------+"
      echo "$h|  ${L1[$h1]}  ${L1[$h2]}     ${L1[$m1]}  ${L1[$m2]}     ${L1[$s1]}  ${L1[$s2]}     |"
      echo "$h|  ${L2[$h1]}  ${L2[$h2]}  $ch  ${L2[$m1]}  ${L2[$m2]}  $ch  ${L2[$s1]}  ${L2[$s2]}     |"
      echo "$h|  ${L3[$h1]}  ${L3[$h2]}     ${L3[$m1]}  ${L3[$m2]}     ${L3[$s1]}  ${L3[$s2]}     |"
      echo "$h|  ${L4[$h1]}  ${L4[$h2]}  $ch  ${L4[$m1]}  ${L4[$m2]}  $ch  ${L4[$s1]}  ${L4[$s2]}     |"
      echo "$h|  ${L5[$h1]}  ${L5[$h2]}     ${L5[$m1]}  ${L5[$m2]}     ${L5[$s1]}  ${L5[$s2]}  $m |"
      echo "$h+-----------------------------------------------------+"
   else
      echo $t
   fi
   read -t 0.49 c && exit 0
   if [ $ch == "o" ]; then ch=" "; else ch="o"; fi
done
