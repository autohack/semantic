%{
	#include "my.h"
	#include "y.tab.h"
	

%}

%%

int						{ yylval = "int";
						  return INT;};
float					return FLOAT;
char					return CHAR;
void					return VOID;
main					return MAIN;
while					return WHILE;
struct					return STRUCT;
if  					return IF;
else					return ELSE;


[A-Za-z_][A-Z0a-z0-9_]*	{yylval = strdup(yytext);
						return IDENTIFIER;};


[0-9]+  |
[0-9]+"."[0-9]+ |
"."[0-9]+ 				return NUMBER;

[\[\]\(\)\{\}\;\,\=\+\-\*\/\<\>\!]	return yytext[0];

\n 						;
[ \t]+					/* ignore whitespace */;

%%


