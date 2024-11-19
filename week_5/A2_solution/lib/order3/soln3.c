#include <stdio.h>
#include <stdlib.h>
#include <soln3.h>

int findterm3 ( recrel3 R, int n )
{
   int i, a, a_1, a_2, a_3;

   if (n < 0) return -1;
   if (n == 0) return R.a0;
   if (n == 1) return R.a1;
   if (n == 2) return R.a2;

   a_1 = R.a2; a_2 = R.a1; a_3 = R.a0;
   for (i=3; i<=n; ++i) {
      a = R.c1 * a_1 + R.c2 * a_2 + R.c3 * a_3 + R.d;
      a_3 = a_2;
      a_2 = a_1;
      a_1 = a;
   }

   return a;
}
