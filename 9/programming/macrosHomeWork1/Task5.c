#include <stdio.h>

#define swap(a, b, type) \
    type temp;           \
    temp = a;            \
    a = b;               \
    b = temp;
int main()
{
    float a = 10.6;
    float b = 6.7;
    swap(a, b, float);

    printf("A:%f B:%f", a, b);
}
