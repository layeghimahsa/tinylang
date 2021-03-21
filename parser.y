%{
	int yylex(void);
	void yyerror(char *);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "parser.h"
	
	extern int yylineno;
	int number_of_args = 1;
	int counter = 0;
	char *mother_function;
	//------------------------------------------------------------------------------
	
	
	
	//------------------------------------------------------------------------------
	
	//P_code generarion 
	/*enum p_code_inst {PUSH, POP, ADD, SUB, MUL, DIV, NOP, JMP, BRCT, BRCF};
	enum p_code_operand_type {REGISTER, CONSTANT, IDENTIFIER};
	enum p_code_register {PC, SP, BP};
	
	struct IR_node{
		
		char *label;
		int address;
		enum p_code_inst instruction;
		enum p_code_operand_type operand_type;
		
		union
		{
		   char *identifier;
		   int constant;
		   enum p_code_register p_register;
		} p_code_operand;
		
		struct IR_node *next;
	
	};*/
	
	//------------------------------------------------------------------------------
		


%}

//Token Values
%type <dst_ptr> variable_declaration
%type <dst_ptr> variable_assignment
%type <dst_ptr> function_list
%type <dst_ptr> function_header
%type <dst_ptr> function
%type <dst_ptr> if_statement
%type <dst_ptr> else_statement
%type <dst_ptr> program
%type <dst_ptr> statement_list
%type <dst_ptr> statement
%type <value> expr

%union{
	char *identifier_name;
	int value; 
	struct dst_node *dst_ptr;
};

%token <value> NUMBER
%token <identifier_name> IDENTIFIER
%token LPAR RPAR
%token INT
%token FUNC
%token SC COMMA
%token ASSIGNMENT
%token EQUAL INEQUAL GREATER LESS GREATEREQUAL LESSEQUAL
%token AND OR NOT
%token RETURN
%token IF ELSE
%token MAIN
%token ARG
%token COMMENT

%start program


%%

program: function_list
	{
		dst = new_program_dstnode();
		dst->down = $1;
	};
	

function_list:	function function_list {$1->side = $2; $$ = $1; }
		| function {$$ = $1;};
	     
function: function_header LPAR statement_list RPAR
{
	$$ = new_dstnode_functiondeclaration($1);
	$$->down = $3; 
};

function_header: FUNC IDENTIFIER LPAR function_args RPAR
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = $2;
	node->value = number_of_args;
	node->type = FUNCTION_HEADER;
	node->down = NULL;
	node->side = NULL;
	number_of_args = 1;
	counter = 0;
	$$ = node;
	
	mother_function = $2; // This is used for variable scope
	printf("\nmother function is: %s\n", mother_function);
	//add_to_symtable(&symtable, $2, number_of_args, 0, "null");

};

function_args: ARG IDENTIFIER COMMA function_args { number_of_args = number_of_args + counter;}
	     | ARG IDENTIFIER  { counter = 1; }         
	     ;
	          

variable_declaration: INT IDENTIFIER SC
{
	$$ = new_dstnode_variabledeclaration($2);
	//add_to_symtable(&symtable, $2, 0, 1, mother_function);
};


variable_assignment: IDENTIFIER ASSIGNMENT expr SC
{
	$$ = new_dstnode_variableassignment($1, $3);
	//add_to_symtable(symtable, $1, $3);
	 	
};

expr: NUMBER  
    | IDENTIFIER { $$ = get(symtable, $1); }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')'  { $$ = $2; }
;

if_statement: IF LPAR if_conditions RPAR LPAR statement_list RPAR
{
	$$->name = NULL;
	$$->value = 0;
	$$->type = IF_STATEMENT;
	$$->down = $6;
	$$->side = NULL;

};

if_conditions: if_condition
	     | LPAR if_condition RPAR AND if_conditions
	     | LPAR if_condition RPAR OR if_conditions
	     | NOT LPAR if_condition RPAR if_conditions ;

if_condition: IDENTIFIER EQUAL NUMBER 
	    | IDENTIFIER INEQUAL NUMBER
	    | IDENTIFIER GREATER NUMBER
	    | IDENTIFIER LESS NUMBER
	    | IDENTIFIER GREATEREQUAL NUMBER
	    | IDENTIFIER LESSEQUAL NUMBER ;
	   

else_statement: ELSE LPAR statement_list RPAR
{
	$$->name = NULL;
	$$->value = 0;
	$$->type = ELSE_STATEMENT;
	$$->down = $3;
	$$->side = NULL;
};
	    

statement: variable_declaration {$$ = $1;}
	 | variable_assignment {$$ = $1;} 
	 | if_statement {$$ = $1;}
	 | else_statement {$$ = $1;};
	 

statement_list: statement statement_list { $1->side = $2; $$ = $1; }//printf("\n statement listttttttt \n"); 
		| { $$ = NULL;};


%%

