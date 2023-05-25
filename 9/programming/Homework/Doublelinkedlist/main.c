#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void printArray(List *list)
{
    struct node *temp = list->head;
    while (temp != NULL)
    {
        printf("%lf\n", temp->data);
        temp = temp->next;
    }
}

void main()
{
    List list = init();
    pushFront(&list, 1);
    pushFront(&list, 2);
    pushFront(&list, 3);

    pushBack(&list, 4);
    pushBack(&list, 5);
    pushBack(&list, 6);

    push(&list, 7, 0);
    push(&list, 8, 3);

    popFront(&list);
    popBack(&list);

    printArray(&list);

    printf("popFront: %lf\n", popFront(&list));
    printf("popBack: %lf\n", popBack(&list));
    printf("pop: %lf\n", pop(&list, 2));

    printArray(&list);

    release(&list);
}