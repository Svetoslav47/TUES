#ifndef STACK_H
#define STACK_H

struct StackNode
{
    int data;
    struct StackNode *next;
};

typedef struct
{
    struct StackNode *top;
    int size;
} Stack;

Stack initStack();
int popStack(Stack *stack);
void pushStack(Stack *stack, int data);

#endif