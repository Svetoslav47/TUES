#include <stdio.h>
#include "mystrings.h"

void main(int argc, char **argv){
    for (int i = 1; i < argc; i++)
    {
        printf("%s is of length: %d\n", argv[i], strlength(argv[i]));
    }
}