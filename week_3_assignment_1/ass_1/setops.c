#include <stdio.h>
#include<stdlib.h>
#include "setops.h"
#include "settype.h"

//the implementation of the setprint fucntion
void setprint(numset S){
    printf("{");
    for(int i=1;i<S[0]+1;i++){
        if(S[i]==1) printf("%d,",i);
    }
    printf("}");
    printf("\n");
}

//the implemenatation of the setsize function returntype int
int setsize(numset S){
    int count=0;
    for(int i=0;i<S[0]+1;i++){
        if(S[i]==1) count++;
    }
    return count;
}


//the implementation of the setaddelt function retrun type numset
numset setaddelt(numset S,int i){
    S[i]=1;
    return S;
}

//the implementation of the setdelelt function retrun type numset
numset setdelelt(numset S,int i){
    S[i]=0;
    return S;
}

//the implemebtation of the setunion function which finds the union of two sets
numset setunion(numset A,numset B){
    numset C=setinit(A[0]);
    for(int i=1;i<A[0];i++){
            if(A[i]==1||B[i]==1){
                C=setaddelt(C,i);
            }
    }
    return C;
}


//the implemebtation of the setunion function which finds the intersection of two sets
numset setintersection(numset A,numset B){
    numset C=setinit(A[0]);
    for(int i=1;i<A[0];i++){
            if(A[i]==1&&B[i]==1){
                C=setaddelt(C,i);
            }
    }
    return C;
}