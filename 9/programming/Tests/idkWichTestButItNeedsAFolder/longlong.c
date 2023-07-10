#include <stdio.h>
#include <limits.h>

void main()
{
    long long a = 0x1234567890abcdefLL;
    // print the info about the the type long: size (in bits), min and max values
    printf("Size of long long: %d bits (%d bytes). Min value: %lld. Max value: %lld.\n", sizeof(long long) * CHAR_BIT, sizeof(long long), LLONG_MIN, LLONG_MAX);
}