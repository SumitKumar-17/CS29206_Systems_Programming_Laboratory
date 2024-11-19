#ifndef SOLN2_H
#define SOLN2_H

typedef struct
{
    int d, c1, c2, a0, a1;
} recrel2;

int findterm2(recrel2 *r, int n);

#endif
