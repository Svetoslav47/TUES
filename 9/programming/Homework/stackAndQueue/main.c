#include "stack.h"
#include "queue.h"
#include <stdio.h>

int main()
{
    Stack stack = initStack();
    Queue queue = initQueue();
    int i;
    for (i = 0; i < 10; i++)
    {
        pushStack(&stack, i);
        pushQueue(&queue, i);
    }
    printf("Stack: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", popStack(&stack));
    }
    printf("\n");
    printf("Queue: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", popQueue(&queue));
    }
    printf("\n");
    return 0;
}