#include "header.h"

/** @file  search.c
 *  @brief Function used to search student record
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and search for particular student record given by user as input
 *  according to roll number or name and returns that nodes address.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    ST* address of node which has required students information
 */
ST *search(ST *Headptr)
{
	ST *temp1, *temp2;
	int choice, num;
	char tname[20];

	printf("1. Search by roll number\n2. Search by name\n");
	printf("\nEnter choice: ");
	scanf("%d", &choice);

	temp1 = Headptr;

	switch (choice) {
	case 1:
		printf("Enter roll number to search: ");
		scanf("%d", &num);
		while (temp1) {
			if (temp1->rollnum == num) {
				return temp1;
			}
			temp1 = temp1->next;
		}
		printf("Roll number not found\n");
		break;
	case 2:
		printf("Enter name to search: ");
		scanf("%s", tname);
		while (temp1) {
			if (strcmp(temp1->name, tname) == 0) {
				return temp1;
			}
			temp1 = temp1->next;
		}
		printf("Name not found\n");
		break;
	default:
		printf("Invalid case\n");
	}
	return 0;
}
