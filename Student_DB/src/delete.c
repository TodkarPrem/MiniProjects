#include "header.h"

/** @file  delete.c
 *  @brief Function used to delete student records from database
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and deletes single node or entire database according to user's
 *  input. Delete's record without memory leakage.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    Void
 */
void delete(ST **HeadPtr)
{
	ST *tmp1, *tmp2;
	int ch, n;
	char tname[20];

	printf("1. Delete record by roll number\n2. Delete record by name\n");
	printf("3. Delete all records\n\n");
	printf("Enter choice: ");
	scanf("%d", &ch);

	tmp1 = *HeadPtr;

	switch (ch) {
	case 1:
		printf("Enter roll number to delete: ");
		scanf("%d", &n);
		while (tmp1) {
			if (tmp1->rollnum == n) {
				if (*HeadPtr == tmp1) {
					*HeadPtr = tmp1->next;
					free(tmp1);
					return;
				} else {
					tmp2->next = tmp1->next;
					free(tmp1);
					return;
				}
			}
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		printf("Roll number not found\n");
		break;
	case 2:
		printf("Enter name to delete: ");
		scanf("%s", tname);
		while (tmp1) {
			if (strcmp(tmp1->name, tname) == 0) {
				if (*HeadPtr == tmp1) {
					*HeadPtr = tmp1->next;
					free(tmp1);
					return;
				} else {
					tmp2->next = tmp1->next;
					free(tmp1);
					return;
				}
			}
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		printf("Name not found\n");
		break;
	case 3:
		while (*HeadPtr) {
			tmp1 = *HeadPtr;
			*HeadPtr = tmp1->next;
			free(tmp1);
		}
		break;
	default:
		printf("Invalid case\n");
	}
}
