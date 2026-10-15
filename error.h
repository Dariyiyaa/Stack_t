#include <stdio.h>

enum Error
{
    Success                     =   0,
    NullStackPointer            =   1,
    NullDataPointer             =   2,
    CantAllocateMemory          =   3,
    CapacityIsSmallerThanSize   =   4, 
    // WrongDataFile               =   5,

};


struct errorReturn
{
    Error error;
    int line;
    const char* file_name;
};
