#include "bitstate.h"
#include <stdio.h>

void main()
{
    while (1)
    {
        printf("chose command\n");
        printf("1 - set bit\n");
        printf("2 - unset bit\n");
        printf("3 - toggle bit\n");
        printf("4 - check specific bit\n");
        printf("5 - check all bits\n");
        printf("6 - exit\n");

        int command = 0;
        scanf("%d", &command);
        int bit = 0;
        switch (command)
        {
        case 1:
            printf("enter bit number:\n");
            bit = 0;
            scanf("%d", &bit);

            setBit(bit);
            break;
        case 2:
            printf("enter bit number:\n");
            bit = 0;
            scanf("%d", &bit);
            unsetBit(bit);
            break;
        case 3:
            printf("enter bit number:\n");
            bit = 0;
            scanf("%d", &bit);
            toggleBit(bit);
            break;
        case 4:
            printf("enter bit number:\n");
            bit = 0;
            scanf("%d", &bit);
            printf("bit %d state is %d\n", bit, isBitSet(bit));
            break;
        case 5:
            printf("all bits state:\n");

            for (int i = 0; i < 32; i++)
            {
                printf("bit %d state is %d\n", i, isBitSet(i));
            }

            break;
        case 6:
            return;

        default:
            printf("wrong command\n");
            break;
        }
    }
}