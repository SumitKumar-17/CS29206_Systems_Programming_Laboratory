// #indef SETOPS_H
#define  SETOPS_H
#include "settype.h"

// Print the elements of a numset S
void setprint(numset S);

//Return the size (number of elements) in the numset S, that is, t :=|S|
int setsize(numset S);

// Add the element i to the numset S, that is, T := S   {⋃i}
numset setaddelt(numset S,int i);

//  Remove the element i from the numset S, that is, T := S – {i}
numset setdelelt(numset S,int i);

// Set T := A   ⋃B
numset setunion(numset A,numset B);

// Set T := A   ⋂
numset setintersection(numset A,numset B);


// #endif