struct dst_node* new_dstnode_variabledeclaration(char *n)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = VARIABLE_DECLARATION;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = 0;
	node->down = NULL;
	node->side = NULL;
	return node;
}

struct dst_node* new_dstnode_variableassignment(char *n, int val)
{	
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = VARIABLE_ASSIGNMENT; 
	node->value = val;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->down = NULL;
	node->side = NULL;
	return node;
}

struct dst_node* new_dstnode_functiondeclaration(struct dst_node *dst_ptr)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = FUNCTION;
	node->name = (char *) malloc(strlen(dst_ptr->name)+1);
	strcpy(node->name,dst_ptr->name);
	node->value = dst_ptr->value;
	node->down = NULL;
	node->side = NULL;
	//printf("\n name: %s\n",node->name);
	//printf("value: %d\n",node->value);
	return node;

}

struct dst_node* new_program_dstnode()
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = "program";
	node->value = 0;
	node->type = PROGRAM;
	node->down = NULL;
	node->side = NULL;
	return node;
}

/*void add_to_symtable(struct symbol_node *head, char *n, int value, enum symbol_type type, int arg_num){

	struct symbol_node *current;
	current = head;
	
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = (symbol_node *) malloc(sizeof(symbol_node));
	current->next->value = val;
	current->next->name = (char *) malloc(strlen(n)+1);
	strcpy(current->next->name,n);
	current->next->TYPE = type;
	current->next->arg_number = arg_num;
	current->next->next = NULL;
	return;

}*/



void add_to_symtable(struct symbol_node **symtable, char *n, int val, int type, char *scope){



	struct symbol_node * new_node = (struct symbol_node *) malloc(sizeof(struct symbol_node)); 
	  
	struct symbol_node  *last = *symtable;  
	  
	    /* 2. put in the data  */
	new_node->arg_number = val;
	new_node->name = (char *) malloc(strlen(n)+1);
	strcpy(new_node->name,n);
	new_node->type = type;
	new_node->scope = (char *) malloc(strlen(scope)+1);
	strcpy(new_node->scope,scope);
	new_node->next = NULL; 
	  

	if (*symtable == NULL) 
	{ 
	   *symtable = new_node; 
	   return; 
	} 
	  
	while (last->next != NULL) 
		last = last->next; 
	  
	last->next = new_node; 
	return; 

	
	/*if(symtable == NULL){
		symtable = (struct symbol_node *) malloc(sizeof(struct symbol_node));
		symtable->arg_number = val;
		symtable->name = (char *) malloc(strlen(n)+1);
		strcpy(symtable->name,n);
		symtable->type = type;
		symtable->scope = (char *) malloc(strlen(scope)+1);
		strcpy(symtable->scope,scope);
		symtable->next = NULL;
		printf("the name is %s form add_to_sym \n", symtable->name);
		return;
	}
	
	while(symtable->next != NULL){
		symtable = symtable->next;
	}
	
	symtable->next = (struct symbol_node *) malloc(sizeof(struct symbol_node));
	symtable->next->arg_number = val;
	symtable->next->name = (char *) malloc(strlen(n)+1);
	strcpy(symtable->next->name,n);
	symtable->next->type = type;
	symtable->next->scope = (char *) malloc(strlen(scope)+1);
	strcpy(symtable->next->scope,scope);
	symtable->next->next = NULL;
	
	printf("the name is %s form add_to_sym (not first)\n", symtable->next->name);
	
	return;*/
	

}

int get(struct symbol_node *head, char *n){
	int value;
	struct symbol_node *current;
	current = head;
	
	while(current->next != NULL){
		if(current->name == n){
			return current->arg_number;
		}
		current = current->next;
	}
	
	
	
	
	
	//return error!
}


int check_semantics(struct dst_node *dst){
	
	//error types -> 0 = duplicate function
	int error = 0;
	
	//1.function declaration
	struct dst_node *func_ptr;
	func_ptr = dst->down;
	while(func_ptr != NULL){
		//printf("name: %s\n", func_ptr->name);
		char * func_name = func_ptr->name;
		//printf("name: vatiable %s\n", func_name);
		bool result = is_function_exists(symtable, func_name);
		//printf("bool: %d\n", result);
		if(result == true){
			error += 1; //duplicate function
			//return error;
		}else{
			add_to_symtable(&symtable, func_name, func_ptr->value, 0, "null");
		}
		func_ptr = func_ptr->side;
	}
	
	
	//2.variable declaration
	struct dst_node *statement_ptr;
	
	func_ptr = dst->down;
	
	while(func_ptr != NULL){
		
		if(func_ptr->down != NULL){
			
			if(func_ptr->down->type == VARIABLE_DECLARATION){
				char * variable_name = func_ptr->down->name;
				char * scope = func_ptr->name;
				
				bool result = is_variable_exists(symtable, variable_name, scope);
				
				if(result == true){
					error += 1; //duplicate variable in matching scope
					//return error;
				} else{
					add_to_symtable(&symtable, variable_name, 0, 1, scope);
				}
			}
			
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
				if(statement_ptr->side->type == VARIABLE_DECLARATION){
					char * variable_name = statement_ptr->side->name;
					char * scope = func_ptr->name;
					bool result = is_variable_exists(symtable, variable_name, scope);
					if(result == true){
						error += 1; //duplicate variable in matching scope
						//return error;
					}else{
						add_to_symtable(&symtable, variable_name, 0, 1, scope);
					}
					statement_ptr = statement_ptr->side;
				}
			}
		}
		
		func_ptr = func_ptr->side;
	} 
	
	
	return error;
	
	
}

