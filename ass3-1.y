%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <iostream>
	#include "definition.h"
	using namespace std;

	vector<func_name_table> global_func;
	vector<quadruple> quad_table;
	vector<struct_name_table> global_struct;
	variable *vn, *pn, *vnptr, *pnptr;
	int active_func_ptr = -1, call_func_ptr = -1, level = 0, namptr = -1, fnptr = -1,active_struct_ptr = -1,strptr = -1;
	bool found, ok;
	int nextquad = 0;

	void yyerror(char *s);
	int yylex();
	int get_size(enum t type);
	int get_dim(string name, int dimnum);
	void patchtype(enum t type,vector <variable> &namelist,string name);
	void backpatch(vector<int> list, int quad_number);
	void gen(quadruple quad);
	int newtemp(variable *var);
	void error (string err);
	int coercible(enum t type1, enum t type2);
	enum t not_compatible(enum t type);
	enum t compare_types(enum t type1,enum t type2);
	bool compatible_arithop(enum t type1, enum t type2);
	void search_func(string name, bool &found, int &namptr);
	void enter_func(string name, enum t type, int &namptr, string struct_name);
	void search_var(string name, int active_func_ptr, int level, bool &found, variable* &vn);
	void enter_var(string name, int level, int active_func_ptr, variable* &namptr, vector<int> dimlist, int pointer);
	void search_param(string name, int active_func_ptr, bool &found, variable* &pn);
	void delete_var_list(int active_func_ptr, int level);
	void enter_param(string name, enum t type, int active_func_ptr, string struct_name, int pointer, vector<int> dimlist);
	enum t get_result_type(int fnptr);
	void check_param_type(int call_func_ptr, int param_no, enum t eletype, bool &ok, string struct_name);
	enum t get_variable_type(string name, int active_func_ptr, int level);
	void search_struct(string name,bool &found, int &strptr);
	void enter_struct(string name ,int &strptr);
	void search_struct_var(string name, int active_struct_ptr , bool &found, variable* &vn);
	void enter_struct_var(string name, int active_struct_ptr, variable * &vnptr, vector<int> dimlist, int pointer);
%}
%union
{
	res* reslt;
	string* val;
	variable * var;
	vector<int> *list;
	int int_val;
	while_struct *wstruct;
	lhs* lhs_var;
}


/*  *********************** TO BE DONE ******************

1. STAR and ELIST together like int *a allows you to use a[10]




*/ 
%token PLUS MINUS STAR SLASH
%token LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
%token LEFT_CLOSED_BRACKET RIGHT_CLOSED_BRACKET
%token LEFT_OPEN_BRACKET RIGHT_OPEN_BRACKET

%token <val> IDENTIFIER
%token <int_val> NUMBER_INT
%token NUMBER_FLOAT 
%token TYPEDEF
%token INTEGER FLOAT CHAR VOID STRUCT

%token SEMICOLON 

%token OR AND EQUALS LESS_THAN GREATER_THAN 
%token IF NOT WHILE

%token CHARACTER QUOT RETURN COMMA

%right ELSE

%type <lhs_var> lhs br_elist;
%type <wstruct> whileexp;
%type <reslt> result type list_id elist struct_list_id;
%type <var> decl_ids id_arr exp  t_exp f_exp pm_exp aa_exp d_exp func_call;
%type <list> br_dimlist br_param ifexp stmt matched_stmt n_inter body optional_stmt stmt_list;
%type <int_val> paramlist plist mult_star m_inter;

%start code

%%

code:				struct_decl code	
				|	func_defn_decl code
				|	
				;

struct_decl:		str_head LEFT_CURLY_BRACKET dslist RIGHT_CURLY_BRACKET SEMICOLON
													{
														active_struct_ptr = -1;
													}
				;

str_head:			STRUCT IDENTIFIER
													{
														search_struct(*($2),found,strptr);
														if (found)
														{
															error("Structure already declared");
														}
														else 
														{
															enter_struct(*($2),strptr);
														}
														active_struct_ptr = strptr;
													}
				;

func_defn_decl:		func_head func_body
													{
														active_func_ptr = -1;
														level = 0;
													}
				;

func_body:			LEFT_CURLY_BRACKET optional_stmt RIGHT_CURLY_BRACKET
													{
														backpatch(*$2, nextquad);
														quadruple q;
														q.s1 = "func end";
														q.oprnd_1 = q.s2 = q.oprnd_2 = q.s3 = q.oprnd_3 = q.s4 = "";
														gen(q);
													}
				;

optional_stmt:		stmt_list
													{
														$$ = new vector<int>;
														(*$$) = (*$1);
													}
				|
													{
														$$ = new vector<int>;
														(*$$).clear();
													}
				;

func_head:			res_id LEFT_OPEN_BRACKET decl_plist RIGHT_OPEN_BRACKET
															{
																level = 2;
															}
				;

