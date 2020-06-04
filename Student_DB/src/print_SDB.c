#include "header.h"

/** @file  print_SDB.c
 *  @brief Function used to print student records
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and prints available student records on monitor.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    Void
 */
void print(ST *stackPtr)
{
	printf("Available records:\n");
	while (stackPtr) {
		printf("%d %s %f\n", stackPtr->rollnum, stackPtr->name, \
				stackPtr->avg);
		stackPtr = stackPtr->next;
	}
printf("\n");
}


/** @file  Function used to linked list node
 *  @brief Adds node in linked list to store single student record
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and stores the data available in linked list in given file
 *  to use it as database.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    Void
 */
void savefile(ST *stackPtr)
{
	FILE *fptr;
	fptr = fopen("../doc/Student_DB.txt", "w");

	while (stackPtr) {
		fprintf(fptr, "%d %s %f\n", stackPtr->rollnum, stackPtr->name, \
				stackPtr->avg);
		stackPtr = stackPtr->next;
	}
}


/** @file  Function used to count available student records
 *  @brief Counts how many nodes are available in linked list
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and counts how many student records are stroed in database.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    Void
 */
int count(ST *stackPtr)
{
	int count = 0;
	while (stackPtr) {
		count++;
		stackPtr = stackPtr->next;
	}
	return count;
}
