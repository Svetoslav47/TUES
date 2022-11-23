#ifndef TransformGuard

#define TransformGuard
typedef struct {
    long result;
    char error[100];
} transformation;

transformation transformString(char* numberToConvert, int Size);
#endif

