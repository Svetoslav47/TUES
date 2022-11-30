#include <stdio.h>
#define square(x) printf(#x)

void main(){
    int something = 5;
    square(something);
}