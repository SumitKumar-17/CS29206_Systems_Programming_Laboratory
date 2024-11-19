#include <stdio.h>
#include <stdlib.h>
#include <settype.h>
#include <setops.h>

void setprint ( numset S )
{
   int i, first = 1;

   printf("{");
   for (i=1; i<=S[0]; ++i) if (S[i]) {
      printf("%s%d", (first) ? "" : ", ", i);
      first = 0;
   }
   printf("}\n");
}

int setsize ( numset S )
{
   int i, size = 0;

   for (i=1; i<=S[0]; ++i) if (S[i]) ++size;
   return size;
}

numset setaddelt ( numset S , int i )
{
   if (i > S[0]) {
      fprintf(stderr, "*** Error in setaddelt: element not in the universe\n");
   } else {
      S[i] = 1;
   }
   return S;
}

numset setdelt ( numset S , int i )
{
   if (i > S[0]) {
      fprintf(stderr, "*** Error in setdelelt: element not in the universe\n");
   } else {
      S[i] = 0;
   }
   return S;
}

numset setunion ( numset A, numset B )
{
   int i;
   numset S = NULL;

   if (A[0] != B[0]) {
      fprintf(stderr, "*** Error in setunion: sets are from different universes\n");
   } else {
      S = setinit(A[0]);
      for (i=1; i<=A[0]; ++i) S[i] = A[i] | B[i];
   }
   return S;
}

numset setintersection ( numset A, numset B )
{
   int i;
   numset S = NULL;

   if (A[0] != B[0]) {
      fprintf(stderr, "*** Error in setintersection: sets are from different universes\n");
   } else {
      S = setinit(A[0]);
      for (i=1; i<=A[0]; ++i) S[i] = A[i] & B[i];
   }
   return S;
}
