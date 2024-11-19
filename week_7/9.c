#define M 5
#define N 7
#include <stdio.h>
#include <stdlib.h>

typedef int row[N];
int main()
{
    row *A = (row *)malloc(M * sizeof(row));
    printf("A = %p\n", A);
    for (int i = 0; i < M; ++i)
    {
        printf("i = %d\n", i);
        A[i][2 * N + i] = 5;
    }
}

//ERRROR IS WE ARE WITING AN int value of size 4 as a row[n] which is invalid


//12 bytes indicates after 140 bytes of memeory is allocated error si happening

// ths is happeneing as we are tryiing to access 2*n+i is out of bound of the array
