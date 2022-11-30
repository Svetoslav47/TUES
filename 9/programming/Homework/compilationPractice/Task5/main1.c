#include <stdio.h>

void main(int argc, char **argv){
    printf("%d\n", argc);
    for(int i = 0; 1; i++){
        printf("%s\n", argv[i]);
    }
}