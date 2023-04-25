#include <stdio.h>
#include <stdlib.h>

#include "dynamicArray.h"

#define ASSERT_ALLOC_MEMORY(PTR)          \
  if ((PTR) == NULL)                      \
  {                                       \
    printf("Error allocating memory \n"); \
    exit(1);                              \
  }

static void resize(DynamicArray *arr, int newsize)
{
  if (newsize > arr->capacity)
  {
    arr->capacity *= 2;
    arr->buffer = (int *)realloc(arr->buffer, sizeof(int) * arr->capacity);
    ASSERT_ALLOC_MEMORY(arr->buffer);
  }
  else if (newsize <= arr->capacity / 2)
  {
    arr->capacity /= 2;
    arr->buffer = (int *)realloc(arr->buffer, sizeof(int) * arr->capacity);
    ASSERT_ALLOC_MEMORY(arr->buffer);
  }
  arr->size = newsize;
}

DynamicArray init(int capacity)
{
  DynamicArray arr;
  arr.capacity = capacity;
  arr.size = 0;
  arr.buffer = (int *)calloc(arr.capacity, sizeof(int));

  return arr;
}

void pushBack(DynamicArray *arr, double value)
{
  int newsize = arr->size + 1;
  resize(arr, newsize);
  arr->buffer[newsize - 1] = value;
}

double popBack(DynamicArray *arr)
{
  if (arr->size == 0)
  {
    return -1;
  }
  int result = arr->buffer[arr->size - 1];
  arr->buffer[arr->size - 1] = 0;
  int newsize = arr->size - 1;
  resize(arr, newsize);

  return result;
}

void pushFront(DynamicArray *arr, double value)
{
  int newsize = arr->size + 1;
  resize(arr, newsize);
  for (int i = newsize - 1; i > 0; i--)
  {
    arr->buffer[i] = arr->buffer[i - 1];
  }
  arr->buffer[0] = value;
}

double popFront(DynamicArray *arr)
{
  if (arr->size == 0)
  {
    return -1;
  }
  int result = arr->buffer[0];
  for (int i = 0; i < arr->size - 1; i++)
  {
    arr->buffer[i] = arr->buffer[i + 1];
  }
  arr->buffer[arr->size - 1] = 0;
  int newsize = arr->size - 1;
  resize(arr, newsize);

  return result;
}

void setElement(DynamicArray *arr, int index, double value)
{
  arr->buffer[index] = value;
}

double getElement(DynamicArray *arr, int index)
{
  return arr->buffer[index];
}

void insertElement(DynamicArray *arr, int index, double value)
{
  int newsize = arr->size + 1;
  resize(arr, newsize);
  for (int i = newsize - 1; i > index; i--)
  {
    arr->buffer[i] = arr->buffer[i - 1];
  }
  arr->buffer[index] = value;
}

double popAtIndex(DynamicArray *arr, int index)
{
  if (arr->size == 0)
  {
    return -1;
  }
  int result = arr->buffer[index];
  for (int i = index; i < arr->size - 1; i++)
  {
    arr->buffer[i] = arr->buffer[i + 1];
  }
  arr->buffer[arr->size - 1] = 0;
  int newsize = arr->size - 1;
  resize(arr, newsize);

  return result;
}

int findElement(DynamicArray *arr, double value)
{
  for (int i = 0; i < arr->size; i++)
  {
    if (arr->buffer[i] == value)
    {
      return i;
    }
  }
  return -1;
}

void release(DynamicArray *arr)
{
  free(arr->buffer);
  arr->buffer = NULL;
  arr->capacity = 0;
  arr->size = 0;
}