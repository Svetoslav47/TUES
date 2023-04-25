#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull add(ull a, ull b)
{
    return a + b;
}

ull reduce(ull arr[], ull size, ull (*func)(ull, ull), ull initial)
{
    ull result = initial;
    for (int i = 0; i < size; i++)
    {
        result = (*func)(result, arr[i]);
    }
    return result;
}

int main()
{
    ull arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ull result = reduce(arr, 10, add, 0);
    printf("%llu\n", result);
    return 0;
}
