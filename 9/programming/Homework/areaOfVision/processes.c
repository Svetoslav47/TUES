#include "processes.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>

static struct process processes[5];
static int processesCount = 0;

static unsigned int getNextProccessId(){
    static unsigned int currentId = 0;
    if (currentId == UINT_MAX)
    {
        currentId = 0;
        return 0;
    }
    
    currentId++;
    return currentId;
}

void createNewProcess(char processName[30]){
    struct process newProcess;
    newProcess.processID = getNextProccessId();
    strcpy(newProcess.processName, processName);
    processes[processesCount] = newProcess;
    processesCount++;

    printf("Process with id %u created\n", newProcess.processID);
}

void stopProcess(int processId){
    int processIndex = -1;
    for (int i = 0; i < processesCount; i++)
    {
        if (processes[i].processID == processId)
        {
            processIndex = i;
            break;
        }
    }
    if (processIndex == -1)
    {
        printf("Process with id %u not found\n", processId);
        return;
    }
    //remove the process from the array and rearrange the array
    for (int i = processIndex; i < processesCount - 1; i++)
    {
        processes[i] = processes[i + 1];
        processesCount--;
    }
}

void listAllProcesses(){
    printf("All processes:\n");
    for (int i = 0; i < processesCount; i++)
    {
        printf("Process with id %u and name %s\n", processes[i].processID, processes[i].processName);
    }
}