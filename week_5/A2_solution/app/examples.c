#include <stdio.h>
#include <stdlib.h>
#include "../lib/order1/soln1.h"
#include "../lib/order2/soln2.h"
#include "../lib/order3/soln3.h"

int main ()
{
   int n;
   recrel1 R1;
   recrel2 R2;
   recrel3 R3;

   printf("n = "); scanf("%d", &n);

   /* Tower of Hanoi */
   R1.c1 = 2; R1.d = 1; R1.a0 = 0;
   printf("ToH(%d) = %d\n", n, findterm1(R1,n));

   /* Fibonacci numbers + 5 */
   R2.c1 = R2.c2 = 1; R2.d = -5; R2.a0 = 5; R2.a1 = 6;
   printf("Fib(%d) + 5 = %d\n", n, findterm2(R2,n));

   /* Fibonacci numbers */
   R3.c1 = 0; R3.c2 = 2; R3.c3 = 1;
   R3.d = 0; R3.a0 = 0; R3.a1 = 1; R3.a2 = 1;
   printf("Fib(%d) = %d\n", n, findterm3(R3,n));
}
