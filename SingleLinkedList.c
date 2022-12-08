#include "SingleLinkedList.h"



errorState_t addNode(list_t *lptr, u32 index, bookData_t bookData)
{
	
	errorState_t state;
	// Validate params
	if (index > lptr->size)
	{
		state = NOT_ADDED;
	}
	else if (lptr == NULL)
	{
		state = NOT_ADDED;
	}
	// Adding new node
	else
	{
		node_t *newNode = (node_t *) malloc(sizeof(node_t));
		newNode->bookData = bookData;
		
		if (index == 0)
		{
			newNode->next = lptr->head;
			lptr->head = newNode;
		}
		else
		{	
			node_t *tempNode = lptr->head;
	
			s32 i;
			for (i = 0; i < index - 1; i++)
			{
				tempNode = tempNode->next;
			}
			
			newNode->next = tempNode->next;
			tempNode->next = newNode;	
		}
		lptr->size++;
		
		state = ADDED;
	}
	return state;
}
	
	
	
	
errorState_t removeNode(list_t *lptr, u32 index)
{
	errorState_t state;
	// Validate params
	if (index >= lptr->size)
	{
		state = NOT_DELETED;
	}
	else if (lptr == NULL)
	{
		state = NOT_DELETED;
	}
	// Remove node
	else
	{
		node_t *tempNode = lptr->head;
		if (index == 0)
		{
			if (lptr->size == 1)
			{
				lptr->head = NULL;
			}
			else
			{
				lptr->head = lptr->head->next;
			}
			free(tempNode);
		}
		else
		{
			s32 i;
			for (i = 0; i < index - 1; i++)
			{
				tempNode = tempNode->next;
			}
			node_t *tempNode2 = tempNode->next;
			tempNode->next = tempNode2->next;
			free(tempNode2);			
		}
		lptr->size--;
		state = DELETED;
	}
	return state;
}


void displayData(list_t *lptr)
{
	node_t *tempNode = lptr->head;
	u32 index = 1;
	while (tempNode != NULL)
	{
		printf("Book Number: %d\n", index);
		printf("Book Name: %s\n", tempNode->bookData.bookName);
		printf("Book Author: %s\n", tempNode->bookData.bookAuthor);
		printf("Price: %d\n", tempNode->bookData.bookPrice);
		tempNode = tempNode->next;
		index = index + 1;
		printf("--------------------------\n");
	}
}