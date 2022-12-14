#include "safeint.h"
#include <limits.h>

struct SafeResult safeadd(int x, int y)
{
    struct SafeResult result;
    if (x > 0 && y > 0 && x > INT_MAX - y)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else if (x < 0 && y < 0 && x < INT_MIN - y)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else
    {
        result.errorflag = 1;
        result.value = x + y;
    }
    return result;
}

struct SafeResult safesubtract(int x, int y)
{
    struct SafeResult result;
    if (x > 0 && y < 0 && x > INT_MAX + y)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else if (x < 0 && y > 0 && x < INT_MIN + y)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else
    {
        result.errorflag = 1;
        result.value = x - y;
    }
    return result;
}

struct SafeResult safemultiply(int x, int y)
{
    struct SafeResult result;
    if (x > 0 && y > 0 && x > INT_MAX / y)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else if (x < 0 && y < 0 && x < INT_MAX / y)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else if (x > 0 && y < 0 && x > INT_MIN / y)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else if (x < 0 && y > 0 && x < INT_MIN / y)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else
    {
        result.errorflag = 1;
        result.value = x * y;
    }
    return result;
}

struct SafeResult safedivide(int x, int y)
{
    struct SafeResult result;
    if (y == 0)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else if (x == INT_MIN && y == -1)
    {
        result.errorflag = 0;
        result.value = 0;
    }
    else
    {
        result.errorflag = 1;
        result.value = x / y;
    }
    return result;
}

struct SafeResult safestrtoint(char *str)
{
    struct SafeResult result;
    int i = 0;
    int sign = 1;
    int value = 0;
    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            result.errorflag = 0;
            result.value = 0;
            return result;
        }
        if (value > INT_MAX / 10 || (value == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
        {
            result.errorflag = 0;
            result.value = 0;
            return result;
        }
        value = value * 10 + (str[i] - '0');
        i++;
    }
    result.errorflag = 1;
    result.value = sign * value;
    return result;
}