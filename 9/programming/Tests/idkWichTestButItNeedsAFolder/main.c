#include <stdio.h>
#include "counter.h"

void main()
{
    for (int i = 0; i < 10; i++)
    {
        addToSum();
    }
    printf("%ld", sum);
}