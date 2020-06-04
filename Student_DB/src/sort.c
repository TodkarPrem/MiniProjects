#include "header.h"

/** @file  sort.c
 *  @brief Function used to sort student database
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and sorts entire student database according to users choice.
 *  User can sort database according to roll number, name or marks.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    Void
 */
void sort(ST **Headptr)
{
	ST *temp1, *temp2, *temp, var;
	int cnt, i, j;

	printf("1. Sort record by roll number\n2. Sort record by name\n");
	printf("3. Sort record by average marks\n\n");
	printf("Enter choice: ");
	scanf("%d", &i);

	temp1 = *Headptr;
	cnt = count(*Headptr);

	switch (i) {
	case 1:
		for (i = 0; i < cnt - 1; i++) {
			temp2 = temp1->next;
			for (j = i + 1; j < cnt; j++) {
				if (temp1->rollnum > temp2->rollnum) {
					var = *temp1;
					*temp1 = *temp2;
					*temp2 = var;

					temp = temp1->next;
					temp1->next = temp2->next;
					temp2->next = temp;
				}
				temp2 = temp1->next;
			}
			temp1 = temp1->next;
		}
		return;
	case 2:
		for (i = 0; i < cnt - 1; i++) {
			temp2 = temp1->next;
			for (j = i + 1; j < cnt; j++) {
				if (strcmp(temp1->name, temp2->name) > 0) {
					var = *temp1;
					*temp1 = *temp2;
					*temp2 = var;

					temp = temp1->next;
					temp1->next = temp2->next;
					temp2->next = temp;
				}
				temp2 = temp1->next;
			}
			temp1 = temp1->next;
		}
		return;
	case 3 :
		for (i = 0; i < cnt - 1; i++) {
			temp2 = temp1->next;
			for (j = i + 1; j < cnt; j++) {
				if (temp1->avg > temp2->avg) {
					var = *temp1;
					*temp1 = *temp2;
					*temp2 = var;

					temp = temp1->next;
					temp1->next = temp2->next;
					temp2->next = temp;
				}
				temp2 = temp1->next;
			}
			temp1 = temp1->next;
		}
		return;
	default:
		printf("Invalid choice\n");
	}
}
