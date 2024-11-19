#!/bin/bash

gcc -c -o stack.o stack.c -I.
gcc -c -o queue.o queue.c -I.
ar rcs libstaque.a stack.o queue.o
gcc -o staquecheck staquecheck.c -I. -L. -lstaque
./staquecheck
rm -f stack.o queue.o libstaque.a staquecheck
