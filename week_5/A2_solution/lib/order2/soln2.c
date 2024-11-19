#include <stdio.h>
#include <stdlib.h>
#include <soln2.h>

int findterm2 ( recrel2 R, int n )
{
   int i, a, a_1, a_2;

   if (n < 0) return -1;
   if (n == 0) return R.a0;
   if (n == 1) return R.a1;

   a_1 = R.a1; a_2 = R.a0;
   for (i=2; i<=n; ++i) {
      a = R.c1 * a_1 + R.c2 * a_2 + R.d;
      a_2 = a_1;
      a_1 = a;
   }

   return a;
}
