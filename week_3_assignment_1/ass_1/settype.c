#include<stdio.h>
#include<stdlib.h>
#include "settype.h"

// the function setinit implementation
numset setinit(int N){
   numset S;
   S=(int *)calloc((N+1),sizeof(int *));
   S[0]=N;
   return S;
}


//the function setrand implementation
numset setrand(int N){
     numset S=setinit(N);
     for(int i=1;i<N;i++){
         if(rand()%2==0){
             S[i]=1;
         }
     }
     return S;
}


//the setdestroy function implementation 
numset setdestroy(numset S){
    free(S);
    return S;
}

