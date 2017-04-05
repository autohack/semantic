//headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// data defination

struct symboltable
{
	char name[20];
	char type[20];
	struct varlist *param;
	struct varlist *local; 
	int num_params;
	
}symboltable;

struct varlist
{
	char var_name[20];
	char type[20];
	int level;
	struct varlist *next;
}varlist;


int  search_func();
void enter_func();
int search_param();
void enter_param();
void print_table();