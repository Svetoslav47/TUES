#include <stdio.h>

unsigned char lights = 237; // 11101101
void printLightsState();
void turnOffLightsWithEvenNumber();

int main()
{
    printLightsState();
    turnOffLightsWithEvenNumber();
    printf("%d\n", lights);
}

void printLightsState()
{
    printf("Lights state: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("light %d is %d\n", i + 1, (lights >> i) & 1);
    }
    printf("\n");
}

void turnOffLightsWithEvenNumber()
{
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            //& - bitwise AND
            //~ - bitwise NOT
            // move the one to the i-th position
            // flip the bits so its something like 11110111
            //& with the lights variable
            // this will turn off the i-th light
            // because the i-th bit of the lights variable will be 0
            // and AND gives 0 if any of the bits are 0
            lights &= ~(1 << i);
        }
    }
}