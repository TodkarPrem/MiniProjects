#include "header.h"

/** @file  readfile.c
 *  @brief Function used to read database
 *
 *  This function takes address of head pointer of linked list as function
 *  arguments and reads default file to generate linked list according to
 *  previously created database.
 *
 *  @param[in] HeadPtr Head pointer of stack
 *  @return    Void
 */
void readfile(ST **Headptr)
{
	ST *temp1, *temp2, var;
	FILE *fp;

	fp = fopen("../doc/Student_DB.txt", "r");
	if (fp == 0) {
		printf("Database is not created yet...\n");
		return;
	}

	while (*Headptr) {
		temp1 = *Headptr;
		*Headptr = temp1->next;
		free(temp1);
	}

	while (fscanf(fp, "%d%s%f", &var.rollnum, var.name, &var.avg) != EOF) {
		temp1 = malloc(sizeof(ST));

		temp1->rollnum = var.rollnum;
		strcpy(temp1->name, var.name);
		temp1->avg = var.avg;

		if (*Headptr == 0) {
			temp1->next = *Headptr;
			*Headptr = temp1;
		} else {
			temp2 = *Headptr;
			while (temp2->next)
				temp2 = temp2->next;
			temp1->next = temp2->next;
			temp2->next = temp1;
		}
	}
}
