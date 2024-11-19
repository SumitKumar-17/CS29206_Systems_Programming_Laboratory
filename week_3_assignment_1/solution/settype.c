#include <stdio.h>
#include <stdlib.h>
#include <settype.h>

numset setinit ( int N )
{
   numset S;
   int i;

   S = (int *)malloc((N + 1) * sizeof(int));
   S[0] = N;
   for (i=1; i<=N; ++i) S[i] = 0;
   return S;
}

numset setrand ( int N )
{
   numset S;
   int i;

   S = (int *)malloc((N + 1) * sizeof(int));
   S[0] = N;
   for (i=1; i<=N; ++i) S[i] = (rand() % 2) ? 1 : 0;
   return S;
}

/* The following function first generates t 1's and n - t 0's. It then makes a random
   permutation of this array. Does this algorithm generate each of the C(n,t) subsets
   with equal probability?

   This function is just a placeholder. Do not worry too much about its mathematical
   accuracy.
*/
numset setrandsize ( int N, int t )
{
   numset S;
   int i, j;

   if (t > N) {
      fprintf(stderr, "*** Error in randset: subset size larger than the universe size\n");
      return NULL;
   }

   S = (int *)malloc((N + 1) * sizeof(int));
   S[0] = N;
   for (i=1; i<=t; ++i) S[i] = 1;
   for (i=t+1; i<=N; ++i) S[i] = 0;
   for (i=1; i<N; ++i) {
      j = i + rand() % (N-i+1);
      if ((j != i) && (S[j] != S[i])) {
         t = S[i]; S[i] = S[j]; S[j] = t;
      }
   }
   return S;
}

numset setdestroy ( numset S )
{
   free(S);
   return NULL;
}
