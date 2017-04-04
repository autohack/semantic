%{
	#include "my.h"
	#include "y.tab.h"
	int line = 1;

%}

%%

int						return INT;
float					return FLOAT;
char					return CHAR;
void					return VOID;
main					return MAIN;
while					return WHILE;
struct					return STRUCT;
if  					return IF;
else					return ELSE;


[A-Za-z_][A-Z0a-z0-9_]*	return IDENTIFIER;


[0-9]+  |
[0-9]+"."[0-9]+ |
"."[0-9]+ 				return NUMBER;

[\[\]\(\)\{\}\;\,\=\+\-\*\/\<\>\!]	return yytext[0];
[\'][^\']*[\'] 			return STRING;
\n 						{line++;};
[ \t]+					/* ignore whitespace */;

%%