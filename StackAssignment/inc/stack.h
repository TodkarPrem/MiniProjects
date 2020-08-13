/** @file stack.h
 *  @brief Function prototypes for the stack related operations.
 *
 *  @author Premraj Todkar
 *  @bug No known bugs.
 */

int initstack(void **stackHeadPtr, uint32 maxStackSize);
int push(void *stackHeadPtr, uint32 data);
int pop(void *stackHeadPtr, uint32 *data);
int front(void *stackHeadPtr, uint32 *data);
int getStackSize(void *stackHeadPtr, uint32 *size);
int getNodeIndex(void *stackHeadPtr, uint32 data, uint32 *index);
int printStack(void *stackHeadPtr);
int insertNodeAt(void **stackHeadPtr, int position, uint32 data);
int retrieveNodeFrom(void *stackHeadPtr, int index, int offset, uint32 *);
int deleteStack(void **stackHeadPtr);
int stackRemoveNthNode(void **stackHeadPtr, int position);
int isStackEmpty(void *stackHeadPtr);
