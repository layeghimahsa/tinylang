%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "parser.tab.h"
%}
digit [0-9]
number [digit]+
letter [a-zA-Z]
%%
"(" { return LPAR;}
")" { return RPAR;}
"," { return COMMA;}
";" { return SC;}
"=" { return ASSIGNMENT;}
"==" { yylval.identifier_name = strdup(yytext);  return EQUAL;}
"!=" {yylval.identifier_name = strdup(yytext); return INEQUAL;}
">" {yylval.identifier_name = strdup(yytext); return GREATER;}
"<" {yylval.identifier_name = strdup(yytext); return LESS;}
">=" {yylval.identifier_name = strdup(yytext); return GREATEREQUAL;}
"<=" {yylval.identifier_name = strdup(yytext); return LESSEQUAL;}
"&&" {yylval.identifier_name = strdup(yytext); return ANDS;}
"||" {yylval.identifier_name = strdup(yytext); return ORS;}
"!"  {yylval.identifier_name = strdup(yytext); return NOTS;}
"+" {yylval.identifier_name = strdup(yytext); return PLUS;}
"-" {yylval.identifier_name = strdup(yytext); return MINUS;}
"*" {yylval.identifier_name = strdup(yytext); return MULTIPLICATION;}
"/" {yylval.identifier_name = strdup(yytext); return DIVISION;}
"return" {return RETURN;}
"if" {return IF;}
"else" {return ELSE;}
"func" { return FUNC;}
"msin" {return MAIN;}
"arg"  {return ARG;}
"int" {return INT;}
"void" {return VOID;}
([0-9]+) {yylval.value = atoi(yytext); return NUMBER;}
({letter}|_)({letter}|{digit}|_)* {yylval.identifier_name = strdup(yytext); return IDENTIFIER;}
[ \t\n]+ ; //whitespace ignore
"//".* { /* DO NOTHING */ }

%%

int yywrap(){
	return 1;
}

