#include <stdio.h>
#include "mystrings.h"

void main(int argc, char **argv)
{
    if (strlength(argv[1]) > 49 || strlength(argv[2]) > 49)
    {
        printf("one of the names is longer than 50 chars long");
        return;
    }
    char string1[101] = "";
    strconcat(string1, argv[1]);
    strconcat(string1, argv[2]);
    if (argc == 3)
    {
        printf("concat is %s\n", string1);
    }
}