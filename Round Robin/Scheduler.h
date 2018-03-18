#ifndef Scheduler_H_
#include "Queue.h"
#define PROCESS_H_
#define LIMIT 100

typedef struct {
	int arrivalTime;
	int burstTime;
	char processName[5];
} Process;

typedef struct {
    int timeQuantum, currentTime, timeSlots, processes;
    Process processList[LIMIT];
    Queue processQueue;
} Scheduler;

Process* createProcess       (int, int, char[]);
void     initializeScheduler (Scheduler*, char*);
void     scheduleProcess     (Scheduler*, Process*);
Process* serveProcess        (Scheduler*);

#endif
