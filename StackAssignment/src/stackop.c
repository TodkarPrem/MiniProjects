/** @file stackop.c
 *  @brief contains stack's basic operations such as initialise, push and pop
 */

#include "structure.h"

/** @brief Initialises the stack.
 *
 *  Initialises the stack with given size using doubly linked list.
 *  By default data values are set to -1.
 *  Upon successful initialisation returns 0.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[in] size How many elements user wants store in stack.
 *  @return Integer
 */
int initstack(void **stackHeadPtr, uint32 size)
{
	int i;
	stack *temp;

	for (i = 0; i < size; i++) {
		temp = malloc(sizeof(stack));
		temp->prev = 0;
		temp->num = -1;
		temp->next = *(stack **)stackHeadPtr;

		if (*(stack **)stackHeadPtr)
			(*(stack **)stackHeadPtr)->prev = temp;
		*stackHeadPtr = temp;
	}
	return 0;
}


/** @brief Initialises the stack.
 *
 *  Inserts data on top of the stack.
 *  Upon successful insertion of data returns 0, otherwise 1.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[in] data data which user wants to insert in stack.
 *  @return Integer
 */
int push(void *stackHeadPtr, uint32 data)
{
	stack *temp = (stack *)stackHeadPtr;

	if (temp) {
		do {
			if (temp->num == -1) {
				temp->num = data;
				return 0;
			}
			temp = temp->next;
		} while (temp);
	}
	return 1;
}


/** @brief Deletes top element of the stack.
 *
 *  Pops the top element of stack.
 *  Upon successful popping returns 0, otherwise 1.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[out] data variable used to store poped element from stack.
 *  @return Integer
 */
int pop(void *stackHeadPtr, uint32 *data)
{
	stack *temp1 = (stack *)stackHeadPtr, *temp2 = 0;

	while (temp1) {
		if (temp1->num == -1)
			break;
		temp2 = temp1;
		temp1 = temp1->next;
	}
	if (temp2) {
		temp2->num = -1;
		return 0;
	}
	return 1;
}
