
#include "math.h"

int factoriel(int x)
{
    int p = 1;
    for(int i=x; i>0; i--)
    {
        p *= i;
    }
    return p;
}