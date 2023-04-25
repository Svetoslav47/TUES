#include <stdio.h>
#include <stdlib.h>

void main()
{
    int rows = 0, cols = 0;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int **arr = (int **)calloc(rows, sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        *(arr + i) = (int *)calloc(cols, sizeof(int));
        if (*(arr + i) == NULL)
        {
            printf("Memory allocation failed");
            return;
        }
    }

    {
        int count = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                *(*(arr + i) + j) = count++;
            }
        }
    }

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
    }

    for (int i = 0; i < rows; i++)
    {
        free(*(arr + i));
    }
    free(arr);
}
