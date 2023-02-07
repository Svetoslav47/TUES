#include <stdio.h>

int compareasc(const void *a, const void *b);
int comparedesc(const void *a, const void *b);

void main()
{
    int a = 5;
    int b = 10;
    printf("a = %d, b = %d\n", a, b);
    printf("compareasc: %d\n", compareasc(&a, &b));
    printf("comparedesc: %d\n", comparedesc(&a, &b));
}

int compareasc(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return 1;
    }
    else if (*(int *)a < *(int *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int comparedesc(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return -1;
    }
    else if (*(int *)a < *(int *)b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}