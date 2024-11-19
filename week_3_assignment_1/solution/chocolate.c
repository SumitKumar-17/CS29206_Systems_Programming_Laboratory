#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <settype.h>
#include <setops.h>

#define NEXPT 1000

int howmany ( int N )
{
   int i, n;
   numset S;

   S = setinit(N);
   n = 0;
   while (setsize(S) < N) {
      ++n;
      i = 1 + rand() % N;
      S = setaddelt(S,i);
      #ifndef STAT_MODE
         printf("    Packet %3d has coupon %3d, Available coupons: ", n, i);
         setprint(S);
      #endif
   }
   return n;
}

int main ( int argc, char *argv[] )
{
   int N, n;

   srand((unsigned int)time(NULL));

   if (argc > 1) {
      N = atoi(argv[1]);
   } else {
      printf("\nNumber of coupons (N): ");
      scanf("%d", &N);
   }

   #ifdef STAT_MODE
      int i;

      printf("+++ Statistics mode\n");
      n = 0;
      for (i=0; i<NEXPT; ++i) n += howmany(N);
      printf("--- Average number of packets to buy = %lf\n", (double)n / (double)NEXPT);
   #else
      printf("+++ Interactive mode\n");
      n = howmany(N);
      printf("--- %d packets were bought\n", n);
   #endif

   exit(0);
}
