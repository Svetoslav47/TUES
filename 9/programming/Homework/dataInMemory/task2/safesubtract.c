#include <stdio.h>
#include <limits.h>
#include "safeint.h"

void main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <number1> <number2>", argv[0]);
    }
    else
    {
        struct SafeResult xSafe = safestrtoint(argv[1]);
        struct SafeResult ySafe = safestrtoint(argv[2]);
        if (xSafe.errorflag == 1 || ySafe.errorflag == 1)
        {
            printf("Error: Overflow");
            return;
        }
        int x = xSafe.value;
        int y = ySafe.value;

        struct SafeResult result = safesubtract(x, y);
        if (result.errorflag == 0)
        {
            printf("%d - %d = %d", x, y, result.value);
        }
        else
        {
            printf("Error: Overflow");
        }
    }
}