#include <stdio.h>

#define debug(x) printf("%s : %d is on line %d in %s", #x, x, __LINE__, __FILE__)

int main(){
    int var = 10;
    debug(var);
    return 0;
}