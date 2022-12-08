#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"



typedef struct
{
	u8 bookName[100];
	u8 bookAuthor[100];
	s32  bookPrice;
}bookData_t;



typedef struct node_t
{
	bookData_t bookData;
	struct node_t *next;
}node_t;




typedef struct list_t
{
	u32 size;
	struct node_t *head;
}list_t;


typedef enum
{
	ADDED,
	NOT_ADDED,
	DELETED,
	NOT_DELETED
}errorState_t;

errorState_t addNode(list_t *ptr, u32 index, bookData_t bookData);
errorState_t removeNode(list_t *ptr, u32 index);
void displayData(list_t *lptr);


#endif