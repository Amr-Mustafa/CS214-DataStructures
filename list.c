#include "SList.h"

/*
 * Preconditions:
 * 1) List is declared.
 *
 * Postconditions:
 * 1) List is initialized.
 */
void initializeList (SList* list)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 * 3) List is not full.
 *
 * Postconditions:
 * 1) Entry is added at the given index to the list.
 * 2) Size of the list is incremented.
 */
void insertEntry (int index, entryType* entry, SList* list)
{
	Node* pn = (Node*) malloc(sizeof(Node));
	pn->entry = entry;
	pn->next = NULL;


	if (list->size > 0) // list is not empty
	{
		if (index == 0) // insertion at the head
		{
			pn->next = list->head;
			list->head = pn;
		}
		else if (index > list->size - 1) // insertion at the tail
		{
			list->tail->next = pn;
			list->tail = pn;
		}
		else if (index > 0 && index < size) // insertion in the middle
		{
			Node* iterator = list->head;
			for (int i = 0; i < index - 1; i++)
				iterator = iterator->next;

			pn->next = iterator->next;
			iterator->next = pn;
		}
	}
	else // list is empty
	{
		list->head = pn;
		list->tail = pn;
	}

	list->size++;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 * 3) List is not full.
 *
 * Postconditions:
 * 1) Entry is added at the end of the list.
 * 2) Size of the list is incremented.
 */
void insertEntryAtEnd (entryType* entry, SList* list)
{
	insertEntry (list->size, entry, list);
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 * 3) List is not empty.
 * 4) 0 <= index <= size - 1.
 *
 * Postconditions:
 * 1) Entry at the given index is returned.
 */
entryType getEntry (int index, SList* list)
{
	Node* iterator = list->head;
	for (int i = 0; i < index; i++)
		iterator = iterator->next;
	return iterator->entry;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 * 3) List is not empty.
 * 4) 0 <= index <= size - 1.
 *
 * Postconditions:
 * 1) Given entry is set at the given index.
 */
void setEntry (int index, entryType* entry, SList* list)
{
	Node* iterator = list->head;
	for (int i = 0; i < index; i++)
		iterator = iterator->next;
	iterator->entry = entry;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 * 3) List is not empty.
 *
 * Postconditions:
 * 1) List is cleared and reset.
 */
void clearList (SList* list)
{
	Node* pn = list->head;
	while (pn) {
		pn = pn->next;
		free(list->head);
		list->head = pn;
	}
	list->tail = NULL;
	list->size = 0;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 *
 * Postconditions:
 * 1) A boolean value is returned indicating whether the list is empty or not.
 */
bool isEmpty (SList* list)
{
	return !(list->size);
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 * 3) List is not empty.
 * 4) 0 <= index <= size - 1.
 *
 * Postconditions:
 * 1) Entry at the given index is removed and returned.
 * 2) Size of list in decremented.
 */
entryType removeEntry (int index, SList* list)
{
	Node* iterator = list->head, pn = NULL;
	entryType e;

	if (index)
	{
		for (int i = 0; i < index - 1; i++)
			iterator = iterator->next;
		pn = iterator->next;
		iterator->next = pn->next;
		e = pn->entry;
	}
	else
	{
		e = list->head->entry;
		pn = list->head;
		list->head = pn->next;
	}

	free(pn);
	list->size--;
	return e;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 *
 * Postconditions:
 * 1) Size of the list is returned.
 */
int listSize (SList* list)
{
	return list->size;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 * 3) 0 <= startIndex <= endEndex <= size - 1.
 *
 * Postconditions:
 * 1) A SList is returned containing elements starting from startIndex through endEndex.
 */
SList subList (int startIndex, int endIndex, SList* list)
{
	SList sub;
	sub->size = endIndex - startIndex + 1;
	sub->head = list->head;
	sub->tail = list->head;

	for (int i = 0; i < startIndex; i++)
		sub->head = sub->head->next;

	for (int i = 0; i < endIndex; i++)
			sub->tail = sub->tail->next;

	return sub;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 * 3) List is not empty.
 *
 * Postconditions:
 * 1) A boolean is returned indicating whether the given entry is contained in the list or not.
 */
bool listContains (entryType* entry, SList* list)
{
	Node* iterator = list->head;
	for (int i = 0, n = list->size; i < n; i++)
	{
		if (iterator->entry == entry) return true; // Definitely not generic xD
	}

	return false;
}

/*
 * Preconditions:
 * 1) List is declared.
 * 2) List is initialized.
 *
 * Postconditions:
 * 1) A boolean is returned indicating whether the list is full or not.
 */
bool isFull (SList* list) {
	return false;
}
