{	
										search_func(IDENTIFIER , found);
										if(found) printf("error same function declared \n");
										else enter_func(IDENTIFIER,result.type,nameptr);
										active_func_ptr = nameptr; 
										level = 1;
									}



ids:				IDENTIFIER{strcpy(id_type,IDENTIFIER);}
					| IDENTIFIER '[' ']' {strcpy(id_type,IDENTIFIER);};

struct gello
{
	
	int b,s[10];
	int a[10];

}ab,ssk[10][10];

	if(2>2)
	{
		int k ;
	}
	if(2>21)
		{
			
		}
	else
	{

	}

decl_param:			datatype IDENTIFIER{
									if(search_param(IDENTIFIER))
										printf("error: parameter already declared\n");
									else
										enter_param(IDENTIFIER);
								};


				{	
										int found = search_func(IDENTIFIER );
										if(found) printf("error : same function declared \n");
										else enter_func(IDENTIFIER,result_type);
										// active_func_ptr = st[limit]; 
										level = 1;
									}


int						{ yylval = yytext;
						  return INT;};


						if(!search_func($1))
														printf("function not declared\n");
													else
													{
														
													}
													
								    while (temp != NULL)
    {
        if(!strcmp(current->var_name,id) && current->level <= level)
            return 1;
        temp = temp->next;
    }


