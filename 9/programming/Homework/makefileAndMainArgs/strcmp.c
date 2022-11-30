#include <stdio.h>
#include "mystrings.h"

void main(int argc, char **argv){
    if(argc == 3){
        printf("%d\n", strcmp(argv[1], argv[2]));
    }
}