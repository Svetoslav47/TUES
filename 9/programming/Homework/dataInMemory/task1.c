#include <limits.h>
#include <stdio.h>

void main(){
    printf("%-10s | %-10s | %-4s | %-20s | %-20s | %s\n", "name", "how print", "size", "signed min", "signed max", "unsigned max");
    // print a table for every whole number type
    printf("%-10s | %-10s | %-4d | %-20d | %-20d | %u\n", "char", "%c", sizeof(char), CHAR_MIN, CHAR_MAX, UCHAR_MAX);
    printf("%-10s | %-10s | %-4d | %-20d | %-20d | %u\n", "short", "%hd", sizeof(short), SHRT_MIN, SHRT_MAX, USHRT_MAX);
    printf("%-10s | %-10s | %-4d | %-20d | %-20d | %u\n", "int", "%d", sizeof(int), INT_MIN, INT_MAX, UINT_MAX);
    printf("%-10s | %-10s | %-4d | %-20ld | %-20ld | %lu\n", "long", "%ld", sizeof(long), LONG_MIN, LONG_MAX, ULONG_MAX);
    printf("%-10s | %-10s | %-4d | %-20lld | %-20lld | %llu\n", "long long", "%lld", sizeof(long long), LLONG_MIN, LLONG_MAX, ULLONG_MAX);
}