#include <stdio.h>

#define arrSize 5

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
#if defined arrSize && arrSize > 1 && arrSize < 10
    int arr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        int total = 1;
        for (int j = 0; j < i; j++)
        {
            total *= 2;
        }
        arr[i] = total;
    }
#if defined _WIN32
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
#elif defined __linux__
    for (int i = 1; i < arrSize; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
#elif defined __APPLE__
    for (int i = 0; i < arrSize - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < arrSize; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
#else
    for(int i = 0; i < arrSize/2; i++){
        swap(&arr[i], &arr[n-i]);
    }
#endif
#else
    printf("size is not supported or size is bigger than 10")

#endif
}