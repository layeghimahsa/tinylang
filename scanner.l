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
";" {printf(" SC "); return SC;}
"=" {printf(" ASSIGNMENT "); return ASSIGNMENT;}
"==" {printf(" == "); yylval.identifier_name = strdup(yytext);  return EQUAL;}
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
"if" {printf(" IF "); return IF;}
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

