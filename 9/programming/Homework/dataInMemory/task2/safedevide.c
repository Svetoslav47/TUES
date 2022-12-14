#include <stdio.h>
#include "safeint.h"

void main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <number1> <number2>", argv[0]);
    }else{
        struct SafeResult xSafe = safestrtoint(argv[1]);
        struct SafeResult ySafe = safestrtoint(argv[2]);
        if(xSafe.errorflag == 0 || ySafe.errorflag == 0){
            printf("Error: Overflow");
            return;
        }
        int x = xSafe.value;
        int y = ySafe.value;
        
        struct SafeResult result = safedivide(x, y);
        if (result.errorflag == 1)
        {
            printf("%d / %d = %d", x, y, result.value);
        }else{
            printf("Error: Overflow");
        }
    }
}