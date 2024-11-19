#ifndef _SETUTILS_SETOPS_H
#define _SETUTILS_SETOPS_H

extern void setprint ( numset ) ;
extern int setsize ( numset ) ;
extern numset setaddelt ( numset , int ) ;
extern numset setdelelt ( numset , int ) ;
extern numset setunion ( numset , numset ) ;
extern numset setintersection ( numset , numset ) ;

#endif
