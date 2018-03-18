#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct {
	struct queue* pStructQueue;
} Queue;

void  initializeQueue (Queue*);
void* dequeue    (Queue*);
void  enqueue    (Queue*, void*, int);
int   isEmpty    (Queue*);

#endif
