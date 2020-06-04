#include "header.h"

/** @file  modify.c
 *  @brief Function used to modify student record
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and modifies student data according to roll number or name.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    Void
 */
void modify(ST *HeadPtr)
{
	ST *tmp;

	printf("\nRecord which needs to modify:\n");
	tmp = search(HeadPtr);

	if (tmp != 0) {
		printf("Current student information:\n");
		printf("%d %s %f\n", tmp->rollnum, tmp->name, tmp->avg);

		printf("\nEnter roll number, name & marks to modify record\n");
		scanf("%d%s%f", &tmp->rollnum, tmp->name, &tmp->avg);
		printf("\nRecord modified...\n");
	} else
		printf("Student database not modified...\n");
}
