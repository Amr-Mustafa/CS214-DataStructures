#include "Scheduler.h"
#include "Queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * -> Preconditions:
 *    1. arrivalTime >= 0.
 *    2. burstTime > 0.
 * -> Postconditions:
 *    1. A pointer to a process with the given arguments is returned.
 */
Process* createProcess (int arrivalTime, int burstTime, char processName[]) {
    Process* p     = (Process*) malloc(sizeof(Process));
    p->arrivalTime = arrivalTime;
    p->burstTime   = burstTime;
    strcpy(p->processName, processName);
    return p;
}

/**
 * -> Preconditions:
 *    1. pScheduler is not NULL.
 *    2. configFile is not NULL.
 * -> Postconditions:
 *    1. Scheduler referenced by pScheduler is initialized with the given time quantum.
 */
void initializeScheduler(Scheduler* pScheduler, char* configFile) {
    
    pScheduler->currentTime = 0, pScheduler->timeQuantum = 1;
    
    /* open config file */
    FILE* inputFile = fopen(configFile, "r");
    if (!inputFile) exit(1);
    
    /* prepare buffer */
    char* line = malloc(sizeof(30));
    if (!line) exit(1);
    
    /* read the timeQuantum */
    fgets(line, 30,inputFile);
    char string[40];
    sscanf(line, "%s %s %s %s %d", string, string, string, string, &pScheduler->timeSlots);
    
    /* read each process */
    int i = 0;
    while(fgets(line, 30,inputFile)) {
        int arrivalTime, burstTime;
        char processName[5];
        
        sscanf(line, "%s %d %d", processName, &arrivalTime, &burstTime);
        
        Process* p = createProcess(arrivalTime, burstTime, processName);

        pScheduler->processList[i++] = *p;
    }
    
    pScheduler->processes = i;
    initializeQueue(&pScheduler->processQueue);
}

/**
 * -> Preconditions:
 *    1. pScheduler is not NULL.
 *    2. pProcess is not NULL.
 * -> Postconditions:
 *    1. Process referenced by pProcess is enqueud in the processes queue of the scheduler referened by pScheduler.
 */
void scheduleProcess (Scheduler* pScheduler, Process* pProcess) {
    enqueue(&pScheduler->processQueue, (void*) pProcess, sizeof(Process));
}

/**
 * -> Preconditions:
 *    1. pScheduler is not NULL.
 * -> Postconditions:
 *    1. Process at the head of the processQueue of the Scheduler referenced by pScheduler is served.
 */
Process* serveProcess (Scheduler* pScheduler) {
    void* process = dequeue(&pScheduler->processQueue);
    if(--((Process*) process)->burstTime == 0) {
        return (Process*) process;
    }
    return (Process*) process;
}
