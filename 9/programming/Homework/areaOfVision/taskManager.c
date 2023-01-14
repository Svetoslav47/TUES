#include "processes.h"
#include <stdio.h>

void main(){
    while (1)
    {
        printf("Enter command: \n");
        printf("1 - create new process\n");
        printf("2 - stop process\n");
        printf("3 - list all processes\n");
        printf("4 - exit\n");
        int command;
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            printf("Enter process name: ");
            char processName[30];
            scanf("%s", processName);
            createNewProcess(processName);
            break;
        case 2:
            printf("Enter process id: ");
            int processId;
            scanf("%d", &processId);
            stopProcess(processId);
            break;
        case 3:
            listAllProcesses();
            break;
        case 4:
            return;
        }
    }
    
}