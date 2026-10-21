#include <stdio.h>
#include "hzhz.h"
#include "StackInit.cpp"
#include "assert.h"

int main()
{
    
    putchar('\n');
    assert(stdout);

    Stack_t stk1 = {};
    size_t capacity = 5;

    struct errorReturn ret_val = {};
    
    double a = 0;

    putchar('\n');
    
    ReturnValueCheck(&(ret_val = StackInit(&stk1, capacity)));

    putchar('o');

    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPush(&stk1, 10)));

    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPush(&stk1, 20)));
    
    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPush(&stk1, 30)));
    
    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPush(&stk1, 40)));

    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPush(&stk1, 50)));
    
    StackDump(&stk1);
    
    ReturnValueCheck(&(ret_val = StackPush(&stk1, 60)));

    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));
    
    StackDump(&stk1);

    
    ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));
    
    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));
    
    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));
    
    StackDump(&stk1);

    ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));
    
    StackDump(&stk1);
    
    ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));


    StackDump(&stk1);

    // double a = 0;
    // ReturnValueCheck(&(ret_val = StackPush(&stk1, 60)));
    // ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));
    // ReturnValueCheck(&(ret_val = StackPush(&stk1, 70)));
    // ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));
    // ReturnValueCheck(&(ret_val = StackPush(&stk1, 70)));
    // ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));
    // ReturnValueCheck(&(ret_val = StackPush(&stk1, 70)));
    // ReturnValueCheck(&(ret_val = StackPop(&stk1, &a)));


    // printf("%f", a);
    

    StackDestroy(&stk1);
    
}