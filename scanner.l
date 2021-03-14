%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "parser.tab.h"
%}
digit [0-9]
number [digit]+
letter [a-zA-Z]
%%
"(" {return LPAR; printf("LPAR");}
")" {return RPAR; printf("RPAR");}
"," {return COMMA;}
";" {return SC;}
"=" {return ASSIGNMENT;}
"==" {return EQUAL;}
"!=" {return INEQUAL;}
">" {return GREATER;}
"<" {return LESS;}
">=" {return GREATEREQUAL;}
"<=" {return LESSEQUAL;}
"&&" {return AND;}
"||" {return OR;}
"!"  {return NOT;}
"return" {return RETURN;}
"if" {return IF;}
"else" {return ELSE;}
"func" {return FUNC; printf("FUNC");}
"msin" {return MAIN;}
"arg"  {return ARG; printf("ARG");}
"int" {return INT;}
{number} {yylval.value = atoi(yytext); return NUMBER;}
({letter}|_)({letter}|{digit}|_)* {yylval.identifier_name = strdup(yytext); printf("IDENTIFIER"); return IDENTIFIER;}
[ \t\n]+ ; //whitespace ignore

%%

int yywrap(){
	return 1;
}

