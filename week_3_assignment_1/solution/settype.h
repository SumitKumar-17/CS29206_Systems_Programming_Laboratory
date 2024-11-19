#ifndef _SETUTILS_SETTYPE_H
#define _SETUTILS_SETTYPE_H

/* Define the data type for sets of numbers */
typedef int *numset;

/* Constructors and destructors */
extern numset setinit ( int ) ;
extern numset setrand ( int ) ;
extern numset setrandsize ( int , int ) ;
extern numset setdestroy ( numset ) ;

#endif
