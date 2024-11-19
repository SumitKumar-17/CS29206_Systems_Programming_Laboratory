// stack.c
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "stack.h"

stack initstack() {
    return NULL;
}

int emptystack(stack S) {
    return S == NULL;
}

int top(stack S) {
    if (emptystack(S)) {
        fprintf(stderr, "Error: Top of empty stack\n");
        exit(EXIT_FAILURE);
    }
    return S->data;
}

stack push(stack S, int value) {
    nodep new_node = (nodep)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = S;
    return new_node;
}

stack pop(stack S) {
    if (emptystack(S)) {
        fprintf(stderr, "Error: Pop from empty stack\n");
        exit(EXIT_FAILURE);
    }

    nodep temp = S;
    S = S->next;
    free(temp);
    return S;
}

void printstack(stack S) {
    while (S != NULL) {
        printf("%d ", S->data);
        S = S->next;
    }
    printf("\n");
}

stack destroystack(stack S) {
    while (S) {
        nodep temp = S;
        S = S->next;
        free(temp);
    }
    return NULL;
}
