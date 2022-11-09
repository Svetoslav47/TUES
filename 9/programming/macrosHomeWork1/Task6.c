#include <stdio.h>

#define swap_array(array, index1, index2)          \
    array[index1] = array[index1] + array[index2]; \
    array[j] = array[index1] - array[index2];      \
    array[index1] = array[index1] - array[index2]

#define swap(a, b, type) \
    type temp;           \
    temp = a;            \
    a = b;               \
    b = temp;

#define sort(array, size, operator, type)           \
    for (int i = 0; i < size - 1; i++)              \
        for (int j = 0; j < size - i - 1; j++)      \
            if (array[j] operator array[j + 1])     \
            {                                       \
                swap(array[j], array[j + 1], type); \
            }

int main()
{
    char arr[] = {'c', 'b', 'd', 't', 'h', 'z'};
    sort(arr, 6, >, char)

        for (int i = 0; i < 6; i++)
    {
        printf("%c, ", arr[i]);
    }
    return 0;
}