void print_dst(struct dst_node *dst){

	struct dst_node *temp;
	struct dst_node *func_ptr;
	struct dst_node *statement_ptr;
	temp = dst;
	
	if(temp == NULL){
		printf("The node could not be empty!");
		return;
	}
	
	printf("name: %s\n", temp->name);
	printf("|\n");
	printf("∨\n");
	func_ptr = temp->down;
	
	while(func_ptr != NULL){
			
		printf("name: %s", func_ptr->name);
		printf(", type: %s", getType(func_ptr->type));
		printf(", value or arg: %d", func_ptr->value);
		
		if(func_ptr->down != NULL){
			printf("\t\n->\n");
			printf("\tname: %s", func_ptr->down->name);
			printf("\t, type: %s", getType(func_ptr->down->type));
			printf("\t, value or arg: %d", func_ptr->down->value);
			
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
				printf("\t\n->\n");
				printf("\tname: %s", statement_ptr->side->name);
				printf("\t, type: %s", getType(statement_ptr->side->type));
				printf("\t, value or arg: %d", statement_ptr->side->value);
				statement_ptr = statement_ptr->side;
			}
		}
		
		func_ptr = func_ptr->side;
		printf("\n----------------\n");
	
	}

}

char* getType(int i){

	char * name;
	switch(i){
	
	case 0: 
		name = "PROGRAM";
		break;
	case 1: 
		name = "FUNCTION_HEADER";
		break;
	case 2: 
		name = "FUNCTION";
		break;
	case 3: 
		name = "VARIABLE_DECLARATION";
		break;
	case 4: 
		name = "VARIABLE_ASSIGNMENT";
		break;
	case 5: 
		name = "IF_STATEMENT";
		break;
	case 6: 
		name = "ELSE_STATEMENT";
		break;						
	default: 
		break;	
		
	}
	
	return name;
}		


//*****************************print symbol table********************************

void print_symboltable(struct symbol_node *symtable){
	
	struct symbol_node *current;
	current = symtable;

	
	while(current != NULL){
		
		printf("Type: %s", getType_symtbale(current->type));
		printf(", Name: %s", current->name);
		printf(", Arg Number: %d", current->arg_number);
		printf(", Scope: %s\n", current->scope);
		
		current = current->next;
		
	}

}

char* getType_symtbale(int i){

	char * name;
	switch(i){
	
	case 0: 
		name = "FUNCTION";
		break;
	case 1: 
		name = "VARIABLE";
		break;					
	default: 
		break;	
		
	}
	
	return name;
}		

bool is_function_exists(struct symbol_node *symtable, char *n){
	
	bool exist = false;
	while(symtable != NULL){
		if(strcmp(symtable->name, n) == 0){
			if(symtable->type == 0){
				exist = true;
				return exist;
			}
		}
		symtable = symtable->next;
	}
	
}

bool is_variable_exists(struct symbol_node *symtable, char *n, char *scope){
	
	bool exist = false;
	while(symtable != NULL){
		if(strcmp(symtable->name, n) == 0){
			if(symtable->type == 1){
				if(strcmp(symtable->scope, scope) == 0){
					exist = true;
					return exist;
				}
			}
		}
		symtable = symtable->next;
	}
	
}


/*struct IR_node *generate_IR(struct dst_node *dst){
	
	//If we reached a NULL node, just return NULL as well
	if(dst == (struct dst_node *)0){
		return (struct IR_node *)0;
	}

	if(dst->type == PROGRAM){
		return generate_IR(dst->down);
	}
	
	
	//should have a switch-case for every type of dst node
	switch(dst->type)
	{
		case VARIABLE_ASSIGNMENT:
			struct IR_node *new_IR_node = generate_IR(dst->down);
			struct IR_node *last_node = new_IR_node;
			while(last_node->next != (struct IR_node *)0)
				last_node = last_node->next;
			last_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node = last_node->next;
			last_node->instruction = POP;
			last_node->operand_type = IDENTIFER;
			last_node->p_code_operand.identifier = strdup(dst->name);
			last_node->next = generate_IR(dst->side);
			return new_IR_node;
		break;
	}

}*/

void yyerror(char *s){ fprintf(stderr, " %s\n", s); }