res_id:				result mult_star IDENTIFIER	{
													search_func(*$3, found, namptr);
													if(found)
													{
														error("Function already declared");
													}
													else
													{
														enter_func(*$3, $1->type, namptr, $1->struct_name);
														quadruple q;
														q.s1 = "func begin";
														q.oprnd_1 = *$3;
														q.s2 = q.oprnd_2 = q.s3 = q.oprnd_3 = q.s4 = "";
														gen(q);
													}
													active_func_ptr = namptr;
													level = 1;
												}
				;

result:				INTEGER				
								{
									$$ = new res;
									$$->type = INT;
									$$->struct_name = "";
								}
				|	FLOAT				
								{
									$$ = new res;
									$$->type = REAL;
									$$->struct_name = "";
								}
				|	CHAR				
								{
									$$ = new res;
									$$->type = CHA;
									$$->struct_name = "";
								}
				|	VOID				
								{
									$$ = new res;
									$$->type = VOI;
									$$->struct_name = "";
								}
				|	STRUCT IDENTIFIER	{
											$$ = new res;
											$$->type = STRUC;
											$$->struct_name = *$2;
										}
				;

decl_plist:			decl_param COMMA decl_plist
				|	decl_param
				| 	VOID
				|
				;

decl_param:			type decl_ids
									{
										search_param($2->name, active_func_ptr, found, pnptr);
										if(found)
										{
											error("Parameter already declared");
										}
										else
										{
											enter_param($2->name, $1->type, active_func_ptr, $1->struct_name, $2->pointer, *($2->dimlist));
										}
									}
				;

decl_ids:			mult_star IDENTIFIER br_param
													{
														$$ = new variable;
														$$->name = *($2);
														$$->pointer = $1;
														*($$->dimlist) = *($3);
													}
				;

mult_star:			STAR mult_star
							{
								$$ = 1 + $2;
							}
				|	
							{
								$$ = 0;
							}
				;

br_param:			LEFT_CLOSED_BRACKET NUMBER_INT RIGHT_CLOSED_BRACKET br_param
										{
											$$ = new vector<int>;
											(*$$) = *$4;
											(*$$).insert((*$$).begin(), $2);
										}
				|
										{
											$$ = new vector<int>;
											(*$$).clear();
										}
				;

dslist:				struct_declaration
				|	dslist struct_declaration
				;


var_decl:			declaration 
				;

struct_declaration: type struct_list_id SEMICOLON			
														{
															if($1->type!=STRUC)
																patchtype ($1->type,$2->namelist,"");
															else 
																patchtype($1->type,$2->namelist,$1->struct_name);   //todo //function table variablelist and its level
														}		
				;



declaration:		type list_id SEMICOLON			
												{
													if($1->type!=STRUC)
														patchtype ($1->type,$2->namelist,"");
													else 
														patchtype($1->type,$2->namelist,$1->struct_name);   //todo //function table variablelist and its level
												}		
				;								

type:				INTEGER				
								{
									$$ = new res;
									$$->type = INT;
									$$->struct_name = "";
								}
				|	FLOAT		
								{
									$$ = new res;
									$$->type = REAL;
									$$->struct_name = "";
								}	
				|	CHAR				
								{
									$$ = new res;
									$$->type = CHA;
									$$->struct_name = "";
								}
				|	STRUCT IDENTIFIER		
								{
									$$ = new res;
									$$->type = STRUC;
									$$->struct_name = *$2;
								}
				;

struct_list_id:  			id_arr														
															{
																search_struct_var(($1)->name, active_struct_ptr, found, vn);
																$$=new res;
																if(found)
																{
																	error("Variable already declared in the structure");
																}
																else
																{
																	enter_struct_var(($1)->name, active_struct_ptr, vnptr, *(($1)->dimlist), $1->pointer);
																	($$->namelist).push_back(*vnptr);
																}
															}
							| struct_list_id COMMA id_arr														
																{
																	search_struct_var(($3)->name, active_struct_ptr, found, vn);
																	$$=new res;
																	$$->namelist = $1->namelist;
																	if(found)
																	{
																		error("Variable already declared in the structure");
																	}																	
																	else
																	{
																		enter_struct_var(($3)->name, active_struct_ptr, vnptr, *(($3)->dimlist), $3->pointer);
																		($$->namelist).push_back(*vnptr);
																	}
																}
				;

