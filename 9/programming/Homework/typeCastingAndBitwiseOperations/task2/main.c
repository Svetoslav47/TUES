#include <stdio.h>

char switchLight(int lightNumber, char lightsState);
void printLightsState(char lightsState);

void main()
{
    // each bit in the variable lightsState represents the state of a light
    char lightsState = 0;
    while (1)
    {
        printf("Enter command: ");
        printf("s - switch light, p - print lights state, q - quit:");
        char command = 0;
        scanf("%c", &command);
        if (command == 'q')
        {
            break;
        }
        else if (command == 's')
        {
            int lightNumber = 0;
            printf("Enter light number(1-8): ");
            scanf("%d", &lightNumber);
            lightsState = switchLight(lightNumber - 1, lightsState);
        }
        else if (command == 'p')
        {
            printLightsState(lightsState);
        }
    }
}

char switchLight(int lightNumber, char lightsState)
{
    return lightsState ^ (1 << lightNumber);
}

void printLightsState(char lightsState)
{
    for (size_t i = 0; i < 8; i++)
    {
        printf("light %d state is %d\n", i + 1, (lightsState >> i) & 1);
    }
}
