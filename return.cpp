// #ifdef RETURN

// #define RETURN


#include <stddef.h>
#include <stdio.h>
#include "hzhz.h"


void ReturnValueCheck(struct errorReturn* ret_val);


void ReturnValueCheck(struct errorReturn* ret_val)
{
    switch(ret_val -> error)
    {
        case Success:
            break;
        
        case NullStackPointer:
            fprintf(stderr, "Failed to make a pointer at Stack at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
        
        case NullDataPointer:
            fprintf(stderr, "Failed to make a pointer at Data at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;

        case CantAllocateMemory:
            fprintf(stderr, "Failed to allocate memory at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
        
        case CapacityIsSmallerThanSize:
            fprintf(stderr, "The Capacity is smaller than the Size at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;

        case NoElementsLeft:
            fprintf(stderr, "Nothing left to pop at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
            
        case  ArgumentsHasntMatched:
            fprintf(stderr, "Wrong input from File at line %d, in file %s", ret_val -> line, ret_val -> file_name);
            break;

        default:
            break;
    }

    return;
}

// #endif