#include <stdio.h>
#include <math.h>

void main(){
    long arr[] = {10,15,4,2,3};
    for (int i = 0; i < 5; i++){
        arr[i] = pow(arr[i], 4);
    }
}