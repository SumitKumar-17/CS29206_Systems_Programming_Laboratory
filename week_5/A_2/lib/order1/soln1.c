#include<stdio.h>

#include "soln1.h"

int findterm1(recrel1 *r,int n){
    if(n==0) return r->a0;
    else if(n==1) return r->a1;
    else {
        int result=r->c1*findterm1(r,n-1)+r->d;
        return result;
    }
}