list_id:			id_arr														
							{
								search_var(($1)->name, active_func_ptr, level, found, vn);
								$$=new res;
								if(found && vn->level == level)
								{
									error("Variable already declared at same level");
								}
								else if(level == 2)
								{
									search_param(($1)->name, active_func_ptr, found, pn);
									if(found)
									{
										error("Redeclaration of parameter as a variable");
									}
									else
									{
										enter_var(($1)->name, level, active_func_ptr, vnptr, *(($1)->dimlist), ($1)->pointer);
										($$->namelist).push_back(*vnptr);
									}
								}
								else
								{
									enter_var(($1)->name, level, active_func_ptr, vnptr, *(($1)->dimlist), ($1)->pointer);
									($$->namelist).push_back(*vnptr);
								}
							}
				| 	list_id COMMA id_arr														
							{
								search_var(($3)->name, active_func_ptr, level, found, vn);
								$$=new res;
								$$->namelist = $1->namelist;
								if(found && vn->level == level)
								{
									error("Variable already declared at same level");
								}
								else if(level == 2)
								{
									search_param(($3)->name, active_func_ptr, found, pn);
									if(found)
									{
										error("Redeclaration of parameter as a variable");
									}
									else
									{
										enter_var(($3)->name, level, active_func_ptr, vnptr, *(($3)->dimlist), ($3)->pointer);
										($$->namelist).push_back(*vnptr);
									}
								}
								else
								{
									enter_var(($3)->name, level, active_func_ptr, vnptr, *(($3)->dimlist), ($3)->pointer);
									($$->namelist).push_back(*vnptr);
								}
							}
				;

id_arr:				mult_star IDENTIFIER EQUALS exp		{//doubt
														}
				|	mult_star IDENTIFIER br_dimlist	
																			{
																				$$ = new variable;
																				$$->name = *$2;
																				$$->type = 1;
																				$$->pointer = $1;
																				// $$->var_type = 1; 
																				*($$->dimlist) = *($3);

																			}	
				|	mult_star IDENTIFIER br_dimlist EQUALS LEFT_CURLY_BRACKET elist RIGHT_CURLY_BRACKET			{
																												//doubt
																												}
				|	mult_star IDENTIFIER
							{
								$$ = new variable;
								$$->name = *$2;
								$$->type = 0;
								$$->pointer = $1;
								$$->dimlist = new vector<int>;
								(*($$->dimlist)).clear();
								// $$->var_type = 1;    //todo level 
							}
				;

elist:				exp{
	//doubt yadav
}
				|	exp COMMA elist
				;

br_dimlist:			LEFT_CLOSED_BRACKET NUMBER_INT RIGHT_CLOSED_BRACKET		
																{
																	$$ = new vector<int>;
																	(*$$).insert((*$$).begin(),$2);
																}
				|	LEFT_CLOSED_BRACKET NUMBER_INT RIGHT_CLOSED_BRACKET br_dimlist
																			{
																				$$ = new vector<int>;
																				(*$$) = *$4;
																				(*$$).insert((*$$).begin(),$2);
																			}
				;

body:				LEFT_CURLY_BRACKET {level++;} optional_stmt RIGHT_CURLY_BRACKET
												{
													delete_var_list(active_func_ptr, level);
													level--;
													$$ = new vector<int>;
													(*$$) = (*$3);
												}
				;

stmt_list:			stmt_list m_inter stmt
												{
													backpatch(*$1, $2);
													$$ = new vector<int>;
													(*$$) = (*$3);
												}
				|	stmt
												{
													$$ = new vector<int>;
													(*$$) = (*$1);
												}
				;

stmt:				matched_stmt
				|	ifexp stmt
											{
												$$ = new vector<int>;
												(*$$).reserve((*$1).size() + (*$2).size());
												(*$$).insert((*$$).end(), (*$2).begin(), (*$2).end());
												(*$$).insert((*$$).end(), (*$1).begin(), (*$1).end());
											}
				|	ifexp matched_stmt n_inter ELSE m_inter stmt
											{
												backpatch(*$1, $5);
												$$ = new vector<int>;
												(*$$).reserve((*$2).size() + (*$3).size() + (*$6).size());
												(*$$).insert((*$$).end(), (*$2).begin(), (*$2).end());
												(*$$).insert((*$$).end(), (*$3).begin(), (*$3).end());
												(*$$).insert((*$$).end(), (*$6).begin(), (*$6).end());
											}
				;

n_inter:	
					{
						$$ = new vector<int>;
						(*$$).push_back(nextquad);
						quadruple q;
						q.s1 = "goto";
						q.oprnd_1 = "__";
						q.s2 = q.oprnd_2 = q.s3 = q.oprnd_3 = q.s4 = "";
						gen(q);
					}
			;

m_inter:	
					{
						$$ = nextquad;
					}
			;

matched_stmt:		whileexp body
											{
												quadruple q;
												q.s1 = "goto";
												q.oprnd_1 = $1->begin;
												q.s2 = "";
												q.oprnd_2 = "0";
												q.s3 = "";
												q.oprnd_3 = "";
												q.s4 = "";
												gen(q);
												backpatch(*$2, $1->begin);
												$$ = new vector<int>;
												(*$$) = ($1->falselist);
											}
				|	asg SEMICOLON
											{
												$$ = new vector<int>;
												(*$$).clear();
											}
				|	func_call SEMICOLON
				|	RETURN exp SEMICOLON
											{
												quadruple q;
												q.s1 = "return";
												q.oprnd_1 = $2->name;
												q.s2 = q.oprnd_2 = q.s3 = q.oprnd_3 = q.s4 = "";
												gen(q);
												$$ = new vector<int>;
												(*$$).clear();
											}
				|	RETURN SEMICOLON
											{
												quadruple q;
												q.s1 = "return";
												q.oprnd_1 = "";
												q.s2 = q.oprnd_2 = q.s3 = q.oprnd_3 = q.s4 = "";
												gen(q);
												$$ = new vector<int>;
												(*$$).clear();
											}
				|	body
											{
												$$ = new vector<int>;
												(*$$) = (*$1);
											}
				|	var_decl
				;

