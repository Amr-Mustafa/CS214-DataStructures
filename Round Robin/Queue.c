#include <stdlib.h>
#include <string.h>
#include "Queue.h"

typedef struct {
	void* pData;
	int bytes;
} DataCapsule;

typedef struct node {
	DataCapsule* pDataCapsule;
	struct node* pNextNode;
	struct node* pPrevNode;
} Node;

struct queue {
	int size;
	Node* pHead;
	Node* pTail;
};

/**
 * -> Preconditions:
 *    NONE.
 * -> Postconditions:
 *    1. A pointer to an initialized Node is returned.
 */
Node* createNode () {
	Node* pNode = (Node*) malloc(sizeof(Node));
	
	pNode->pNextNode = NULL, pNode->pPrevNode = NULL;
	pNode->pDataCapsule = (DataCapsule*) malloc(sizeof(DataCapsule));
	pNode->pDataCapsule->pData = NULL;
	pNode->pDataCapsule->bytes = 1;
	
	return pNode;
}

/**
 * -> Preconditions:
 *    1. pQueue is not NULL.
 * -> Postconditions:
 *    1. Queue referenced by pQueue is initialized.
 */
void initializeQueue (Queue* pQueue) {
    pQueue->pStructQueue = (struct queue*) malloc(sizeof(struct queue));
    pQueue->pStructQueue->pHead = NULL, pQueue->pStructQueue->pTail = NULL, pQueue->pStructQueue->size = 0;
}

/**
 * -> Preconditions:
 *    1. pQueue is not NULL.
 *    2. Queue referenced by pQueue is initialized.
 *    3. Queue referenced by pQueue is not empty.
 * -> Postconditions:
 *    1. A pointer to the data served is returned.
 *    2. Size of the queue referenced by pQueue is decremented.
 */
void* dequeue (Queue* pQueue) {
    void* pData = malloc(sizeof(pQueue->pStructQueue->pHead->pDataCapsule->bytes));
    memcpy(pData, pQueue->pStructQueue->pHead->pDataCapsule->pData, pQueue->pStructQueue->pHead->pDataCapsule->bytes);
    
    free(pQueue->pStructQueue->pHead->pDataCapsule->pData);
    free(pQueue->pStructQueue->pHead->pDataCapsule);
    
    Node* pNode = pQueue->pStructQueue->pHead;
    
    pQueue->pStructQueue->pHead = pQueue->pStructQueue->pHead->pPrevNode;
    pQueue->pStructQueue->size--;
    
    if (!pQueue->pStructQueue->size) pQueue->pStructQueue->pTail = NULL;
    
    free(pNode);
    return pData;
}

/**
 * -> Preconditions:
 *    1. pQueue is not NULL.
 *    2. Stack referenced by pQueue is initialized.
 *    3. pData is not NULL.
 *    4. bytes > 0.
 * -> Postconditions:
 *    1. Data referenced by data pointer is enqueued into the queue referenced by pQueue.
 *    2. Size of the queue referenced by pQueue is incremented.
 */
void enqueue (Queue* pQueue, void* pData, int bytes) {
    void* pMData = malloc(sizeof(bytes));
    memcpy(pMData, pData, bytes);
    
    Node* pNode = createNode();
    pNode->pDataCapsule->pData = pMData, pNode->pDataCapsule->bytes = bytes;
    
    pNode->pNextNode = pQueue->pStructQueue->pTail;
    
    if (pQueue->pStructQueue->size) pQueue->pStructQueue->pTail->pPrevNode = pNode;
    else {
        pQueue->pStructQueue->pHead = pNode;
    }
    
    pQueue->pStructQueue->pTail = pNode;
    pQueue->pStructQueue->size++;
}

/**
 * -> Preconditions:
 *    1. pQueue is not NULL.
 *    2. Queue referenced by pQueue is initialized.
 * -> Postconditions:
 *    1. An integer value indicating whether the queue is empty or not is returned. (1 -> queue empty, 0 -> queue is not empty)
 */
int isEmpty (Queue* pQueue) {
	return !pQueue->pStructQueue->size;
}
