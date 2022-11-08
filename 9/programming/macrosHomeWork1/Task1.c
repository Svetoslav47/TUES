#include <stdio.h>

#define defineArr int arr[5] = {1,2,3,4,5};
#define printArr for(int i = 0; i < 5; i++) printf("%d\n", arr[i]);

int main(){
    defineArr
    printArr
    return 0;
}