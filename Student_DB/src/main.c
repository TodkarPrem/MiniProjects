/** @mainpage	Student database management system
 *  @brief 	This module store's the student records which can be used in
 		educational organisations. For efficient memory storage dynamic
		memory allocation is used. This module uses Menu based system.
		Different modules are included for easy user interface.
    @author	Premraj Todkar
    @date	8 June 2018
 */

#include "header.h"

/** @file  main.c
 *  @brief Application program
 *
 *  This function is a main application which uses different functions to make
 *  overall student database. Uses Menu based system to take input from user
 *  which makes this application user friendly.
 *
 *  @param[in] Void
 *  @return    Integer
 */
int main()
{
	ST *HeadPtr = 0, *temp;
	int option, check;
	char choice;

	readfile(&HeadPtr);
	while (1) {
		printf("*** WELCOME TO STUDENT DATABASE MANAGEMENT SYSTEM ***\n"
			"\n1.Add student\n2.Delete Record\n3.Modify Record\n"
			"4.Read Database\n5.Sort Database\n6.Search Record\n"
			"7.Print database\n8.Exit\n\n");

		check = 1;
		while (check) {
			printf("Enter choice: ");
			check = scanf(" %d", &option);

			check = input_check(check);
		}

		switch (option) {
		case 1:
			do {
				add(&HeadPtr);
				printf("Want to continue(y/n): ");
				scanf(" %c", &choice);
			} while(choice == 'y' || choice == 'Y');
			break;
		case 2:
			delete(&HeadPtr);
			break;
		case 3:
			modify(HeadPtr);
			savefile(HeadPtr);
			break;
		case 4:
			readfile(&HeadPtr);
			print(HeadPtr);
			break;
		case 5:
			sort(&HeadPtr);
			break;
		case 6:
			temp = search(HeadPtr);
			if (temp != 0)
				printf("%d %s %f\n", temp->rollnum, temp->name,\
						temp->avg);
			break;
		case 7:
			print(HeadPtr);
			break;
		case 8:
			savefile(HeadPtr);
			printf("Database updated...\n");
			return 0;
		default :
			printf("Invalid choice...\n");
		}
	}
}


/** @brief Checks the validity of input given by user.
 *
 *  This function is used to check input validity to avoid crashing of app.
 *  If wrong input is provided by user then this function provides error
 *  message and discards the input buffer.
 *
 *  @param[in] Integer
 *  @return    Integer
 */
int input_check(int check)
{
	if (check == 0) {
		printf("ERROR: Invalid input. Please provide proper input.\n");
		__fpurge(stdin);
		return 1;
	}
	return 0;
}
