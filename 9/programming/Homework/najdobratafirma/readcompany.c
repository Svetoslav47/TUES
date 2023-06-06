#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee
{
    char name[100];
    int numberOfSlaves;
    struct employee **slaves;
} Employee;

Employee *createEmployee(char *name)
{
    Employee *employee = (Employee *)malloc(sizeof(Employee));
    strcpy(employee->name, name);
    employee->numberOfSlaves = 0;
    employee->slaves = NULL;
    return employee;
}

void addSlave(Employee *employee, Employee *slave)
{
    employee->numberOfSlaves++;
    employee->slaves = (Employee **)realloc(employee->slaves, employee->numberOfSlaves * sizeof(Employee *));
    employee->slaves[employee->numberOfSlaves - 1] = slave;
}

void printEmployee(Employee *employee, int depth)
{
    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }
    printf("%s\n", employee->name);
    for (int i = 0; i < employee->numberOfSlaves; i++)
    {
        printEmployee(employee->slaves[i], depth + 1);
    }
}

void deserializeEmployee(Employee *employee, FILE *file)
{
    fread(employee->name, sizeof(char[100]), 1, file);
    fread(&employee->numberOfSlaves, sizeof(int), 1, file);

    employee->slaves = (Employee **)malloc(employee->numberOfSlaves * sizeof(Employee *));
    for (int i = 0; i < employee->numberOfSlaves; i++)
    {
        employee->slaves[i] = (Employee *)malloc(sizeof(Employee));
        deserializeEmployee(employee->slaves[i], file);
    }
}

void main()
{
    FILE *file = fopen("company.bin", "rb");
    Employee *ceo = (Employee *)malloc(sizeof(Employee));
    deserializeEmployee(ceo, file);
    printEmployee(ceo, 0);
    fclose(file);
}