#include <stdio.h>
#include <stdlib.h>

struct node
{
    long data;
    struct node *next;
};

typedef struct
{
    long int count;
    struct node *head;
} linkedList;

void initList(linkedList *list);
void pushFront(linkedList *list, long data);
long popFront(linkedList *list);
long getByIndex(linkedList *list, long index);
void printLinkedList(linkedList *list);

void initList(linkedList *list)
{
    list->count = 0;
    list->head = NULL;
}

void pushFront(linkedList *list, long data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

long popFront(linkedList *list)
{
    if (list->count == 0)
    {
        return -1;
    }
    else
    {
        struct node *temp = list->head;
        long data = temp->data;
        list->head = temp->next;
        free(temp);
        list->count--;
        return data;
    }
}

long getByIndex(linkedList *list, long index)
{
    if (index >= list->count)
    {
        return -1;
    }
    else
    {
        struct node *temp = list->head;
        for (long i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}

void printLinkedList(linkedList *list)
{
    struct node *temp = list->head;
    while (temp != NULL)
    {
        printf("%ld ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    linkedList list = {0, NULL};
    pushFront(&list, 1);
    pushFront(&list, 2);
    pushFront(&list, 3);

    printLinkedList(&list);

    printf("%ld\n", getByIndex(&list, 1));

    popFront(&list);
    popFront(&list);

    printLinkedList(&list);
}