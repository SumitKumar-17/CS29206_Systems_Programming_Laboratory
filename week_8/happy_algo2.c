#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_1 9999
#define MAX_NUM_2 9999

void init(int A[], int n) {
    for (int i = 0; i <= n; i++) {
        A[i] = 0;
    }
}

int isvisited(int A[], int n) {
    return A[n];
}

void markvisited(int A[], int n) {
    A[n] = 1;
}

int nextnum(int n) {
    if (n < 100)
        return 162;
    else
        return 738;
}

int ishappy(int n) {
    int A[MAX_NUM_1];
    if (n > 100)
        init(A, MAX_NUM_2);
    else
        init(A, MAX_NUM_1);
        
    markvisited(A, n);
    while (1) {
        n = nextnum(n);
        if (!isvisited(A, n)) {
            markvisited(A, n);
            continue;
        }
        if (n == 1)
            return 1;
        else
            return 0;
    }
}

int main() {
    for (int n = 1; n <= 9999; n++) {
        if (ishappy(n)) {
            printf("%d\n", n);
        }
    }
    return 0;
}
