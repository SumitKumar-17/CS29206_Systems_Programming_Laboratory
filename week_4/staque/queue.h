// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include "defs.h"


typedef struct {
    nodep front;
    nodep back;
} queue;

queue initqueue();
int emptyqueue(queue);
int front(queue);
queue enqueue(queue, int);
queue dequeue(queue);
void printqueue(queue);
queue destroyqueue(queue);

#endif // QUEUE_H
