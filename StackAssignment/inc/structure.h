/** @file structure.h
 *  @brief Header file inclusion for stack application.
 *
 *  This contains the prototype for input_check function and
 *  eventually any macros, constants or global variables you will need.
 *
 *  @author Premraj Todkar
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <stdbool.h>

#define MAXVAL 2147483647
#define SUCCESS 0

typedef unsigned int uint32;

int input_check(int, uint32);

typedef struct stackNode {
	struct stackNode *prev;
	uint32 num;
	struct stackNode *next;
} stack;
