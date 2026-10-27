#ifndef ERROR

#define ERROR

#include <stdio.h>
#include "stddef.h"



#define CREATE_RETURNING_VALUE(errorCode){  \
    struct errorReturn ret_val= {};         \
    ret_val.error = errorCode;              \
    ret_val.line = __LINE__;                \
    ret_val.file_name = __FILE_NAME__;      \
    return ret_val;                         \
                                            \
}

void ReturnValueCheck(struct errorReturn* ret_val);

enum Error
{
    //StackErrors

    Success                     =   0,
    NullStackPointer            =   1,
    NullDataPointer             =   2,
    CantAllocateMemory          =   3,
    CapacityIsSmallerThanSize   =   4, 
    NoElementsLeft              =   5,

    //FileErrors

    ArgumentsHasntMatched       =   6,
    NullFilePointer             =   7,

    //AssErrors


};


struct errorReturn
{
    Error error;
    int line;
    const char* file_name;
};

#endif