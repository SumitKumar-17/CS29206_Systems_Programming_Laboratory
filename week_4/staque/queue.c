// queue.c
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "queue.h"

queue initqueue() {
    queue Q;
    Q.front = Q.back = NULL;
    return Q;
}

int emptyqueue(queue Q) {
    return Q.front == NULL;
}

int front(queue Q) {
    if (emptyqueue(Q)) {
        fprintf(stderr, "Error: Front of empty queue\n");
        exit(EXIT_FAILURE);
    }
    return Q.front->data;
}

queue enqueue(queue Q, int value) {
    nodep new_node = (nodep)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (emptyqueue(Q)) {
        Q.front = Q.back = new_node;
    } else {
        Q.back->next = new_node;
        Q.back = new_node;
    }

    return Q;
}

queue dequeue(queue Q) {
    if (emptyqueue(Q)) {
        fprintf(stderr, "Error: Dequeue from empty queue\n");
        exit(EXIT_FAILURE);
    }

    nodep temp = Q.front;
    Q.front = Q.front->next;
    free(temp);

    if (Q.front == NULL) {
        Q.back = NULL; // Queue is now empty
    }

    return Q;
}

void printqueue(queue Q) {
    while (Q.front != NULL) {
        printf("%d ", Q.front->data);
        Q.front = Q.front->next;
    }
    printf("\n");
}

queue destroyqueue(queue Q) {
    while (Q.front) {
        nodep temp = Q.front;
        Q.front = Q.front->next;
        free(temp);
    }
    Q.back = NULL;
    return Q;
}
