#!/bin/bash

function evalcfrac ()
{
   local n
   local num
   local den
   local t
   local A

   declare -ai A
   echo ""
   echo -n "Enter the array of coefficients: "
   read -a A
   n=${#A[@]}
   n=$((n-1))
   num=${A[n]}
   den=1
   while [ $n -gt 0 ]; do
      n=$((n-1))
      t=$((A[n]*num+den))
      den=$num
      num=$t
   done
   echo -n "The continued fraction evaluates to $num / $den = "
   echo `echo "scale=10; $num / $den" | bc`
}

function gencfrac ()
{
   local f
   local a
   local b
   local r

   echo ""
   echo -n "Enter fraction (a / b): "
   read a r b
   echo -n "The continued fraction expansion of $a / $b is:"
   while [ $b -gt 0 ]; do
      echo -n " $((a / b))"
      r=$((a % b))
      a=$b
      b=$r
   done
   echo ""
}

evalcfrac
gencfrac
