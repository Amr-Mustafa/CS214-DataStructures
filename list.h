#ifndef SLIST_H_
#define SLIST_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int coefficient;
	int power;
} PolynomialTerm;

typedef PolynomialTerm entryType;

typedef struct node
{
	entryType entry;
	struct node* next;
} Node;

typedef struct
{
	Node* head;
	Node* tail;
	int size;
} SList;

void      initializeList   (SList*);                                                  // Θ(1)
void      insertEntry      (int, entryType*, SList*);                                 // O(n)
void      insertEntryAtEnd (entryType*, SList*);                                      // Θ(1)
entryType getEntry         (int, SList*);                                             // O(n)
void      setEntry         (int, entryType*, SList*);                                 // O(n)
void      clearList        (SList*);                                                  // Θ(n)
bool      isEmpty          (SList*);                                                  // Θ(1)
entryType removeEntry      (int, SList*);                                             // O(n)
int       listSize         (SList*);                                                  // Θ(1)
SList     subList          (int, int, SList*);                                        // O(n)
bool      listContains     (entryType*, SList*, bool (*comp) (entryType, entryType)); // O(n)
bool      isFull           (SList*);                                                  // Θ(1)

#endif
