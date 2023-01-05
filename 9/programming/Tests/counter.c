#include <stdio.h>

long sum = 0;

static int getNextOddNumber()
{
    static int currentNumber = 1;
    int result = currentNumber;
    currentNumber += 2;
    return result;
}

void addToSum()
{
    sum += getNextOddNumber();
}