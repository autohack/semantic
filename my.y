%{
#include "my.h"
int level ;
int active_func_num;
struct symboltable *call_name_ptr;
struct symboltable st[50];
struct for_struct fs[10];
char result_type[20];
int param_count = 0;
int limit=-1;
int total_struct=-1;
int struct_flag = 0;
int e_type = 0;

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

%union {
	int num;
	char *st;
	char fixstr[100];
}
%token <fixstr> INT  FLOAT CHAR VOID MAIN WHILE STRING IF ELSE STRUCT IDENTIFIER
%token <a_number> NUMBER


%type<fixstr> result idd datatype
%type <num>	 param_list plist term factor pm_exp d_exp or_exp exp lhs



%%

start:				start startdash | startdash | func_decl | struct_decl |start func_decl | start struct_decl;

/* -------------------for struct declartion ----------------------*/

struct_decl:		STRUCT IDENTIFIER '{'{struct_flag=1;} struct_block {struct_flag=0;}'}' ';' {

																	if(search_struct($2))
																		printf("%s struct declared before\n",$2 );
																	else
																	{
																		total_struct++;
																		strcpy(fs[total_struct].name,$2);
																		
																	}
																};


struct_block:		declaration struct_block | ;

/*------------------------------------------------------------------------*/

/*---------------- for function declartion-------------------------------*/

func_decl:			func_head  '{' block '}' {
												
												level = 0;
												
											} ;

func_head:			red_id '(' decl_plist ')' {level = 2;
												st[limit].num_params = param_count;};

red_id:				result IDENTIFIER{	

										if(search_func($2)) printf("error : same function %s declared \n",$2);
										else enter_func($2,$1);
										// active_func_ptr = st[limit]; 
										level = 1;
										param_count =0;
									};

result:				INT {strcpy($$,$1);}
					| FLOAT {strcpy($$,$1);}
					| VOID{strcpy($$,$1);};

decl_plist:			decl_pl | ;

decl_pl:			decl_pl ',' decl_param
					| decl_param;


decl_param:			datatype IDENTIFIER{
										e_type = 1;
										if(search_param($2))
											printf("error: parameter, %s already declared\n",$2);
										else
											enter_param($2,$1);
									
								};	




/*------------------------------------------------------------------------*/

/* main function */

startdash:			void_main '(' ')' '{' block	'}' {printf("\n syntax is correct\n");};

void_main:			VOID MAIN{
								if(search_func($2)) 
									printf("error : same %s function declared before \n",$2);
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
/* --------------for function call --------------------------*/
func_call:			func_func_call ';';

func_func_call:		IDENTIFIER '(' param_list ')' {
													if(!search_func($1))
														printf("%s function not declared\n",$1);
													else
													{
														// printf("%d\n",$3 );
														if(st[active_func_num].num_params != $3)
															printf("mismatch in number of parameters in call and declaration in %s function\n",$1);

													}

												} ;

param_list:			plist{$$ = $1;} | {$$ = 0;};

plist:				e {$$ =  1;}| e ',' plist{$$ = $3 + 1;};

e:					NUMBER 
					| v_id
					| v_id '=' func_func_call 
					| func_func_call 
					| v_id '=' v_id 
					| v_id '=' NUMBER
					;

v_id:				IDENTIFIER{	
								int f = search_vars($1);
								if(f==0)
								{
									f = search_param($1);
									if(!(level==2 && f!=0))
									{
										printf("%s is not declared before and using for func call \n",$1 );
									}
								}
							};
/*------------------------------------------------------------------------*/

/* ---------if -else------------------*/
ifblock:			IF '(' exp ')' '{' block '}' 
					| IF '(' exp ')' '{' block '}' ELSE '{' block '}';



/*------------while loop------------------------------*/
whileblock:			WHILE  '(' exp ')'	'{' block '}';

/*------------define variables -------------------------*/
define:				define_vars ';';

define_vars:		vars_id | vars_id ',' define_vars;

vars_id:			lhs '=' exp { if($1 !=1 || $3 != 1)
									printf("error : type mismatch of operands in assigment statement\n");
								};

lhs:				IDENTIFIER{	
								int f = search_vars($1);
								if(f==0)
								{
									f = search_param($1);
									if(!(level==2 && f!=0))
									{
										printf("error: %s is not defined earlier\n",$1 );
										$$ = -1;
									}
								}
								else
									$$ = f;

								};
/*------------------------------------------------------------------------*/

/*-----------variable declartion ------------------------------*/
declaration:		datatype{strcpy(result_type,$1);} vars ';';


datatype:			INT 
					| FLOAT 
					| CHAR
					;


vars:				array_id
					| array_id ',' vars;

array_id:			idd
					| idd '=' exp 
					| idd2 br_dimlist 
					| idd2 br_dimlist '=' '{' numlist '}' 
					| '*' idd3 
					;



idd:				IDENTIFIER{	e_type = 1;
								if(struct_flag==0)
								{
									int f = search_vars($1); int f2 = search_param($1);
									if(f != 0)
										printf("found same name var : %s\n",$1);

									
									else if(level == 2 && f2 !=0 )
										printf("found same parameter :%s  in  function\n",$1);
									else
										enter_vars($1);
								}
								else
								{
									if(search_in_struct_var($1))
										printf("found same name var in struct  : %s\n",$1);
									else
										enter_in_struct($1);

								}

							};

idd2:				IDENTIFIER{	e_type = 2;
								if(struct_flag==0)
								{
									int f = search_vars($1); int f2 = search_param($1);
									if(f != 0)
										printf("found same name var : %s\n",$1);
									
									else if(level == 2 && f2 !=0 )
										printf("found same parameter :%s  in  function\n",$1);
									else
										enter_vars($1);
								}
								else
								{
									if(search_in_struct_var($1))
										printf("found same name var in struct  : %s\n",$1);
									else
										enter_in_struct($1);

								}

							};


idd3:				IDENTIFIER{	e_type = 3;
								if(struct_flag==0)
								{
									int f = search_vars($1); int f2 = search_param($1);
									if(f != 0)
										printf("found same name var : %s\n",$1);
									
									else if(level == 2 && f2 !=0 )
										printf("found same parameter :%s  in  function\n",$1);
									else
										enter_vars($1);
								}
								else
								{
									if(search_in_struct_var($1))
										printf("found same name var in struct  : %s\n",$1);
									else
										enter_in_struct($1);

								}

							};

numlist:			exp | exp ',' numlist;

br_dimlist:			'[' NUMBER ']' | '[' NUMBER ']' br_dimlist ;

/*------------------------------------------------------------------------*/


/*------------ Expression-------------------*/ 
exp:				or_exp '|' '|' exp { if($1 !=1 || $4 != 1)
											{
												printf("error : type mismatch in expersion\n");
												$$ = -1;
											}
											else
												$$ = 1;
											}
					| or_exp
					;

or_exp:				d_exp '&' '&' or_exp  { if($1 !=1 || $4 != 1)
											{
												printf("error : type mismatch in expersion\n");
												$$ = -1;
											}
											else
												$$ = 1;
											}
					| d_exp
					;

d_exp:				pm_exp
					| pm_exp '>' pm_exp { if($1 !=1 || $3 != 1)
											{
												printf("error : type mismatch in expersion\n");
												$$ = -1;
											}
											else
												$$ = 1;
										}
					| pm_exp '!' '=' pm_exp{ if($1 !=1 || $4 != 1)
											{
												printf("error : type mismatch in expersion\n");
												$$ = -1;
											}
											else
												$$ = 1;
											}
					| pm_exp '=' '=' pm_exp{ if($1 !=1 || $4 != 1)
											{
												printf("error : type mismatch in expersion\n");
												$$ = -1;
											}
											else
												$$ = 1;
											}
					| pm_exp '<' pm_exp{ if($1 !=1 || $3 != 1)
										{
											printf("error : type mismatch in expersion\n");
											$$ = -1;
										}
										else
											$$ = 1;
									}
					| pm_exp '<' '=' pm_exp{ if($1 !=1 || $4 != 1)
											{
												printf("error : type mismatch in expersion\n");
												$$ = -1;
											}
											else
												$$ = 1;
											}

					| pm_exp '>' '=' pm_exp{ if($1 !=1 || $4 != 1)
											{
												printf("error : type mismatch in expersion\n");
												$$ = -1;
											}
											else
												$$ = 1;
											}
					| '!' '(' exp ')'{$$ = $3;}
					;

			

pm_exp:				factor	
					| pm_exp '+' factor{ if($1 !=1 || $3 != 1)
										{
											printf("error : type mismatch in expersion\n");
											$$ = -1;
										}
										else
											$$ = 1;
										}
					| pm_exp '-' factor{ if($1 !=1 || $3 != 1)
										{
											printf("error : type mismatch in expersion\n");
											$$ = -1;
										}
										else
											$$ = 1;
										}
					| '-' factor {$$ = $2;}
					;

factor:				term
					|factor '*' term { if($1 !=1 || $3 != 1)
										{
											printf("error : type mismatch in expersion\n");
											$$ = -1;
										}
										else
											$$ = 1;
										}
					| factor '/' term{ if($1 !=1 || $3 != 1)
										{
											$$ = -1;
											printf("error : type mismatch in expersion\n");
										}
										else
											$$ = 1;
										}
					;

term:				NUMBER{$$ = 1;}
					| IDENTIFIER{	
									int f = search_vars($1);
									
									if(f==0)
									{
										f = search_param($1);
										if(!(level==2 && f!=0))
										{
											printf("error: %s is not defined earlier\n",$1 );
											$$ = -1;
										}
									}
									else
										$$ = f;

								}

					/*| func_func_call*/
					| '(' exp ')' { $$ = $2;}
					;


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
Variable declaration checking
Type checking should include type coercibility and operator compatibility.
Scope checking

semantic :
	functions done

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


void enter_param(char id[],char type[])
{
	param_count++;
	struct varlist *new_node,*temp;

	new_node= malloc(sizeof(struct varlist));


 	strcpy(new_node->var_name,id);
 	strcpy(new_node->type,type);
 	new_node->level = 1;
 	new_node->next=NULL;
 	new_node->e_type = e_type;

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
 	new_node->e_type = e_type;
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
			printf("%s-%s-%d-%d\t",temp->var_name,temp->type,temp->level,temp->e_type);
			temp = temp->next;
		}
		temp = st[i].local;
		printf("local:");
		while(temp!=NULL)
		{
			printf("%s-%s-%d-%d\t",temp->var_name,temp->type,temp->level , temp->e_type);
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
            return (current->e_type);
        current = current->next;
    }
    return 0;
}

int search_vars(char id[])
{
    struct varlist *current = st[limit].local;  // Initialize current
    struct varlist *temp = st[limit].param;

    while (current != NULL)
    {
        if(!strcmp(current->var_name,id) && current->level <= level)
            return (current->e_type);
        current = current->next;
    }


    return 0;
}

int search_func(char name[])
{

	int i = 0;
	for(i=0;i<=limit;i++)
	{
		if(!strcmp(st[i].name,name))
		{
			active_func_num = i;		// for function call
			return 1;
		}
	}
	return 0;
}

int search_struct(char name[])
{

	int i = 0;
	for(i=0;i<=total_struct;i++)
	{
		if(!strcmp(fs[i].name,name))
		{		
			return 1;
		}
	}
	return 0;
}

void enter_in_struct(char id[])
{
	// printf("%s --- %d\n", id,level);
	struct varlist *new_node,*temp;

	new_node= malloc(sizeof(struct varlist));

	
 	strcpy(new_node->var_name,id);
 	strcpy(new_node->type,result_type);
 	new_node->level = 0;
 	new_node->next=NULL;

	if(fs[total_struct].local==NULL)
	{
	   fs[total_struct].local=new_node;
	}
 	else
 	{
	   	temp = fs[total_struct].local;
	    while(temp->next!=NULL)
	    {
	    	temp = temp->next;
	    }
	   temp->next = new_node;
 	}
 	// printf("%s done\n",st[limit].local->var_name);
}
int search_in_struct_var(char id[])
{
	struct varlist *current = fs[total_struct].local;  // Initialize current

    while (current != NULL)
    {
        if(!strcmp(current->var_name,id))
            return 1;
        current = current->next;
    }


    return 0;
}