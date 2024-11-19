#include<stdio.h>
#include "soln2.h"

int findterm2(recrel2 *r,int n){
    if(n==0) return r->a0;
    else if(n==1) return r->a1;
    else {
        int result=r->c1*findterm2(r,n-1)+r->c2*findterm2(r,n-2)+r->d;
        return result;
    }
}