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

void serializeEmployee(Employee *employee, FILE *file)
{
    fwrite(employee->name, sizeof(char[100]), 1, file);
    fwrite(&employee->numberOfSlaves, sizeof(int), 1, file);

    for (int i = 0; i < employee->numberOfSlaves; i++)
    {
        serializeEmployee(employee->slaves[i], file);
    }
}

int main()
{
    Employee *ceo = createEmployee("CEO");

    Employee *manager1 = createEmployee("Manager 1");
    addSlave(ceo, manager1);
    Employee *manager2 = createEmployee("Manager 2");
    addSlave(ceo, manager2);
    Employee *manager3 = createEmployee("Manager 3");
    addSlave(ceo, manager3);

    Employee *employee1 = createEmployee("Employee 1");
    addSlave(manager1, employee1);
    Employee *employee2 = createEmployee("Employee 2");
    addSlave(manager1, employee2);
    Employee *employee3 = createEmployee("Employee 3");
    addSlave(manager1, employee3);

    Employee *employee4 = createEmployee("Employee 4");
    addSlave(manager2, employee4);
    Employee *employee5 = createEmployee("Employee 5");
    addSlave(manager2, employee5);
    Employee *employee6 = createEmployee("Employee 6");
    addSlave(manager2, employee6);

    Employee *employee7 = createEmployee("Employee 7");
    addSlave(manager3, employee7);
    Employee *employee8 = createEmployee("Employee 8");
    addSlave(manager3, employee8);
    Employee *employee9 = createEmployee("Employee 9");
    addSlave(manager3, employee9);

    printEmployee(ceo, 0);

    FILE *file = fopen("company.bin", "wb");
    serializeEmployee(ceo, file);
    fclose(file);
}
