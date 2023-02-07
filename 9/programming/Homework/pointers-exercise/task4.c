#include <stdio.h>

int compareasc(const void *a, const void *b);
int comparedesc(const void *a, const void *b);
void bubbleSort(int *arr, int n, int (*compare)(const void *, const void *));

void main()
{
    int arr[] = {5, 7, 8, 9, 1, 2, 3, 4, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n, compareasc);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n, comparedesc);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compareasc(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return 1;
    }
    else if (*(int *)a < *(int *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int comparedesc(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return -1;
    }
    else if (*(int *)a < *(int *)b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void bubbleSort(int *arr, int n, int (*compare)(const void *, const void *))
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (compare(&arr[j], &arr[j + 1]) > 0)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}