ifexp:				IF LEFT_OPEN_BRACKET exp RIGHT_OPEN_BRACKET   		 
					{
						if($3->eletype==CHAR||$3->eletype==ERRORTYPE)
							error("Wrong type in IF statement");
						else
						{
							$$ = new vector<int>;
							(*$$).push_back(nextquad);
							quadruple q;
							q.s1 = "if";
							q.oprnd_1 = $3->name;
							q.s2 = "<=";
							q.oprnd_2 = "0";
							q.s3 = "goto";
							q.oprnd_3 = "__";
							q.s4 = "";
							gen(q);
						}
					}
				;

whileexp:			WHILE m_inter LEFT_OPEN_BRACKET exp	RIGHT_OPEN_BRACKET
								{
									if($4->eletype==CHAR||$4->eletype==ERRORTYPE)
										error("Wrong type in WHILE statement");
									else
									{
										$$ = new while_struct;
										($$->falselist).push_back(nextquad);
										quadruple q;
										q.s1 = "if";
										q.oprnd_1 = $4->name;
										q.s2 = "<=";
										q.oprnd_2 = "0";
										q.s3 = "goto";
										q.oprnd_3 = "__";
										q.s4 = "";
										gen(q);
										$$->begin = $2;
									}
								}
				;

asg:				lhs EQUALS exp				{
									if(($1->place)->eletype!=ERRORTYPE && $3->eletype!=ERRORTYPE)
										if(!coercible(($1->place)->eletype , $3->eletype))
											error("TYPE MISMATCH");
									if((*($1->place->dimlist)).size() == 0)
									{
										quadruple q;
										q.s1 = "";
										q.oprnd_1 = $1->place->name;
										q.s2 = "=";
										q.oprnd_2 = $3->name;
										q.s3 = q.oprnd_3 = q.s4 = "";
										gen(q);
									}
									else
									{
										quadruple q;
										q.s1 = "";
										q.oprnd_1 = ($1->place)->name;
										q.s2 = "[";
										q.oprnd_2 = ($1->offset)->name;
										q.s3 = "]";
										q.oprnd_3 = $3->name;
										q.s4 = "";
										gen(q);
									}
								}
				;

lhs:				IDENTIFIER
												{
													$$ = new lhs;
													$$->offset = NULL;
													($$->place)->pointer = 0;
													search_var(*$1, active_func_ptr, level, found, vn);
													if(!found)
													{
														search_param(*$1, active_func_ptr, found, pn);
														if(!found)
														{
															($$->place)->eletype = ERRORTYPE;
															error("Identifier " + *$1 + " not declared");
														}
														else
														{
															*($$->place) = *pn;
														}
													}
													else
													{
														*($$->offset) = *vn;
													}
												}
				|	br_elist RIGHT_CLOSED_BRACKET
												{
													$$ = new lhs;
													$$->place = new variable;
													*($$->place) = *($1->place);
													$$->offset = new variable;
													($$->offset)->eletype = INT;
													($$->offset)->type = 0;
													($$->offset)->level = level;
													($$->offset)->struct_name = "";
													newtemp($$->offset);
													quadruple q;
													q.s1 = "";
													q.oprnd_1 = ($$->offset)->name;
													q.s2 = "=";
													q.oprnd_2 = ($1->offset)->name;
													q.s3 = "*";
													q.oprnd_3 = get_size(($$->place)->eletype);
													q.s4 = "";
													gen(q);
													// search_var(*$1, active_func_ptr, level, found, vn);
													// if(!found)
													// {
													// 	search_param(*$1, active_func_ptr, found, pn);
													// 	if(!found)
													// 	{
													// 		$$->eletype = ERRORTYPE;
													// 		error("Identifier " + *$1 + " not declared");
													// 	}
													// 	else
													// 	{
													// 		*($$->place) = *pn;
													// 	}
													// }
													// else
													// {
													// 	*($$->place) = *vn;
													// }
													// *($$->offset) = *$2;
												}
				;

