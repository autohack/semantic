%{
#include"my.h"

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
	
}

%}

%token INT FLOAT CHAR VOID MAIN WHILE IDENTIFIER NUMBER STRING IF ELSE STRUCT 

%%

start:				start startdash | startdash | func_decl | struct_decl |start func_decl | start struct_decl;

/* -------------------for struct declartion ----------------------*/

struct_decl:		STRUCT IDENTIFIER '{' struct_block '}' vars';' ;


struct_block:		declaration struct_block | ;

/*------------------------------------------------------------------------*/

/*---------------- for function declartion-------------------------------*/

func_decl:			result IDENTIFIER '(' decl_plist ')' '{' block '}' ;

result:				INT | FLOAT | VOID;

decl_plist:			decl_pl | ;

decl_pl:			decl_pl ',' decl_param
					| decl_param;

decl_param:			datatype ids;

ids:				IDENTIFIER
					| IDENTIFIER '[' ']';


/*------------------------------------------------------------------------*/

/* main function */

startdash:			VOID MAIN '(' ')' '{' block	'}' 	{printf("\n syntax is correct\n");};
/* body insite the function */

block:				whileblock block 
					| declaration block 
					| define block
					| ifblock block
					| func_call
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


datatype:			INT 
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

todo:
	handle data type char 

*/

%%




