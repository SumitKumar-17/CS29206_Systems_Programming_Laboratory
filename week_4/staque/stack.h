// stack.h
#ifndef STACK_H
#define STACK_H

#include "defs.h"

typedef nodep stack;

stack initstack();
int emptystack(stack);
int top(stack);
stack push(stack, int);
stack pop(stack);
void printstack(stack);
stack destroystack(stack);

#endif // STACK_H