br_elist:			br_elist RIGHT_CLOSED_BRACKET LEFT_CLOSED_BRACKET exp
												{
													$$ = new lhs;
													$$->dimnum = $1->dimnum + 1;
													$$->place = new variable;
													*($$->place) = *($1->place);
													int num_elem = get_dim(($1->place)->name, $$->dimnum);
													($$->offset) = new variable;
													($$->offset)->type = 0;
													($$->offset)->eletype = INT;
													($$->offset)->struct_name = "";
													($$->offset)->level = level;
													newtemp($$->offset);
													variable *temp = new variable;
													temp->type = 0;
													temp->eletype = INT;
													temp->struct_name = "";
													temp->level = level;
													newtemp(temp);
													quadruple q;
													q.s1 = "";
													q.oprnd_1 = temp->name;
													q.s2 = "=";
													q.oprnd_2 = ($1->offset)->name;
													q.s3 = "*";
													q.oprnd_3 = num_elem;
													q.s4 = "";
													gen(q);
													q.oprnd_1 = ($$->offset)->name;
													q.oprnd_2 = temp->name;
													q.s3 = "+";
													q.oprnd_3 = $4->name;
													gen(q);
												}
			|		IDENTIFIER LEFT_CLOSED_BRACKET exp
												{
													$$ = new lhs;
													$$->dimnum = 1;
													$$->place = new variable;
													$$->offset = new variable;
													search_var(*$1, active_func_ptr, level, found, vn);
													if(!found)
													{
														search_param(*$1, active_func_ptr, found, pn);
														if(!found)
														{
															($$->place)->eletype = ERRORTYPE;
															error("Identifier " + *$1 + " not declared");
														}
														else
														{
															*($$->place) = *pn;
														}
													}
													else
													{
														*($$->place) = *vn;
													}
													*($$->offset) = *$3;
												}

/*
br_elist:			LEFT_CLOSED_BRACKET exp RIGHT_CLOSED_BRACKET				
															{
																$$ = new variable;
																if($2->eletype != INT)
																{
																	$$->eletype = ERRORTYPE;
																	error("Dimension not an integer.");
																}
																else
																{
																	(*$$) = (*$2);
																}
															}				
				|	LEFT_CLOSED_BRACKET exp RIGHT_CLOSED_BRACKET br_elist
															{
																$$ = new variable;	
																if($2->eletype != INT || $4->type != INT)
																{
																	$$->eletype = ERRORTYPE;
																	error("Dimension not an integer.");
																}
																else
																{
																	$$->eletype = INT;
																	$$->struct_name = "";
																	$$->type = 0;
																	$$->level = level;
																	newtemp($$);
																}
															}				
				;
*/
exp:				exp OR OR aa_exp												{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $4->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $4->eletype) || !compatible_arithop($1->eletype, $4->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = BOOL;
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}
				|	aa_exp															{
																						$$ = new variable;
																						$$->eletype = $1->eletype;
																					}
				;

aa_exp:				d_exp															{
																						$$ = new variable;
																						$$->eletype  = $1->eletype;
																					}
				|	aa_exp AND AND d_exp 											{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $4->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $4->eletype) || !compatible_arithop($1->eletype, $4->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = BOOL;
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}							
				;			

d_exp:				pm_exp															{
																						$$ = new variable;
																						$$->eletype = $1->eletype;
																					}
				|	pm_exp GREATER_THAN pm_exp										{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $3->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $3->eletype) || !compatible_arithop($1->eletype, $3->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = BOOL;
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}							
				|	pm_exp NOT EQUALS pm_exp										{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $4->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $4->eletype) || !compatible_arithop($1->eletype, $4->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = BOOL;
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}		
				|	pm_exp EQUALS EQUALS pm_exp										{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $4->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $4->eletype) || !compatible_arithop($1->eletype, $4->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = BOOL;
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}		
				|	pm_exp LESS_THAN pm_exp											{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $3->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $3->eletype) || !compatible_arithop($1->eletype, $3->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = BOOL;
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}
				|	pm_exp LESS_THAN EQUALS pm_exp									{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $4->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $4->eletype) || !compatible_arithop($1->eletype, $4->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = BOOL;
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}			
				|	pm_exp GREATER_THAN EQUALS pm_exp								{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $4->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $4->eletype) || !compatible_arithop($1->eletype, $4->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = BOOL;
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}			
				|	NOT LEFT_OPEN_BRACKET exp RIGHT_OPEN_BRACKET					{
																						$$ = new variable;
																						$$->type = not_compatible($3->eletype);
																					}					
				;

