#include <stdio.h>

#define arrSize 5

int main(){
    #if defined arrSize && arrSize > 1 && arrSize < 10
        int arr[arrSize];
        for(int i = 0; i < arrSize; i++){
            int total = 1;
            for (int j = 0; j < i; j++)
            {
                total *= 2;
            }
            arr[i] = total;
        }
    #else
        printf("size is not supported or size is bigger than 10")
    #endif
}