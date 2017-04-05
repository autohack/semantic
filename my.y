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
										else enter_func($2,$1);
										// active_func_ptr = st[limit]; 
										level = 1;
										param_count =0;
									};

result:				INT {$$=$1;}
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
									
								};	




/*------------------------------------------------------------------------*/

/* main function */

startdash:			void_main '(' ')' '{' block	'}' {printf("\n syntax is correct\n");};

void_main:			VOID MAIN{
								if(search_func($2)) 
									printf("error : same function declared \n");
								else
									enter_func($2,$1);
									// active_func_ptr = st[limit]; 
									level = 2;
							};
/* body insite the function */

block:				whileblock block 
					| declaration block 
					| define block
					| ifblock block
					| func_call block
					| '{' {level++; } block '}' {level--;} block 
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


datatype:			INT {strcpy(result_type, "int");}
					| FLOAT 
					| CHAR;


vars:				array_id{$$ = $1;}
					| array_id ',' vars;

array_id:			idd	
					| idd '=' exp
					| idd br_dimlist
					| idd br_dimlist '=' '{' numlist '}'
					| '*' idd
					;

idd:				IDENTIFIER{	
								
								if(search_vars($1))
									printf("found same name var\n");
								else if(level == 2 && search_param($1))
								{
									printf("found same parameter of function\n");
								}
								else
								{
									// printf("in idd:%d where IDENTIFIER = %s\n",limit,$1);
									enter_vars($1);
								}



}
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
	// printf("i m gonna insert in %d %s\n", limit,name);
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
void enter_vars(char id[])
{
	// printf("%s --- %d\n", id,level);
	struct varlist *new_node,*temp;

	new_node= malloc(sizeof(struct varlist));

	
 	strcpy(new_node->var_name,id);
 	strcpy(new_node->type,result_type);
 	new_node->level = level;
 	new_node->next=NULL;

	if(st[limit].local==NULL)
	{
	   st[limit].local=new_node;
	}
 	else
 	{
	   	temp = st[limit].local;
	    while(temp->next!=NULL)
	    {
	    	temp = temp->next;
	    }
	   temp->next = new_node;
 	}
 	// printf("%s done\n",st[limit].local->var_name);
}
void print_table()
{
	int i;
	struct varlist *temp;
	printf("symbol table printing\n");
	printf("name\ttype\tparam_count\n");
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
		temp = st[i].local;
		printf("local:");
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

int search_vars(char id[])
{
    struct varlist *current = st[limit].local;  // Initialize current
    while (current != NULL)
    {
        if(!strcmp(current->var_name,id))
            return 1;
        current = current->next;
    }
    return 0;
}