pm_exp:				pm_exp PLUS t_exp
											{
												$$ = new variable;
												variable *operand1, *operand2;
												operand1 = new variable;
												operand2 = new variable;
												if($1->eletype != ERRORTYPE && $3->eletype != ERRORTYPE)
												{
													if(!coercible($1->eletype, $3->eletype) || !compatible_arithop($1->eletype, $3->eletype))
													{
														error("Type mismatch");
														$$->eletype = ERRORTYPE;
													}
													else
													{
														$$->eletype = compare_types($1->eletype, $3->eletype);
														$$->type = 0;
														$$->struct_name = "";
														$$->level = level;
														newtemp($$);

														if($1->eletype == INT && $$->eletype == REAL)
														{
															operand1->eletype = REAL;
															operand1->type = 0;
															operand1->level = level;
															operand1->struct_name = "";
															newtemp(operand1);
															quadruple q;
															q.s1 = "";
															q.oprnd_1 = operand1->name;
															q.s2 = "= cnvrt_float(";
															q.oprnd_2 = $1->name;
															q.s3 = ")";
															q.oprnd_3 = q.s4 = "";
															gen(q);
														}
														else if($1->eletype == $$->eletype)
														{
															*operand1 = *$1;
														}

														if($3->eletype == INT && $$->eletype == REAL)
														{
															operand2->eletype = REAL;
															operand2->type = 0;
															operand2->level = level;
															operand2->struct_name = "";
															newtemp(operand1);
															quadruple q;
															q.s1 = "";
															q.oprnd_1 = operand2->name;
															q.s2 = "= cnvrt_float(";
															q.oprnd_2 = $3->name;
															q.s3 = ")";
															q.oprnd_3 = q.s4 = "";
															gen(q);
														}
														else if($3->eletype == $$->eletype)
														{
															*operand2 = *$3;
														}

														quadruple q;
														q.s1 = "";
														q.oprnd_1 = $$->name;
														q.s2 = "=";
														q.oprnd_2 = operand1->name;
														q.s3 = "+";
														q.oprnd_3 = operand2->name;
														q.s4 = "";
														gen(q);
													}
												}
												else
												{
													$$->eletype = ERRORTYPE;
												}
											}
				|	pm_exp MINUS t_exp												{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $3->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $3->eletype) || !compatible_arithop($1->eletype, $3->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = compare_types($1->eletype,$3->eletype);																								
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}				
				|	t_exp															{
																						$$ = new variable;
																						$$->eletype = $1->eletype;
																					}
				;

t_exp:				f_exp STAR t_exp												{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $3->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $3->eletype) || !compatible_arithop($1->eletype, $3->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = compare_types($1->eletype,$3->eletype);																								
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}
				|	f_exp SLASH t_exp												{
																						$$ = new variable;
																						if($1->eletype != ERRORTYPE && $3->eletype != ERRORTYPE)
																						{
																							if(!coercible($1->eletype, $3->eletype) || !compatible_arithop($1->eletype, $3->eletype))
																							{
																								error("Type mismatch");
																								$$->eletype = ERRORTYPE;
																							}
																							else
																							{
																								$$->eletype = compare_types($1->eletype,$3->eletype);																								
																							}
																						}
																						else
																						{
																							$$->eletype = ERRORTYPE;
																						}
																					}		
				|	f_exp															{
																						$$ = new variable;
																						$$->eletype = $1->eletype;
																					}						
				;

f_exp:				NUMBER_INT								{
																$$ = new variable;
																$$->eletype = INT;
															}
				|	NUMBER_FLOAT							{	
																$$ = new variable;
																$$->eletype = REAL;
															}
				|	mult_star IDENTIFIER
												{
													$$ = new variable;
													$$->pointer = 1;
													search_var(*$2, active_func_ptr, level, found, vn);
													if(!found)
													{
														search_param(*$2, active_func_ptr, found, pn);
														if(!found)
														{
															$$->eletype = ERRORTYPE;
															error("Identifier " + *$2 + " not declared");
														}
														else
														{
															$$->eletype = pn->eletype;
															$$->pointer = pn->pointer - 1;
														}
													}
													else
													{
														$$->pointer = vn->pointer - 1;
														$$->eletype = vn->eletype;
													}
												}
				|	AND IDENTIFIER
												{
													$$ = new variable;
													$$->pointer = 0;
													search_var(*$2, active_func_ptr, level, found, vn);
													if(!found)
													{
														search_param(*$2, active_func_ptr, found, pn);
														if(!found)
														{
															$$->eletype = ERRORTYPE;
															error("Identifier " + *$2 + " not declared");
														}
														else
														{
															$$->eletype = pn->eletype;
															$$->pointer = pn->pointer + 1;
														}
													}
													else
													{
														$$->pointer = vn->pointer + 1;
														$$->eletype = vn->eletype;
													}
												}
				|	mult_star IDENTIFIER br_elist
												{
													$$ = new variable;
													$$->pointer = $1;
													search_var(*$2, active_func_ptr, level, found, vn);
													if(!found)
													{
														search_param(*$2, active_func_ptr, found, pn);
														if(!found)
														{
															$$->eletype = ERRORTYPE;
															error("Identifier " + *$2 + " not declared");
														}
														else
														{
															$$->eletype = pn->eletype;
															$$->pointer = pn->pointer - $1;
														}
													}
													else
													{
														$$->pointer = vn->pointer - $1;
														$$->eletype = vn->eletype;
													}
												}
				|	AND IDENTIFIER br_elist 
												{
													$$ = new variable;
													$$->pointer = 0;
													search_var(*$2, active_func_ptr, level, found, vn);
													if(!found)
													{
														search_param(*$2, active_func_ptr, found, pn);
														if(!found)
														{
															$$->eletype = ERRORTYPE;
															error("Identifier " + *$2 + " not declared");
														}
														else
														{
															$$->eletype = pn->eletype;
															$$->pointer = pn->pointer + 1;
														}
													}
													else
													{
														$$->pointer = vn->pointer + 1;
														$$->eletype = vn->eletype;
													}
												}
				|	mult_star func_call
															{//pointers to be handled
																if($1 > 0)
																{
																	error("Invalid");//to be more precise
																}
																$$ = new variable;
																$$->eletype = $2->eletype;
															}
				|	LEFT_OPEN_BRACKET exp RIGHT_OPEN_BRACKET				{//pointers
																				$$ = new variable;
																				$$->eletype = $2->eletype;
																			}	
				;

