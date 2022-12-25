#include "quadraticroots.h"
#include <math.h>
#include <stdio.h>

QuadraticRootsResult findRoots(double a, double b, double c)
{
    QuadraticRootsResult result;
    printf("a: %lf, b: %lf, c: %lf\n", a, b, c);
    double discriminant = (b * b) - 4 * a * c;
    printf("Discriminant: %lf\n", discriminant);

    if (discriminant < 0)
    {
        result.noRealRoots = 1;
    }
    else
    {
        result.noRealRoots = 0;
        result.x1 = (-b + sqrtl(discriminant)) / (2 * a);
        result.x2 = (-b - sqrtl(discriminant)) / (2 * a);
    }

    return result;
}