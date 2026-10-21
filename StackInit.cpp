#include <stdio.h>
#include <stdlib.h>
#include "hzhz.h"
#include "return.cpp"

#define SHRINK_FACTOR 4
#define EXPAND_FACTOR 2



errorReturn FillStack(Stack_t* const stk, size_t old_capacity, size_t new_capacity)
{
    if (stk == NULL)
    {
        CREATE_RETURNING_VALUE(NullStackPointer)
    }
    
    if(stk -> data == NULL)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    for(size_t i = new_capacity - old_capacity; i < new_capacity - 1; i++)
    {
        *(stk -> data + i) = 0x6767676767;
    } 
    
    *(stk -> data) = 0xDEAD;
    *(stk -> data + new_capacity - 1) = 0xDEAD;

    CREATE_RETURNING_VALUE(Success)
}

errorReturn StuckVerify(Stack_t* const stk)
{
    if (stk == NULL)
    {   
        CREATE_RETURNING_VALUE(NullStackPointer)                       
    }

    if (stk -> data == NULL)                
    {                              
        CREATE_RETURNING_VALUE(NullDataPointer)        
    } 

    if (stk -> capacity < stk -> size)
    {
        CREATE_RETURNING_VALUE(CapacityIsSmallerThanSize)
    }

    CREATE_RETURNING_VALUE(Success)
}


errorReturn StackDump(Stack_t* const stk)
{  
    
    if (stk == NULL)                
    {                              
        CREATE_RETURNING_VALUE(NullStackPointer)        
    }

    fprintf(stderr, "capacity = %lld\n", stk -> capacity);
    fprintf(stderr, "size = %lld\n", stk -> size);

    fprintf(stderr, "Data elements\n{\n");

    for (size_t i = 0; i < stk -> capacity; i++)
    {
        fprintf(stderr, "Index: %lld, Position: %p, Value: %f\n", 
            i, 
            stk -> data + i,  
            stk -> data[i]);
    }

    fprintf(stderr, "}\n");


    CREATE_RETURNING_VALUE(Success)
}


errorReturn StackInit(Stack_t* const stk, size_t const capacity)
{   
    if (stk == NULL)                
    {   
        CREATE_RETURNING_VALUE(NullStackPointer)  
    }

    if (capacity < stk -> size)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    stk -> data = (double*)calloc(capacity, sizeof(double*));
    
    if (stk -> data == NULL)                
    {                           
        CREATE_RETURNING_VALUE(NullStackPointer)  
    } 

    stk -> capacity = capacity;
    stk -> size = 1;

    FillStack(stk, capacity, capacity);
    // StackDump(stk);

    
    CREATE_RETURNING_VALUE(Success)  
}

errorReturn ResizeStack(Stack_t* const stk, size_t const new_capacity)
{
    if (stk == NULL)                
    {                             
        CREATE_RETURNING_VALUE(NullStackPointer)         
    }
    
    size_t old_capacity = stk -> capacity;

    double* temp_memory = (double*)realloc(stk -> data, new_capacity * sizeof(double));
    
    if (temp_memory == NULL)
    {
        CREATE_RETURNING_VALUE(CantAllocateMemory)  
    }

    if (stk -> data == NULL)                
    {                             
        CREATE_RETURNING_VALUE(NullDataPointer)      
    } 

    stk -> data = temp_memory;
    stk -> capacity = new_capacity;

    FillStack(stk, old_capacity, new_capacity);

    CREATE_RETURNING_VALUE(Success)
}


errorReturn StackExpand(Stack_t* const stk)
{
    if (stk == NULL)                
    {                            
        CREATE_RETURNING_VALUE(NullStackPointer)         
    }

    size_t new_capacity = (stk -> capacity) * EXPAND_FACTOR; 

    if (new_capacity < stk -> size)
    {
        CREATE_RETURNING_VALUE(CapacityIsSmallerThanSize) 
    }    

    
    ResizeStack(stk, new_capacity);

    stk -> capacity = new_capacity;
    CREATE_RETURNING_VALUE(Success) 
}

errorReturn StackShrink(Stack_t* const stk)
{
    if (stk == NULL)                
    {                              
        CREATE_RETURNING_VALUE(NullStackPointer)       
    }

    ResizeStack(stk, stk -> size);

    CREATE_RETURNING_VALUE(Success) 
}


errorReturn StackPush(Stack_t* const stk, const double element)
{
    if (stk == NULL)                
    {                              
        CREATE_RETURNING_VALUE(NullStackPointer)         
    }

    if(stk -> size == stk -> capacity - 1)
    {
        StackExpand(stk);
    }


    stk -> data[(stk -> size)++] = element;


    CREATE_RETURNING_VALUE(Success) 
}


errorReturn StackPop(Stack_t* const stk, double* const ret_element)
{
    if (stk == NULL)                
    {                             
        CREATE_RETURNING_VALUE(NullStackPointer)          
    }

    if (stk -> capacity == 2)
    {
        CREATE_RETURNING_VALUE(NoElementsLeft);
    }

    *ret_element = stk -> data[--(stk -> size)];

    stk -> data[(stk -> size)] = 0x6767676767;

    if(stk -> capacity > SHRINK_FACTOR && stk -> size <= stk -> capacity / SHRINK_FACTOR)
    {
        StackShrink(stk);
    }

    CREATE_RETURNING_VALUE(Success) 
}

errorReturn StackDestroy(Stack_t* const stk)
{
    if (stk == NULL)                
    {                           
        CREATE_RETURNING_VALUE(NullStackPointer)            
    }

    if (stk -> data == NULL)                
    {                             
        CREATE_RETURNING_VALUE(NullDataPointer)         
    } 

    free(stk -> data);

    CREATE_RETURNING_VALUE(Success) 

}