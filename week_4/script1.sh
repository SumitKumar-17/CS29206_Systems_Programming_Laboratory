# /!bin/bash
rm -f *.o triangle_calculator
gcc -o triangle_calculator triangle_calculator.c -lm
./triangle_calculator