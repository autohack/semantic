%{
#include "my.h"
int level ;
struct symboltable *active_func_ptr;
struct symboltable *call_name_ptr;
struct symboltable st[50];
char result_type[20];
char id_type[20];
int param_count = 0;

int limit=-1;

void yyerror (const char *str)
{
	fprintf(stderr, "error: %s\n", str);		// error function
}

int yywrap() 
{
	return 1;
}
// main function 
int main() 
{
	yyparse(); // calling parse funtion 
	print_table();
	
}

%}

%token 	INT  FLOAT CHAR VOID MAIN WHILE  IDENTIFIER NUMBER STRING IF ELSE STRUCT 





%%

start:				start startdash | startdash | func_decl | struct_decl |start func_decl | start struct_decl;

/* -------------------for struct declartion ----------------------*/

struct_decl:		STRUCT IDENTIFIER '{' struct_block '}' vars';' ;


struct_block:		declaration struct_block | ;

/*------------------------------------------------------------------------*/

/*---------------- for function declartion-------------------------------*/

func_decl:			func_head  '{' block '}' {
												active_func_ptr = NULL;
												level = 0;
												
											} ;

func_head:			red_id '(' decl_plist ')' {level = 2;
												st[limit].num_params = param_count;};

red_id:				result IDENTIFIER{	
										if(search_func($2)) printf("error : same function declared \n");
										else enter_func($2,result_type);
										// active_func_ptr = st[limit]; 
										level = 1;
										param_count =0;
									};

result:				INT {strcpy(result_type ,"integer");}
					| FLOAT {strcpy(result_type,"real");}
					| VOID{strcpy(result_type, "void");};

decl_plist:			decl_pl | ;

decl_pl:			decl_pl ',' decl_param
					| decl_param;


decl_param:			datatype IDENTIFIER{
									if(search_param($2))
										printf("error: parameter already declared\n");
									else
										enter_param($2,$1);
									// printf("datatype: %s\n",$1 );
								};	




/*------------------------------------------------------------------------*/

/* main function */

startdash:			VOID MAIN '(' ')' '{' block	'}' 	{printf("\n syntax is correct\n");};
/* body insite the function */

block:				whileblock block 
					| declaration block 
					| define block
					| ifblock block
					| func_call block
					| '{' block '}' block
					| /* e */
					;
/* for function call */
func_call:			IDENTIFIER '(' param_list ')' ';';

func_func_call:		IDENTIFIER '(' param_list ')' ;

param_list:			plist | ;

plist:				e | e ',' plist;

e:					NUMBER | IDENTIFIER | IDENTIFIER '=' func_func_call | func_func_call | IDENTIFIER '=' IDENTIFIER | IDENTIFIER '=' NUMBER;

/*------------------------------------------------------------------------*/

/* ---------if -else------------------*/
ifblock:			IF '(' condition ')' '{' block '}' 
					| IF '(' condition ')' '{' block '}' ELSE '{' block '}';

condition:			cid	'<'	cid 
					| cid '>' cid
					| cid '>' '=' cid
					| cid '<' '=' cid
					| cid '!' '=' cid
					;

cid:				IDENTIFIER | exp;

/*------------while loop------------------------------*/
whileblock:			WHILE  '(' condition ')'	'{' block '}';

/*------------define variables -------------------------*/
define:				define_vars ';';

define_vars:		vars_id | vars_id ',' define_vars;

vars_id:			IDENTIFIER '=' exp ;
/*------------------------------------------------------------------------*/

/*-----------variable declartion ------------------------------*/
declaration:		datatype vars ';';


datatype:			INT {$$ = $1;}
					| FLOAT 
					| CHAR;


vars:				array_id
					| array_id ',' vars;

array_id:			IDENTIFIER
					| IDENTIFIER '=' exp
					| IDENTIFIER br_dimlist
					| IDENTIFIER br_dimlist '=' '{' numlist '}'
					| '*' IDENTIFIER
					;

numlist:			exp | exp ',' numlist;

br_dimlist:			'[' NUMBER ']' | '[' NUMBER ']' br_dimlist ;

/*------------------------------------------------------------------------*/


/*------------ Expression-------------------*/ 


exp:				factor
					| exp '+' factor
					| exp '-' factor
					;

factor:				term
					|factor '*' term
					| factor '/' term;

term:				NUMBER
					| '(' exp ')'
					| '-' term;


/*
done:
enter in main loop with void
while loop 
if -else done
condition
expersion
declare vars / array 
define vars 	all these cases done
				int a,c = 3	;
				a=1,c=2.2 + 5;
				int d[2] ;
				int k[2][3] = {4,4,2,1};
struct  done wth vars 
function
funtion calls
pointer is done
nested level is done 

todo:
	handle data type char 

*/

%%

void enter_func(char name[] , char type[] )
{
	limit += 1;
	strcpy(st[limit].name,name);
	strcpy(st[limit].type,type);
	st[limit].param = NULL;
	st[limit].local = NULL;
}

int search_func(char name[])
{
	int i = 0;
	for(i=0;i<limit;i++)
	{
		if(!strcmp(st[limit].name,name))
		{
			return 1;
		}
	}
	return 0;
}
void enter_param(char id[],char type[])
{
	param_count++;
	struct varlist *new_node,*temp;

	new_node= malloc(sizeof(struct varlist));


 	strcpy(new_node->var_name,id);
 	strcpy(new_node->type,type);
 	new_node->level = 1;
 	new_node->next=NULL;

	if(st[limit].param==NULL)
	{
	   st[limit].param=new_node;
	}
 	else
 	{
	   	temp = st[limit].param;
	    while(temp->next!=NULL)
	    {
	    	temp = temp->next;
	    }
	   temp->next = new_node;
 	}
}

void print_table()
{
	int i;
	struct varlist *temp;
	printf("symbol table printing\n");
	printf("name\ttype\n");
	for (i = 0;i<=limit;i++)
	{
		printf("%s\t",st[i].name );
		printf("%s\t",st[i].type );
		printf("%d\t",st[i].num_params);
		temp = st[i].param;
		printf("parmas:");
		while(temp!=NULL)
		{
			printf("%s-%s-%d\t",temp->var_name,temp->type,temp->level);
			temp = temp->next;
		}
		printf("\n");
	}
}
int search_param(char id[])
{
    struct varlist *current = st[limit].param;  // Initialize current
    while (current != NULL)
    {
        if(!strcmp(current->var_name,id))
            return 1;
        current = current->next;
    }
    return 0;
}

