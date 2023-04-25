#include <stdio.h>

typedef union
{
    long odd;
    short even;
} Number;

int main()
{
    Number arr[10];

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            arr[i].even = i;
        }
        else
        {
            arr[i].odd = i;
        }
    }

    printf("Odd indexes: ");
    for (int i = 1; i < 10; i += 2)
    {
        printf("%ld ", arr[i].odd);
    }

    printf("\nEven indexes: ");
    for (int i = 0; i < 10; i += 2)
    {
        printf("%hd ", arr[i].even);
    }

    return 0;
}
