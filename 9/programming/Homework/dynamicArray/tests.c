#include <stdio.h>
#include "dynamicArray.h"

void printdynarr(DynamicArray *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        int currel = getElement(arr, i);
        printf("%d ", currel);
    }
    printf("\n");
}

int main(void)
{
    DynamicArray arr = init(3);
    printdynarr(&arr);

    pushBack(&arr, 4);
    pushBack(&arr, 7);
    pushBack(&arr, 5);
    pushBack(&arr, 3);

    printdynarr(&arr);

    return 0;
}