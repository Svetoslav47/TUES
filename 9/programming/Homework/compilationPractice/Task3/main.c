#include <stdio.h>
#include "transformation.h"
#include <string.h> 

void main(){
    transformation result;
    result = transformString("12a7", 3);
    if(strcmp(result.error, "\0") == 0){
        printf("%ld", result.result);
    }else{
        printf("%s", result.error);
    }
}