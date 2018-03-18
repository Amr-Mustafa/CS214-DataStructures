#include <stdio.h>
#include <stdlib.h>
#include "Scheduler.h"
#include "Queue.h"

int main (void) {
    
    Scheduler scheduler;
    initializeScheduler(&scheduler, "input.txt");
    
    Process* process = NULL;
    
    /* iterate over all time slots */
    for (int t = 0, m = scheduler.timeSlots; t < m; t++) {
        
        /* schedule all processes that have their arrivalTime equal to the currentTime */
        for (int i = 0, n = scheduler.processes; i < n; i++) {
            if (scheduler.processList[i].arrivalTime == scheduler.currentTime) 
                scheduleProcess(&scheduler, &scheduler.processList[i]);
        }
        
        /* reschedule last-served process */
        if (process && process->burstTime) scheduleProcess(&scheduler, process);
        
        /* if after the processQueue is empty then the processor is idle for this time slot */
        if (isEmpty(&scheduler.processQueue)) printf("idle (%d-->%d)\n", t, t+1);
        
        else {
            process = serveProcess(&scheduler);
            printf("%s   (%d-->%d) ", process->processName, t, t+1);
            
            /* process finished execution */
            if (!process->burstTime) { 
                printf("%s aborts\n", process->processName);
            }
            else puts("");
        }
        
        /* increment the scheduler clock */
        scheduler.currentTime++;
    }
    
    puts("stop");
}