func_call:			IDENTIFIER LEFT_OPEN_BRACKET paramlist RIGHT_OPEN_BRACKET
															{
																$$ = new variable;
																$$->type = 0;
																search_func(*$1, found, fnptr);
																if(!found)
																{
																	$$->eletype = ERRORTYPE;
																	error("Function not declared");
																	call_func_ptr = -1;
																}
																else
																{
																	$$->eletype = get_result_type(fnptr);
																	if($$->eletype == STRUC)
																	{
																		$$->struct_name = global_func[fnptr].struct_name;
																	}
																	call_func_ptr = fnptr;
																	if(global_func[call_func_ptr].num_param != ($3))
																	{
																		error("Mismatch in number of parameters");
																	}
																	else
																	{
																		newtemp($$);
																		quadruple q;
																		q.s1 = "refparam";
																		q.oprnd_1 = $$->name;
																		q.s2 = q.oprnd_2 = q.s3 = q.oprnd_3 = q.s4 = "";
																		gen(q);
																		q.s1 = "call";
																		q.oprnd_1 = *$1;
																		q.s2 = "";
																		q.oprnd_2 = $3 + 1;
																		q.s3 = q.oprnd_3 = q.s4 = "";
																	}
																}
															}
				;

paramlist:			plist
								{
									$$ = $1;
								}
				|				{
									$$ = 0;
								}
				;

plist:				exp COMMA plist
								{
									$$ = $3 + 1;
									check_param_type(call_func_ptr, $$, $1->eletype, ok, "");
									if(!ok)
									{
										error("Parameter type mismatch");
									}
									else
									{
										quadruple q;
										q.s1 = "param";
										q.oprnd_1 = $1->name;
										q.s2 = q.oprnd_2 = q.s3 = q.oprnd_3 = q.s4 = "";
										gen(q);
									}
								}
				|	exp
								{
									$$ = 1;
									check_param_type(call_func_ptr, 1, $1->eletype, ok, "");
									if(!ok)
									{
										error("Parameter type mismatch");
									}
									else
									{
										quadruple q;
										q.s1 = "param";
										q.oprnd_1 = $1->name;
										q.s2 = q.oprnd_2 = q.s3 = q.oprnd_3 = q.s4 = "";
										gen(q);
									}
								}
				;



%%

void yyerror(char *s)
{
	printf("ERROR: %s\n",s);
}
int main()
{
	return yyparse();
}

void patchtype(enum t type,vector <variable> &namelist,string name)
{
	for(int i=0;i<namelist.size();i++)
	{
		namelist[i].eletype = type;
		if(type==STRUC)
		{
			namelist[i].struct_name = name;
		}
	}
}
void error (string err)
{
	cout<<err<<endl;

}
int coercible(enum t type1, enum t type2)
{
	return 1;
}

enum t not_compatible(enum t type)
{
	if(type == ERRORTYPE || type == REAL)
		return ERRORTYPE;
	else
		return type;
}
enum t compare_types(enum t type1,enum t type2)
{
	return INT;
}
bool compatible_arithop(enum t type1, enum t type2)
{
	return true;
}

void search_func(string name, bool &found, int &namptr)
{
	found = false;
	namptr = -1;
	for(int i = 0; i < global_func.size(); i++)
	{
		if(global_func[i].name == name)
		{
			found = true;
			namptr = i;
			return;
		}
	}
}

void enter_func(string name, enum t type, int &namptr, string struct_name)
{
	func_name_table temp;
	temp.name = name;
	temp.res_type = type;
	temp.num_param = 0;
	temp.param_list.clear();
	temp.var_list.clear();
	temp.struct_name = struct_name;
	global_func.push_back(temp);
	namptr = global_func.size() - 1;
}

bool compare(variable &a, variable &b)
{
	if(a.level < b.level)
		return true;
	return false;
}

