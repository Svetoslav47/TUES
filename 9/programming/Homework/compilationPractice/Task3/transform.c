#include "transformation.h"
#include <string.h>

transformation transformString(char* numberToConvert, int size){
    transformation result;
    result.result = 0;
    strcpy(result.error, "\0");
    for(int i = 0; i < size; i++){
        if(numberToConvert[i] == '\0'){
            break;
        }
        if(numberToConvert[i] >= '0' && numberToConvert[i] <= '9'){
            result.result = result.result*10 + numberToConvert[i] - '0';
        }else{
            result.result = 0;
            strcpy(result.error, "Invalid Input string");
            break;
        }
    }
    return result;
}