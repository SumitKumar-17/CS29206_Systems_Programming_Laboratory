#include <stdio.h>

void h(int);

void f(int n) {
    if (n > 0)
        h(n - 3);
}

void g(int n) {
    if (n > 0)
        f(n - 1);
}

void h(int n) {
    if (n > 0)
        g(n - 2);
}

int main() {
    f(100);
    return 0;
}
