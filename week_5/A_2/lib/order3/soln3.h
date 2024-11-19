#ifndef SOLN3_H
#define SOLN3_H

typedef struct
{
    int d, c1, c2, c3, a0, a1, a2;
} recrel3;

int findterm3(recrel3 *r, int n);

#endif
