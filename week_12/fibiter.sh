#!/bin/bash

function computerest() {
    local n=$1
    while [ $n -le $2 ];do F[$n]=$((F[n-1]+F[n-2])); n=$((n+1)); done
}

declare -ia F=([0]=0  [1]=1); N=1

while true
do
    echo -n "Enter n: "; read n
    if [ $n -lt 0 ];then echo "Enter a positive integer ";continue ;fi
    if [ $n -gt $N ];then 
        echo "Computing F($((N+1))) through F($n)"
        computerest $((N+1)) $n
        N=$n
    fi
    echo "F($n)=${F[$n]}"
    until flase
    do 
        echo -n "Repeat (y/n)? "; read ans
        case $ans in
        (y|Y) break ;;
        (n|N) exit ;;
        (*) echo "Enter y or n" ;
        esac
    done
done 