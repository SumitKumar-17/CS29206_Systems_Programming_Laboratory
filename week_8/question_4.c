#include <stdio.h>
void f ( int n, int x )
{
if ( n > 0 ) f (n - x, x);
}
int main ()
{
int x;
printf("x = "); scanf("%d", &x);
f(100,x);
}
