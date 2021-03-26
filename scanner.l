%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "parser.tab.h"
%}
digit [0-9]
number [digit]+
letter [a-zA-Z]
%%
"(" {printf(" LPAR "); return LPAR;}
")" {printf(" RPAR "); return RPAR;}
"," {printf(" COMMA ");return COMMA;}
";" {return SC;}
"=" {printf(" ASSIGNMENT "); return ASSIGNMENT;}
"==" {return EQUAL;}
"!=" {return INEQUAL;}
">" {return GREATER;}
"<" {return LESS;}
">=" {return GREATEREQUAL;}
"<=" {return LESSEQUAL;}
"&&" {return AND;}
"||" {return OR;}
"!"  {return NOT;}
"+" {printf(" PLUS "); return PLUS;}
"-" {return MINUS;}
"*" {return MULTIPLICATION;}
"/" {return DIVISION;}
"return" {return RETURN;}
"if" {return IF;}
"else" {return ELSE;}
"func" {printf(" FUNC "); return FUNC;}
"msin" {return MAIN;}
"arg"  { printf(" ARG "); return ARG;}
"int" {printf(" INT "); return INT;}
"void" {return VOID;}
([0-9]+) {yylval.value = atoi(yytext); printf(" NUMBER "); return NUMBER;}
({letter}|_)({letter}|{digit}|_)* {yylval.identifier_name = strdup(yytext); printf(" IDENTIFIER "); return IDENTIFIER;}
[ \t\n]+ ; //whitespace ignore

%%

int yywrap(){
	return 1;
}

