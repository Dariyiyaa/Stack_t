#include <stdio.h>
#include "StackInit.cpp"
#include "StackDump.cpp"

int main()
{
    Stack_t stk1 = {};
    size_t capacity = 5;

    StackInit(&stk1, capacity);

    StackPush(&stk1, 10);
    StackPush(&stk1, 20);
    StackPush(&stk1, 30);
    StackPush(&stk1, 40);
    StackPush(&stk1, 50);
    StackPush(&stk1, 60);
    StackPush(&stk1, 70);
    StackPush(&stk1, 80);
    StackPush(&stk1, 90);
    StackPush(&stk1, 100);

    
    StackDump(&stk1);

    printf("%f", StackPop(&stk1));
    
    

    // StackDestroy(stk1);
    
}