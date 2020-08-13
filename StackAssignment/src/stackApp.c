/** @mainpage StackApp
 *
 *  This module gives brief idea about stack and it's operations.
 *
 *  @author Premraj Todkar
 *  @date 07 June 2018
 *  @bug No known bugs.
 */

#include "structure.h"
#include "stack.h"


/** @file stackApp.c
 *  @brief Main function describing stack application.
 *
 *  Display's stack related operations to select as option.
 *  Make proper call's of library function for correct output.
 *  Also call's input_check function to check the validity
 *  of input given by user.
 *
 *  @param[in] Void.
 *  @return Integer.
 */
int main()
{
	uint32 choice, ret_val, data, size, index, offset;
	stack *HeadPtr = 0;

	while (1) {
input:		printf("\n********** MENU **********\n"
			"1.  Initialise stack\n"
			"2.  Push data in stack\n"
			"3.  Pop data from stack\n"
			"4.  See Top element of stack\n"
			"5.  Get stack size\n"
			"6.  Get stack node from specific index\n"
			"7.  Print all stack element's\n"
			"8.  Insert element in stack at specific index\n"
			"9.  Retrieve node from specific stack index\n"
			"10. Delete Stack\n"
			"11. Delete specific element from stack\n"
			"12. Check if Stack is empty or not\n"
			"13. Exit\n");

		printf("\nEnter choice: ");
		ret_val = scanf("%u", &choice);

		ret_val = input_check(ret_val, choice);
		if (ret_val == 0) {
			printf("ERROR: Please provide proper input.\n");
			goto input;
		}

here:		switch (choice) {
		case 1:
			printf("Enter stack size(number of elements): ");
			ret_val = scanf("%u", &size);

			ret_val = input_check(ret_val, size);
			if (ret_val == 0) {
				printf("ERROR: Please provide proper input.\n");
				goto here;
			}

			ret_val = initstack((void **)&HeadPtr, size);
			if (ret_val == SUCCESS)
				printf("Stack initialised successfully.\n");
			else
				printf("ERROR: Stack initialisation failed.\n");
			break;
		case 2:
			if (HeadPtr == 0) {
				printf("ERROR: Stack is not created yet...\n");
				break;
			}
			printf("Enter data to push in stack: ");
			ret_val = scanf("%u", &data);

			ret_val = input_check(ret_val, data);
			if (ret_val == 0) {
				printf("ERROR: Please provide proper input.\n");
				goto here;
			}

			ret_val = push(HeadPtr, data);
			if (ret_val == SUCCESS)
				printf("Data pushed in stack successfully.\n");
			else
				printf("ERROR: Failed to push data.\n");
			break;
		case 3:
			ret_val = pop(HeadPtr, &data);
			if (ret_val == SUCCESS)
				printf("Element poped successfully.\n");
			else
				printf("ERROR: Failed to pop data. Stack is "
					"Empty.\n");
			break;
		case 4:
			ret_val = front(HeadPtr, &data);
			if (ret_val == SUCCESS)
				printf("Top element of stack is: %d\n", data);
			else
				printf("ERROR: Stack is empty.\n");
			break;
		case 5:
			ret_val = getStackSize(HeadPtr, &size);
			if (ret_val == SUCCESS)
				printf("Available stack size : %d\n", size);
			else
				printf("ERROR: Failed to collect stack size. "
					"Stack is not created yet...\n");
			break;
		case 6:
			if (HeadPtr == 0) {
				printf("ERROR: Stack is not created yet...\n");
				break;
			}
			printf("Enter element to know its index from stack: ");
			ret_val = scanf("%d", &data);

			ret_val = input_check(ret_val, data);
			if (ret_val == 0) {
				printf("ERROR: Please provide proper input.\n");
				goto here;
			}

			ret_val = getNodeIndex(HeadPtr, data, &index);
			if (ret_val == SUCCESS)
				printf("Element %d is available in stack at "
					"index :%d\n", data, index);
			else
				printf("ERROR: Failed to get index of given "
					"data.\n");
			break;
		case 7:
			ret_val = printStack(HeadPtr);
			if (ret_val == 1)
				printf("ERROR: Stack is Empty.\n");
			break;
		case 8:
			if (HeadPtr == 0) {
				printf("ERROR: Stack is not created yet...\n");
				break;
			}
			printf("Enter node index to insert in stack: ");
			ret_val = scanf("%d", &index);

			ret_val = input_check(ret_val, index);
			if (ret_val == 0) {
				printf("ERROR: Please provide proper input.\n");
				goto here;
			}

here2:			printf("Enter data to be inserted in node: ");
			ret_val = scanf("%d", &data);

			ret_val = input_check(ret_val, data);
			if (ret_val == 0) {
				printf("ERROR: Please provide proper input.\n");
				goto here2;
			}

			ret_val = insertNodeAt((void **)&HeadPtr, index, data);
			if (ret_val == SUCCESS)
				printf("Node inserted successfully.\n");
			else
				printf("ERROR: Failed to insert node.\n");
			break;
		case 9:
			if (HeadPtr == 0) {
				printf("ERROR: Stack is not created yet...\n");
				break;
			}
			printf("Enter node index to retrieve from stack: ");
			ret_val = scanf("%d", &index);

			ret_val = input_check(ret_val, index);
			if (ret_val == 0) {
				printf("ERROR: Please provide proper input.\n");
				goto here;
			}

here3:			printf("Enter node offset with respect to index: ");
			ret_val = scanf("%d", &offset);

			ret_val = input_check(ret_val, 0);
			if (ret_val == 0) {
				printf("ERROR: Please provide proper input.\n");
				goto here3;
			}

			ret_val = retrieveNodeFrom(HeadPtr, index, offset,
					&data);
			if (ret_val == SUCCESS)
				printf("Retrievd data from stack at node index "
					"%d is: %d\n", index + offset, data);
			else
				printf("ERROR: Failed to retrieve data from "
					"index %d\n", index + offset);
			break;
		case 10:
			if (HeadPtr == 0) {
				printf("ERROR: Stack is not created yet...\n");
				break;
			}
			ret_val = deleteStack((void **)&HeadPtr);
			if (ret_val == SUCCESS)
				printf("Stack deleted successfully.\n");
			else
				printf("ERROR: Failed to delete stack. "
					"Stack don't exist.\n");
			break;
		case 11:
			if (HeadPtr == 0) {
				printf("ERROR: Stack is not created yet...\n");
				break;
			}
			printf("Enter node index to delete from stack: ");
			ret_val = scanf("%u", &index);

			ret_val = input_check(ret_val, index);
			if (ret_val == 0) {
				printf("ERROR: Please provide proper input.\n");
				goto here;
			}

			ret_val = stackRemoveNthNode((void **)&HeadPtr, index);
			if (ret_val == SUCCESS)
				printf("Stack node deleted successfully.\n");
			else
				printf("ERROR: Failed to delete node at index: "
					"%d\n",	index);
			break;
		case 12:
			ret_val = isStackEmpty(HeadPtr);
			if (ret_val == 0)
				printf("Stack doesn't exist.\n");
			else if (ret_val == 1)
				printf("Stack is empty\n");
			else
				printf("stack is not empty.\n");
			break;
		case 13:
			return 0;
		default:
			printf("ERROR: Invalid choice. Please try again.\n\n");
		}
	}
	return 0;
}



/** @brief Checks the input given by user is valid or not.
 *
 *  Checks the return type i.e in variable of scanf to decide whether
 *  the input given by user is valid or not.
 *  Also checks the input is within valid range or not.
 *  Upon valid input, function returns 1, otherwise 0.
 *
 *  @param[in] in return type of scanf.
 *  @param[in] data input given by user.
 *  @return Integer.
 */
int input_check(int in, uint32 data)
{
	if (in == 0) {
		__fpurge(stdin);
		return 0;
	} else if (data > MAXVAL) {
		printf("ERROR: Input data is out of range(>%d).\n", MAXVAL);
		return 0;
	}
	return 1;
}
