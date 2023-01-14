#ifndef PROCESSES_H
#define PROCESSES_H


struct process
{
    unsigned int processID;
    char processName[30];
};

void createNewProcess(char processName[30]);
void stopProcess(int processId);
void listAllProcesses();


#endif
