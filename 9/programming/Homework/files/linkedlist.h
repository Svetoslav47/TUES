#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "book.h"

struct ListNode
{
    Book *value;
    struct ListNode *next;
};

typedef struct
{
    int size;
    struct ListNode *head;
} LinkedList;

LinkedList init();

struct ListNode *get(LinkedList *list, int index);

void push(LinkedList *list, int index, Book *value);
void pushback(LinkedList *list, Book *value);
void pushfront(LinkedList *list, Book *value);

Book *pop(LinkedList *list, int index);
Book *popfront(LinkedList *list);
Book *popback(LinkedList *list);

void set(LinkedList *list, int index, Book *value);

// For homework
void release(LinkedList *list);

#endif