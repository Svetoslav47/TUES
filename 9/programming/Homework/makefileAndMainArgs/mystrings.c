#include <stdio.h>
#include "mystrings.h"

int strlength(char *string)
{
    int counter = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}

void strconcat(char *string1, char *string2)
{
    int lenght = strlength(string1);

    for (int i = 0; string2[i] != '\0'; i++)
    {
        string1[lenght] = string2[i];
        lenght++;
    }

    string1[lenght] = '\0';
}

int strcmp(char *string1, char *string2)
{
    int string1Len = strlength(string1);
    int string2Len = strlength(string2);

    if (string1Len == string2Len)
    {
        for (int i = 0; i < string1Len; i++)
        {
            if (string1[i] < string2[i])
            {
                return -1;
            }
            else if (string1[i] > string2[i])
            {
                return 1;
            }
        }
        return 0;
    }

    int stringOneIsLonger = string1Len > string2Len ? 1 : 0;
    string1Len = string1Len < string2Len ? string1Len : string2Len;
    for (int i = 0; i < string1Len; i++)
    {
        if (string1[i] < string2[i])
        {
            return -1;
        }
        else if (string1[i] > string2[i])
        {
            return 1;
        }
    }
    if (stringOneIsLonger)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}