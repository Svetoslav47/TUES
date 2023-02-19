#include <stdio.h>

int lenOfStr(char str[])
{
    char *ptr = str;
    int len = 0;
    while (*(ptr++) != '\0')
    {
        len++;
    }
    return len;
}

void main()
{
    printf("the string is %d chars long", lenOfStr("test"));
}