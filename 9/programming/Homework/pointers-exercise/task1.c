#include <stdio.h>

void main()
{
    int a;
    int b;
    int *pA = &a;
    int *pB = &b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("a:\n %p : %d\n", pA, *pA);
    printf("b:\n %p : %d\n", pB, *pB);
}