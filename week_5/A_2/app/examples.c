#include<stdio.h>
#include "../lib/order1/soln1.h"
#include "../lib/order2/soln2.h"
#include "../lib/order3/soln3.h"

int main(){
    int n;
    printf("n=");
    scanf("%d",&n);
    
    recrel1 hanoi_relation={1,2,0,1};
    int hanoi_result=findterm1(&hanoi_relation,n);
    printf("ToH(%d) =%d\n",n,hanoi_result);

    recrel2 fibonacci_relation_plus_5={-5,1,1,5,6};
    int fibonacci_result_plus_5_result=findterm2(&fibonacci_relation_plus_5,n);
    printf("Fib(%d) + 5=%d\n",n,fibonacci_result_plus_5_result);

    recrel3 fibonacci_relation_2={0,0,2,1,0,1,1};
    int fibonacci_result_2=findterm3(&fibonacci_relation_2,n);
    printf("Fib(%d)=%d\n",n,fibonacci_result_2);
}