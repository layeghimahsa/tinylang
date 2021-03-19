#include <stdio.h>
#include "parser.tab.h"
#include "parser.h"

extern FILE *yyin;
extern struct dst_node *dst;
extern struct symbol_node *symtable;

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Undefined input file. Usage: \"<program name> <source file>\"\n");
		return 0;
	}
	
	yyin = fopen(argv[1],"r");
	if(yyin == NULL){
		printf("Could not open input file %s\n",argv[1]);
		return 0;
	}
	

	
	yyparse();
	print_dst(dst);
	printf("------------------------------------------------\n");
	printf("Now it comes to symtable\n");
	print_symboltable(symtable);

}
