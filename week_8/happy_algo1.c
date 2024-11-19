#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 9999

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
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int ishappy(int n) {
    int A[MAX_NUM];
    init(A, MAX_NUM);
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
