#ifndef DYNAMICARR_H
#define DYNAMICARR_H

typedef struct
{
    int *buffer;
    unsigned int capacity;
    unsigned int size;
} DynamicArray;

DynamicArray init(int capacity);
void pushBack(DynamicArray *arr, double value);
double popBack(DynamicArray *arr);

void pushFront(DynamicArray *arr, double value);
double popFront(DynamicArray *arr);

void setElement(DynamicArray *arr, int index, double value);
double getElement(DynamicArray *arr, int index);

void insertElement(DynamicArray *arr, int index, double value);
double popAtIndex(DynamicArray *arr, int index);

int findElement(DynamicArray *arr, double value);

void release(DynamicArray *arr);

#endif