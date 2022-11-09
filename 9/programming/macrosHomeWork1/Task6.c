#include <stdio.h>

#define swap_array(array, index1, index2)          \
    array[index1] = array[index1] + array[index2]; \
    array[j] = array[index1] - array[index2];      \
    array[index1] = array[index1] - array[index2]

#define swap(a, b) \
    a = a + b;     \
    b = a - b;     \
    a = a - b

#define compare(array, i, j, operator) array[i] operator array[j]

#define sort(array, size, operator)                 \
    for (int i = 0; i < size - 1; i++)              \
        for (int j = 0; j < size - i - 1; j++)      \
            if (compare(array, j, j + 1, operator)) \
            {                                       \
                swap(array[j], array[j + 1]);       \
                \ 
                                                 \
            }

int main()
{
    int arr[] = {5, 7, 9, 3, 4, 2};
    sort(arr, 6, >)

        for (int i = 0; i < 6; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}
