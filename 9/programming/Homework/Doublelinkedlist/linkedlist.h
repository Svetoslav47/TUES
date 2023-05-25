#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
#endif