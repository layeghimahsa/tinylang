%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "parser.tab.h"
	int yylineno;
%}
digit [0-9]
number [digit]+
letter [a-zA-Z]
%%
"(" {return LPAR;}
")" {return RPAR;}
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
"func" {return FUNC;}
"msin" {return MAIN;}
"arg"  {return ARG;}
"int" {return INT;}
{number} {yylval.value = atoi(yytext); return NUMBER;}
({letter}|_)({letter}|{digit}|_)* {yylval.identifier_name = strdup(yytext); return IDENTIFIER;}
^"//"[^\n]*\n {return COMMENT;}
^(.*)\n {++yylineno;}
%%

int yywrap(){
	return 1;
}

