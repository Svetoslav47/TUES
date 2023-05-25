#include <stdio.h>
#include <stdlib.h>

struct node
{
    double data;
    struct node *next;
    struct node *prev;
};

typedef struct
{
    struct node *head;
    struct node *tail;
    int size;
} List;

List init();
void push(List *list, double data, int index);
void pushFront(List *list, double data);
void pushBack(List *list, double data);
double pop(List *list, int index);
double popFront(List *list);
double popBack(List *list);
double get(List *list, int index);
void release(List *list);

List init()
{
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return list;
}

void push(List *list, double data, int index)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->size == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else if (index == 0)
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    else if (index == list->size - 1)
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    else if (index < list->size / 2)
    {
        struct node *temp = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    else
    {
        struct node *temp = list->tail;
        for (int i = list->size; i > index; i--)
        {
            temp = temp->prev;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
    list->size++;
}

void pushFront(List *list, double data)
{
    push(list, data, 0);
}

void pushBack(List *list, double data)
{
    push(list, data, list->size - 1);
}

double pop(List *list, int index)
{
    double data;
    if (list->size == 0)
    {
        printf("List is empty\n");
        return 0;
    }
    else if (index == 0)
    {
        popFront(list);
    }
    else if (index == list->size - 1)
    {
        popBack(list);
    }
    else if (index < list->size / 2)
    {
        struct node *temp = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        data = temp->next->data;
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }
    else
    {
        struct node *temp = list->tail;
        for (int i = list->size; i > index; i--)
        {
            temp = temp->prev;
        }
        data = temp->data;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    list->size--;
    return data;
}

double popFront(List *list)
{
    struct node *temp;
    temp = list->head;
    double data = temp->data;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
    list->size--;
    return data;
}

double popBack(List *list)
{
    struct node *temp;
    temp = list->tail;
    double data = temp->data;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);
    list->size--;
    return data;
}

double get(List *list, int index)
{
    if (list->size == 0)
    {
        printf("List is empty\n");
        return 0;
    }
    else if (index == 0)
    {
        return list->head->data;
    }
    else if (index == list->size - 1)
    {
        return list->tail->data;
    }
    else if (index < list->size / 2)
    {
        struct node *temp = list->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    else
    {
        struct node *temp = list->tail;
        for (int i = list->size; i > index; i--)
        {
            temp = temp->prev;
        }
        return temp->data;
    }
}

void release(List *list)
{
    struct node *temp = list->head;
    while (temp != NULL)
    {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}