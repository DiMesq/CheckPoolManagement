#ifndef _XMALLOC_H_
#define _XMALLOC_H_



/**
 * Uses the same input as malloc, and has the same output, with the only 
 * difference being that it stops execution if some error occurred when
 * calling malloc.
 */
void* xmalloc(unsigned siz);

#endif
