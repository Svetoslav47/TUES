#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum education
{
    undeducated,
    primary,
    secondary,
    unviersity
};

enum work_status
{
    unemployed,
    employed
};

enum family_status
{
    single,
    married
};

struct person
{
    long egn;
    char names[255];
    int age;
    enum education education;
};

