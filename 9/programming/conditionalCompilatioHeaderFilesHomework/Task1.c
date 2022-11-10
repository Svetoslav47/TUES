#include <stdio.h>
 
#define debug

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    #ifdef debug
        printf("Sorted array: \n");
        printArray(arr, n);
    #endif


    int sum = 0;
    #ifdef debug
            printf("Devisible by 3: \n");
    #endif
    for(int i = 0; i<n; i++){
        if(i % 3 == 0){
            #ifdef debug
                printf("%d\n", arr[i]);
            #endif
            sum += arr[i];
        }
    }
    
    return 0;
}