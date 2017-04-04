//headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// data defination

struct SymbolTable
{
	char name[20];
	char type[20];
	struct varlist *param;
	struct varlist *local; 
	int num_params;
	
}SymbolTable;

struct varlist
{
	char id[20];
	char type[20];
	int level;
}varlist;

void yyerror();
int yywrap();