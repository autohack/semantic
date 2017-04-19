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
	int e_type;// 1- normal 2- array 3- pointer
	struct varlist *next;
}varlist;

struct for_struct
{
	char name[20];
	struct varlist *local;
}for_struct;
int  search_func();
void enter_func();
int search_param();
void enter_param();
void print_table();
int  search_vars();
void enter_vars();
int search_struct();
void enter_in_struct();
int search_in_struct_var();