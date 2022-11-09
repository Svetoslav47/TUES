#include <stdio.h>

#define swap(a, b, type) \
    a = a + b;           \
    b = a - b;           \
    a = a - b
int main()
{
    // this works for every type because you can use + with everything (chars just use ascii code)
    float a = 10.6;
    float b = 6.7;
    swap(a, b, "int");

    printf("A:%f B:%f", a, b);
}