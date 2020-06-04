/** @file header.h                                                           
 *  @brief Header file inclusion for student database application.                         
 *                                                                              
 *  This contains the function declarations used in application program and                    
 *  eventually any macros, constants or global variables you will need.         
 *                                                                              
 *  @author Premraj Todkar                                                      
 *  @bug No known bugs.                                                         
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int rollnum;
	char name[20];
	float avg;
	struct student *next;
}ST;


int input_check(int);
void add(ST **);
int count(ST *);
void print(ST *);
void sort(ST **);
ST * search(ST *);
void modify(ST *);
void delete(ST **);
void savefile(ST *);
void readfile(ST **);