void search_var(string name, int active_func_ptr, int level, bool &found, variable* &vn)
{
	found = false;
	vn = NULL;
	int cur_level = -1;
	// sort(global_func[active_func_ptr].var_list.begin(), global_func[active_func_ptr].var_list.end(), compare);
	for(int i = global_func[active_func_ptr].var_list.size() - 1; i >= 0; i--)
	{
		if(level < global_func[active_func_ptr].var_list[i].level)
		{
			continue;
		}
		if(global_func[active_func_ptr].var_list[i].name == name)
		{
			if(cur_level < global_func[active_func_ptr].var_list[i].level)
			{
				cur_level = global_func[active_func_ptr].var_list[i].level;
				vn = &global_func[active_func_ptr].var_list[i];
				found = true;
			}
		}
	}
}

void enter_var(string name, int level, int active_func_ptr, variable* &namptr, vector<int> dimlist, int pointer)
{
	variable temp;
	temp.name = name;
	temp.level = level;
	temp.pointer = pointer;
	*temp.dimlist = dimlist;
	global_func[active_func_ptr].var_list.push_back(temp);
	namptr = &global_func[active_func_ptr].var_list[global_func[active_func_ptr].var_list.size() - 1];
}

void search_param(string name, int active_func_ptr, bool &found, variable* &pn)
{
	found = false;
	namptr = -1;
	for(int i = 0; i < global_func[active_func_ptr].param_list.size(); i++)
	{
		if(global_func[active_func_ptr].param_list[i].name == name)
		{
			found = true;
			pn = &global_func[active_func_ptr].param_list[i];
			return;
		}
	}
}

void delete_var_list(int active_func_ptr, int level)
{
	for(int i = 0; i < global_func[active_func_ptr].var_list.size(); i++)
	{
		if(global_func[active_func_ptr].var_list[i].level == level)
		{
			global_func[active_func_ptr].var_list.erase(global_func[active_func_ptr].var_list.begin() + i);
		}
	}
}

void enter_param(string name, enum t type, int active_func_ptr, string struct_name, int pointer, vector<int> dimlist)
{
	variable temp;
	temp.name = name;
	temp.eletype = type;
	temp.struct_name = struct_name;
	temp.pointer = pointer;
	*temp.dimlist = dimlist;
	global_func[active_func_ptr].param_list.push_back(temp);
}

enum t get_result_type(int fnptr)
{
	return global_func[fnptr].res_type;
}

void check_param_type(int call_func_ptr, int param_no, enum t eletype, bool &ok, string struct_name = "")
{
	if(global_func[active_func_ptr].param_list[param_no].eletype != eletype)
	{
		ok = false;
		return;
	}
	if(eletype != STRUC)
	{
		ok = false;
		return;
	}
	if(global_func[active_func_ptr].param_list[param_no].struct_name == struct_name)
	{
		ok = true;
	}
	else
	{
		ok = false;
	}
}

enum t get_variable_type(string name, int active_func_ptr, int level)
{
	int cur_level = -1;
	enum t type = ERRORTYPE;
	// sort(global_func[active_func_ptr].var_list.begin(), global_func[active_func_ptr].var_list.end(), compare);
	for(int i = global_func[active_func_ptr].var_list.size(); i >= 0; i--)
	{
		if(global_func[active_func_ptr].var_list[i].level > level)
		{
			continue;
		}
		if(global_func[active_func_ptr].var_list[i].name == name)
		{
			if(cur_level < global_func[active_func_ptr].var_list[i].level)
			{
				cur_level = global_func[active_func_ptr].var_list[i].level;
				type = global_func[active_func_ptr].var_list[i].eletype;
			}
		}
	}
	return type;
}
void search_struct(string name,bool &found, int &strptr)
{
	found = false;
	strptr = -1;
	for (int i=0;i<global_struct.size();i++)
	{
		if (global_struct[i].name==name)
		{
			found = true;
			strptr = i;
			return;
		}
	}
}
void enter_struct(string name ,int &strptr)
{
	struct_name_table temp;
	temp.name = name;
	temp.var_list.clear();
	global_struct.push_back(temp);
	strptr = global_struct.size()-1;
}
void search_struct_var(string name, int active_struct_ptr , bool &found, variable* &vn)
{
	cout<<"Check 1"<<endl;
	found = false;
	vn = NULL;
	for(int i=0;i<global_struct[active_struct_ptr].var_list.size();i++)
	{
		if (global_struct[active_struct_ptr].var_list[i].name == name)
		{
			found = true;
			vn = &global_struct[active_struct_ptr].var_list[i];
			return;
		}
	}
}
void enter_struct_var(string name, int active_struct_ptr, variable * &vnptr, vector<int> dimlist, int pointer)
{
	variable temp;
	temp.name = name;
	temp.pointer = pointer;
	*temp.dimlist = dimlist;
	global_struct[active_struct_ptr].var_list.push_back(temp);
	vnptr = &global_struct[active_struct_ptr].var_list[global_struct[active_struct_ptr].var_list.size()-1];
}

void backpatch(vector<int> list, int quad_number)
{
}

void gen(quadruple quad)
{
}

int newtemp(variable *var)
{
}

int get_size(enum t type)
{
}

int get_dim(string name, int dimnum)
{
}