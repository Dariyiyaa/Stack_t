#ifndef HZCH_H

#define HZCH_H

#include <stdio.h>
#include <stddef.h>
#include "error.h"


struct Stack_t
{
    int cannary_open = 0xDEAD;
    double* data;
    size_t size;
    size_t capacity;
    int cannary_close = 0xDEAD;
}; 


errorReturn StackInit(Stack_t* stk, size_t capacity);
errorReturn StackPush(Stack_t* stk, double value);
errorReturn StackPop(Stack_t* stk, double* ret_element);
errorReturn ResizeStack(Stack_t* stk, size_t new_capacity);
errorReturn StackExpand(Stack_t* stk);
errorReturn StackShrink(Stack_t* stk);
errorReturn StackDump(Stack_t* stk);
errorReturn StackDestroy(Stack_t* stk);
errorReturn StuckVerify(Stack_t*  stk);
errorReturn FillStack(Stack_t* const stk, size_t capacity);
errorReturn FillStack(Stack_t* const stk, size_t old_capacity, size_t new_capacity);


#endif