#include <stdio.h>
#include "parser.tab.h"
#include "parser.h"
#include "interpreter.h"

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
	
	puts("--------------------------------------------------------------------------------\n");
	puts("                               Printing DST                                     \n");
	puts("--------------------------------------------------------------------------------\n");
	print_dst(dst);
	
	
	//semantic analysis to check validity of code
	//puts("--------------------------------------------------------------------------------\n");
	//puts("                             Check Semantics                                     \n");
	//puts("--------------------------------------------------------------------------------\n");
	
	int errors = check_semantics(dst);
	
	if(errors > 0)
	{
		//puts("--------------------------------------------------------------------------------\n");
		//puts("                             ERROR FOUND!                                       \n");
		//puts("--------------------------------------------------------------------------------\n");
		printf("%d Erros found during semantic analysis.\n",errors);
		return 0;
	}
	
	puts("--------------------------------------------------------------------------------\n");
	puts("                                Printing IR                                     \n");
	puts("--------------------------------------------------------------------------------\n");
	
	
	struct IR_node *IR = NULL;
	IR = generate_IR(dst);
	print_IR(IR);
	
	//interpret(IR);
	
}
