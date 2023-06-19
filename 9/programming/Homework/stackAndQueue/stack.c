#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack initStack()
{
    Stack stack;
    stack.top = NULL;
    stack.size = 0;
    return stack;
}

int popStack(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    int data = stack->top->data;
    struct StackNode *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

void pushStack(Stack *stack, int data)
{
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}
