#include<stdio.h>
#include "soln3.h"

int findterm3(recrel3 *r,int n){
    if(n==0) return r->a0;
    else if(n==1) return r->a1;
    else if(n==2) return r->a2;
    else {
        int result=(r->c1)*findterm3(r,n-1)+(r->c2)*findterm3(r,n-2)+(r->c3)*findterm3(r,n-3)+r->d;
        return result;
    }
}