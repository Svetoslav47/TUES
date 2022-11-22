#include <stdio.h>

#define get_bigger(x, y) x > y ? x : y

int main(){
    printf("%d", get_bigger(4, 5));
    return 0;
}