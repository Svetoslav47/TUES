#include <stdio.h>
#include <stdlib.h>

#include "dynamicArray.h"

void print_donors(DynamicArray *arr)
{
    printf("Current donors:\n");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d. %lf\n", i + 1, getElement(arr, i));
    }
}

int main()
{
    int capacity = 10;
    DynamicArray donors = init(capacity);

    int choice;
    double id;

    while (1)
    {
        printf("\n1. Add donor\n2. Remove donor\n3. List donors\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the EGN of the donor: ");
            scanf("%lf", &id);
            pushBack(&donors, id);
            break;
        case 2:
            printf("Enter the EGN of the donor to remove: ");
            scanf("%lf", &id);
            int index = findElement(&donors, id);
            if (index != -1)
            {
                popAtIndex(&donors, index);
            }
            else
            {
                printf("Donor with EGN %d not found.\n", id);
            }
            break;
        case 3:
            print_donors(&donors);
            break;
        case 4:
            release(&donors);
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
