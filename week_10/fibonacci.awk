#!/usr/bin/gawk -f

function fib(n){
if(n<=1) return n
return fib(n-1)+fib(n-2)
}

BEGIN{
printf("Enter the integer")
getline n< "-"
n=int(n)
print "FIB("n")="fib(n)
}
