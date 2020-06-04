#include "header.h" 

/** @file   add.c
 *  @brief  Function used to add student record
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and add node to store student record according to student's
 *  roll number. Student records are stored in ascending order.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    Void
 */
void add(ST **HeadPtr)
{
	ST *temp1, *temp2;

	temp1 = (ST *)malloc(sizeof(ST));
	printf("Enter roll number, name & average marks of student:\n");
	scanf("%d %s %f", &temp1->rollnum, temp1->name, &temp1->avg);

	if (*HeadPtr == 0 || (*HeadPtr)->rollnum > temp1->rollnum) {
		temp1->next = *HeadPtr;
		*HeadPtr = temp1;
	} else {
		temp2 = *HeadPtr;
		while (temp2) {
			if (temp2->next == 0 || temp2->next->rollnum > 
					temp1->rollnum) {
				temp1->next = temp2->next;
				temp2->next = temp1;
				break;
			}
			temp2=temp2->next;
		}
	}
}
