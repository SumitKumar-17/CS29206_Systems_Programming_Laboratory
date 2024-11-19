// #indef SETTYPE_H
#define  SETTYPE_H

//the dtaa type numset is defined
typedef int *numset;

// nitialize a numset S to the empty subset of U
numset setinit(int N);

// Initialize a numset S to a random subset of U
numset setrand(int N);


// numset setrandsize(int N,int t);

//Make S an invalid set
numset setdestroy(numset S);