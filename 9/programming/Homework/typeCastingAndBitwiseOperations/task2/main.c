#include <stdio.h>

void switchLight(int lightNumber, char *lightsState);
void printLightsState();

void main()
{
    // each bit in the variable lightsState represents the state of a light
    char lightsState = 0;
    while (1)
    {
        printf("Enter command: ");
        char command = 0;
        scanf("%c", &command);
        if (command == 'q')
        {
            break;
        }
        else if (command == 's')
        {
            int lightNumber = 0;
            printf("Enter light number: ");
            scanf("%d", &lightNumber);
            switchLight(lightNumber, &lightsState);
        }
        else if (command == 'p')
        {
            printLightsState();
        }
    }
}

void switchLight(int lightNumber, char *lightsState)
{
    // change the state of the bit at position lightNumber
    // in the variable lightsState
}

void printLightsState()
{
    // print the state of each light
}
