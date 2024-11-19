#include <stdio.h>

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
    while (n != 1 && n != 4) {
        n = nextnum(n);
    }
    return (n == 1);
}

int main() {
    for (int n = 1; n <= 999999; n++) {
        if (ishappy(n)) {
            printf("%d\n", n);
        }
    }
    return 0;
}
