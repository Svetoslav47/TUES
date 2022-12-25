#include <stdio.h>
#include <stdlib.h>
#include "quadraticroots.h"

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Error: not enough arguments.\n");
        return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    QuadraticRootsResult roots = findRoots(a, b, c);
    if (roots.noRealRoots)
    {
        printf("The equation has no real roots.\n");
    }
    else
    {
        printf("The roots of the equation are %lf and %lf.\n", roots.x1, roots.x2);
    }

    return 0;
}