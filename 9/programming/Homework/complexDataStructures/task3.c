#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[16];
    int number;
    double grade;
};

void add_student(struct Student **students, int *count)
{
    // увеличаване на размера на масива с 1
    *students = realloc(*students, (*count + 1) * sizeof(struct Student));

    printf("Enter student name (up to 15 characters): ");
    scanf("%s", (*students)[*count].name);

    printf("Enter student number: ");
    scanf("%d", &(*students)[*count].number);

    printf("Enter student grade: ");
    scanf("%lf", &(*students)[*count].grade);

    (*count)++;
}

void print_students(struct Student *students, int count)
{
    printf("\nAll students:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s, number: %d, grade: %.2lf\n", i + 1, students[i].name, students[i].number, students[i].grade);
    }
}

int main()
{
    struct Student *students = NULL;
    int count = 0;
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Add student\n");
        printf("2. Print all students\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student(&students, &count);
            break;
        case 2:
            print_students(students, count);
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 3);
}