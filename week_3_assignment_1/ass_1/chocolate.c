#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "settype.c"
#include "setops.c"

int howmanypackets(int N);

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));

    int N;
    printf("Number of coupons (N):");
    scanf("%d", &N);

#ifdef STAT_MODE
    int total_packets = 0;
    printf("+++ Statistics mode ");
    for (int i = 0; i < 1000; i++)
    {
        total_packets += howmanypackets(N);
    }
    printf("--- Average number of packets to buy =%lf\n", (double)total_packets / 1000);
#else

    printf("+++ Interactive mode\n");
    howmanypackets(N);
#endif

    return 0;
}

int howmanypackets(int N)
{
    numset S = setinit(N);
    int set_count = 0;

    while (setsize(S) < N)
    {
        int c = 1 + rand() % N;
        S = setaddelt(S, c);
        set_count++;

#ifndef STAT_MODE
        // set_count++;
        printf("packet %d has coupon %d, Available coupons: ", set_count, c);
        setprint(S);
#endif
    }

#ifndef STAT_MODE
    printf("--- %d packets were bought ", set_count);
#endif

    return set_count;
}
