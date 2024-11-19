#include <stdio.h>
#include <stdlib.h>
#include <soln1.h>

int findterm1 ( recrel1 R, int n )
{
   int i, a;

   if (n < 0) return -1;
   a = R.a0;
   for (i=1; i<=n; ++i) a = R.c1 * a + R.d;
   return a;
}
