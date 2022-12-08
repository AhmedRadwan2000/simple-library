#include "SingleLinkedList.h"
 
bookData_t bookData;
list_t newList = {0, 0};
u32 currentBooks;
 
void main(void)
{

while (1)
{
	printf("\n");
	printf("To Add a book                          press '1'\n");
	printf("To delete a book                       press '2'\n");
	printf("To view available books                press '3'\n");
	printf("To see number of available books       press '4'\n");
	printf("To exit the program                    press '5'\n");
	
	
	// store option
	printf("\n");
	
	printf("Your Option = ");
	u8 option;
	
	restart:
	scanf("%d", &option);
	getchar(); // clear buffer
	
	printf("\n");
	if (option == 1)
	{	
		printf("Enter the book name: ");
		gets(bookData.bookName);
		
		printf("Enter the book Author: ");
		gets(bookData.bookAuthor);
		
		printf("Enter the book price: ");
		scanf("%d", &bookData.bookPrice);
		
		while (bookData.bookPrice <= 0)
		{
			printf("Wrong Price try again: ");
			scanf("%d", &bookData.bookPrice);
		}
		
		addNode(&newList, currentBooks, bookData);
		currentBooks = currentBooks + 1;
		
		printf("\nBook added successfully :)\n");
		printf("--------------------------\n");
	}
	else if (option == 2)
	{
		printf("Enter the book number: ");
		
		u32 bookNumber;
		scanf("%d", &bookNumber);
		
		if (removeNode(&newList, bookNumber - 1) != DELETED)
		{
			printf("Invalid index try again :(\n");
		}
		else
		{
			printf("Book deleted successfully :)\n");
		}
		printf("--------------------------\n");
		
		currentBooks = currentBooks - 1;
	}
	else if (option == 3)
	{
		displayData(&newList);
	}
	else if (option == 4)
	{
		printf("No. of available books = %d\n", newList.size);
		printf("--------------------------\n");
	}
	else if (option == 5)
	{
		break;
	}
	else
	{
		printf("Invalid option try again: ");
		goto restart;
	}
}
 
}