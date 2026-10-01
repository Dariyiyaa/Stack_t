#include <stdio.h>
#include <stdlib.h>
#include "stack.cpp"

int    StackInit(Stack_t* stk, size_t capacity);
int    StackPush(Stack_t* stk, double value);
double StackPop(Stack_t* stk);
int    ResizeStack(Stack_t* stk, size_t new_capacity);
int    StackExpand(Stack_t* stk);
int    StackShrink(Stack_t* stk);
int    StackDump(Stack_t* stk);


int StackDump(Stack_t* stk)
{
    fprintf(stderr, "capacity = %lld\n", stk -> capacity);
    fprintf(stderr, "size = %lld\n", stk -> size);

    fprintf(stderr, "Data elements\n{\n");
    for (size_t i = 0; i < stk -> size; i++)
    {
        fprintf(stderr, "Index: %lld, Position: %p, Value: %f\n", i, stk -> data + i,  stk -> data[i]);
    }
    fprintf(stderr, "}\n");

    return 0;
}


int StackInit(Stack_t* stk, size_t capacity)
{
    stk -> data = (double*)calloc(capacity, sizeof(double*));
    stk -> capacity = capacity;
    stk -> size = 0;

    return 0;
} 


int ResizeStack(Stack_t* stk, size_t new_capacity)
{
    stk -> data = (double*)realloc(stk -> data, new_capacity * sizeof(double));
    stk -> capacity = new_capacity;

    return 0;
}


int StackExpand(Stack_t* stk)
{
    size_t new_capacity = (stk -> capacity) * 2; 
    stk -> capacity = new_capacity;
    ResizeStack(stk, new_capacity);

    return 0;
}

int StackShrink(Stack_t* stk)
{
    ResizeStack(stk, stk -> size);

    return 0;
}


int StackPush(Stack_t* stk, double value)
{

    if(stk -> size == stk -> capacity)
    {
        StackExpand(stk);
    }

    stk -> data[(stk -> size)++] = value;


    return 0;
}


double StackPop(Stack_t* stk)
{
    double ret_value = stk -> data[--(stk -> size)];

    if(stk -> capacity > 2 && stk -> size <= stk -> capacity / 2)
    {
        StackShrink(stk);
    }

    return ret_value;
}