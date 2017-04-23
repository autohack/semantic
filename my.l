%option noyywrap

%{
	#include "my.h"
	#include "y.tab.h"
	

%}

%%

int						{ strcpy(yylval.fixstr,"int"); return INT;};
float					{  strcpy(yylval.fixstr,"float");return FLOAT;};
char					{ strcpy(yylval.fixstr,"char"); return CHAR;};
void					{strcpy(yylval.fixstr,"void");return VOID;};
main					{strcpy(yylval.fixstr,"main");return MAIN;};
while					{strcpy(yylval.fixstr,"while");return WHILE;};
struct					{strcpy(yylval.fixstr,"struct");return STRUCT;};
if  					{strcpy(yylval.fixstr,"if");return IF;};
else					{strcpy(yylval.fixstr,"else");return ELSE;};


[A-Za-z_][A-Z0a-z0-9_]*	{strcpy(yylval.fixstr,yytext);

						return IDENTIFIER;};


[0-9]+  |
[0-9]+"."[0-9]+ |
"."[0-9]+ 				{  strcpy(yylval.fixstr,yytext);
							return NUMBER;}

[\&\|\[\]\(\)\{\}\;\,\=\+\-\*\/\<\>\!]	return yytext[0];

\n 						;
[ \t]+					/* ignore whitespace */;

%%


