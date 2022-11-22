#include <stdio.h>

#define addAndRaiseToTheSecond(A, B) ((A) + (B)) * ((A) + (B))

void main(){
    printf("%d", addAndRaiseToTheSecond(2, 3));
}