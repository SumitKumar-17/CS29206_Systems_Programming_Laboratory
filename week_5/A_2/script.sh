#/!bin/bash

gcc -o examples.out app/examples.c lib/librecrel.a -I lib/order1 -I lib/order2  -I lib/order3
./examples.out
rm -f examples.out