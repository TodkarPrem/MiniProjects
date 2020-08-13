/** @file stackcheck.c
 *  @brief contains stack's extended operations
 */

#include "structure.h"


/** @brief Checks the stack  exists or not.
 *
 *  This function checks existance of stack. If stack doesn't exist then
 *  returns 0 otherwise checks stack is empty or not. If stack is empty
 *  function returns success value that is 1, otherwise returns 2.
 *  Function works fine for both cases that is for stack empty
 *  as well as if stack don't exist.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @return Integer.
 */
int isStackEmpty(void *stackHeadPtr)
{
	stack *head = (stack *)stackHeadPtr;
	if (!head)
		return 0;
	else if (head->num == -1)
		return 1;
	else
		return 2;
}


/** @brief Retrieves the top node from stack without deleting it.
 *
 *  Stores the data of top node from stack in address of actual
 *  argument passed in function as a parameter.
 *  Upon success returns 0, otherwise 1.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[out] data variable to store retrieved value from stack
 *  @return Integer.
 */
int front(void *stackHeadPtr, uint32 *data)
{
	stack *head = (stack *)stackHeadPtr, *temp = 0;

	while (head) {
		if (head->num == -1)
			break;
		temp = head;
		head = head->next;
	}

	if (temp) {
		*data = temp->num;
		return 0;
	}
	return 1;
}


/** @brief Calculates the available size of stack.
 *
 *  If stack is initialised successfully, gives how much
 *  data we can store in stack. Upon success returns 0.
 *  If stack is initialised successfully, returns 1 as failure.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[out] size variable to store size of stack.
 *  @return Integer.
 */
int getStackSize(void *stackHeadPtr, uint32 *size)
{
	stack *temp = (stack *)stackHeadPtr;
	*size = 0;

	if (temp) {
		while (temp) {
			++*size;
			temp = temp->next;
		}
		return 0;
	}
	else
		return 1;
}


/** @brief Prints the number of elements availabel in stack.
 *
 *  If stack contains some valid data, then this function
 *  prints the available elements.
 *  If stack is empty then nothing gets printed on the screen.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @return Integer.
 */
int printStack(void *stackHeadPtr)
{
	stack *temp = (stack *)stackHeadPtr;

	if (temp && temp->num != -1) {
		printStack(temp->next);
		printf("%u\n", temp->num);
	} else
		return 1;
	return 0;
}


/** @brief Gives the index of specific data present in stack.
 *
 *  Gives the available node number or index of given data from stack,
 *  if given data is present in stack.
 *  Upon success function returns 0, otherwise 1.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[in] data data whose index we want to know.
 *  @param[out] index variable to store the index of found data
 *  @return Integer.
 */
int getNodeIndex(void *stackHeadPtr, uint32 data, uint32 *index)
{
	*index = 1;
	stack *temp = (stack *)stackHeadPtr;

	if (temp)
		do {
			if (temp->num == data)
				return 0;
			++*index;
			temp = temp->next;
		} while (temp);
	return 1;
}


/** @brief Deletes whole stack.
 *
 *  Deletes memory of stack allocated at the time of initialisation,
 *  by freeing the nodes of linked list.
 *  Upon successful deletion of stack returns 0, otherwise 1.
 *  Function works fine for all cases that is for stack full,
 *  stack empty as well as stack is not created yet.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @return Integer.
 */
int deleteStack(void **stackHeadPtr)
{
	stack *temp;

	if (*stackHeadPtr)
		do {
			temp = *(stack **)stackHeadPtr;
			*stackHeadPtr = temp->next;
			free(temp);
		} while (*stackHeadPtr);
	else
		return 1;
	return 0;
}


/** @brief Delete's a particular node from stack.
 *
 *  Takes index of node which user wants to delete as a argument,
 *  if node is present in stack deletes that node.
 *  Upon successful deletion of node returns 0, otherwise 1.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[in] index node number which user wants to delete from stack.
 *  @return Integer.
 */
int stackRemoveNthNode(void **stackHeadPtr, uint32 index)
{
	uint32 node_count = 1;
	stack *temp = *(stack **)stackHeadPtr, *temp1;

	while (temp) {
		if (node_count == index) {
			if (temp == *stackHeadPtr) {
				if (temp->next)
					temp->next->prev = 0;
				*stackHeadPtr = temp->next;
				free(temp);
				return 0;
			} else {
				temp1->next = temp->next;
				if (temp->next)
					temp1->next->prev = temp1;
				free(temp);
				return 0;
			}
		}
		temp1 = temp;
		temp = temp->next;
		node_count++;
	}
	return 1;
}


/** @brief Insert node at given location in stack.
 *
 *  Insert's node at given location by allocating new memory.
 *  Upon successful insertion returns 0, otherwise returns 1.
 *  Function works fine for cases like invalid node number,
 *  stack empty as well as stack don't exist.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[in] position node number where user wants to insert node.
 *  @param[in] data input to the inserted node.
 *  @return Integer.
 */
int insertNodeAt(void **stackHeadPtr, int position, uint32 data)
{
	uint32 node_count = 1, size = 0;
	stack *temp1, *temp2 = 0, *temp;

	temp1 = *(stack **)stackHeadPtr;
	while (temp1) {
		size++;
		temp1 = temp1->next;
	}

	temp1 = *(stack **)stackHeadPtr;

	if (size >= position)
		while (temp1) {
			if (node_count == position) {
				temp = malloc(sizeof(stack));
				temp->prev = temp2;
				temp->num = data;
				temp->next = temp1;

				if (node_count == 1)
					*stackHeadPtr = temp;
				else
					temp2->next = temp;
				temp1->prev = temp;
				return 0;
			}
			if (temp1->num == -1)
				temp1->num = 0;
			temp2 = temp1;
			temp1 = temp1->next;
			node_count++;
		}
	return 1;
}


/** @brief Retrieve's data from particular node from given index.
 *
 *  Retrieve's data from particular node using index and offset.
 *  If offset is positive, find's node having node number as
 *  index + offset, otherwise index - offset.
 *  Upon success returns 0, otherwise returns index + offset value.
 *  Function works fine for cases like stack empty as well
 *  as stack don't exist.
 *
 *  @param[in] stackHeadPtr Head pointer of stack.
 *  @param[in] index node number from which user wants to retrieve data.
 *  @param[in] offset displacement value from base location that is index.
 *  @param[out] data variable to store the retrieved data
 *  @return Integer.
 */
int retrieveNodeFrom(void *stackHeadPtr, int index, int offset, uint32 *data)
{
	stack *temp = (stack *) stackHeadPtr;
	uint32 node_count = 1;

	if (index + offset >= 1) {
		while (temp) {
			if (node_count == index + offset) {
				*data = temp->num;
				return 0;
			}
			temp = temp->next;
			node_count++;
		}
	}
	if (index + offset)
		return index + offset;
	else
		return 1;
}
