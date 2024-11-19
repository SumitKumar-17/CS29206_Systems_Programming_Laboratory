// staquecheck.c
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "stack.h"
#include "queue.h"

#define ITER_CNT 10

int main() {
    stack S = initstack();
    for (int i = 0; i < ITER_CNT; ++i) {
        S = push(S, rand() % 100);
        printstack(S);
    }
    S = destroystack(S);

    queue Q = initqueue();
    for (int i = 0; i < ITER_CNT; ++i) {
        Q = enqueue(Q, rand() % 100);
        printqueue(Q);
    }
    Q = destroyqueue(Q);

    exit(0);
}
