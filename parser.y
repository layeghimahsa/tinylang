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
	char *current_identifier;
	int current_value;
	
%}

//Token Values
%type <dst_ptr> variable_declaration
%type <dst_ptr> variable_assignment
%type <dst_ptr> function_list
%type <dst_ptr> function_header
%type <dst_ptr> function
%type <dst_ptr> if_statement
%type <dst_ptr> if_conditions
%type <dst_ptr> else_statement
%type <dst_ptr> program
%type <dst_ptr> statement_list
%type <dst_ptr> statement
%type <dst_ptr> expr

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
%token <identifier_name> PLUS MINUS MULTIPLICATION DIVISION
%left PLUS MINUS
%left MULTIPLICATION DIVISION

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
	//printf("\nmother function is: %s\n", mother_function);
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
	current_identifier = $1;
	//printf("current identifier is: %s\n", current_identifier);
	$$ = new_dstnode_variableassignment($1);
	$$->down = $3;
	$$->value = $$->down->value;
	
	printf("\ncurrent identifier is: %s\n", current_identifier);
	printf("valueeee: %d\n",current_value);
	add_variable_value(&variablenode, current_identifier, current_value);
	//add_to_symtable(symtable, $1, $3);
	 	
};


expr: NUMBER  {$$ = new_dstnode_expr_number($1); current_value = $1;}//add_variable_value(&variablenode, $$->name, $1);}
    | IDENTIFIER {$$ = new_dstnode_expr_identifier($1, get_variable_value(variablenode, $1)); current_value = get_variable_value(variablenode, $1);}
    | expr PLUS expr {current_value = $1->value + $3->value; $$ = new_dstnode_expr($1, $2, $3, current_value);}
    | expr MINUS expr {current_value = $1->value - $3->value; $$ = new_dstnode_expr($1, $2, $3, current_value);}
    | expr MULTIPLICATION expr {current_value = $1->value * $3->value; $$ = new_dstnode_expr($1, $2, $3, current_value); }
    | expr DIVISION expr { current_value = $1->value / $3->value; $$ = new_dstnode_expr($1, $2, $3, current_value); }
    | LPAR expr RPAR  {current_value = $2->value; $$ = new_dstnode_expr_pranthesis($2, current_value); }
;

if_statement: IF LPAR if_conditions RPAR LPAR statement_list RPAR
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	$$->name = NULL;
	$$->value = 0;
	$$->type = IF_STATEMENT;
	$$->down = $3;
	$$->side = NULL;
	//($$->down)->side = $6;
	$$->side = $6;

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
	 

statement_list: statement statement_list { $1->side = $2; $$ = $1; }
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

struct dst_node* new_dstnode_variableassignment(char *n)
{	
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = VARIABLE_ASSIGNMENT; 
	node->value = 0;
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


struct dst_node* new_dstnode_expr_number(int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION;
	node->name = NULL;
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_expr_identifier(char *n, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}


struct dst_node* new_dstnode_expr(struct dst_node* first, char *n, struct dst_node* second, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node = first;
	node->value = val;
	node->side = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->side->name = (char *) malloc(strlen(n)+1);
	strcpy(node->side->name,n);
	node->side->side = second;
	return node;

}


struct dst_node* new_dstnode_expr_pranthesis(struct dst_node* first, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node = first;
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}


//--------------------------------------------------------------------------------------------------------------------------

void add_to_symtable(struct symbol_node **symtable, char *n, int val, int type, char *scope){



	struct symbol_node * new_node = (struct symbol_node *) malloc(sizeof(struct symbol_node)); 
	  
	struct symbol_node  *last = *symtable;  
	  
	new_node->value = val;
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


}


void add_variable_value(struct variable_value_node **variablenode, char *n, int val){

	

	struct variable_value_node * new_node = (struct variable_value_node *) malloc(sizeof(struct variable_value_node)); 
	 
	struct variable_value_node  *last = *variablenode; 
	  
	new_node->value = val;
	new_node->name = (char *) malloc(strlen(n)+1);
	strcpy(new_node->name,n);
	new_node->next = NULL; 
	
	if (*variablenode == NULL) 
	{ 
	   *variablenode = new_node; 
	   return; 
	} 
	  
	while (last->next != NULL) 
		last = last->next; 
	  
	last->next = new_node; 
	return; 


}

int get_variable_value(struct variable_value_node *head, char *n){

	int value;
	struct variable_value_node *current;
	current = head;
	
	while(current != NULL){
		if(strcmp(current->name,n) == 0){
			return current->value;
		}
		current = current->next;
	}
	
	//return error!
}

int get(struct symbol_node *head, char *n){
	int value;
	struct symbol_node *current;
	current = head;
	
	while(current->next != NULL){
		if(strcmp(current->name,n) == 0){
			return current->value;
		}
		current = current->next;
	}
	
	
	//return error!
}


/*void set(struct symbol_node *head, char *n, int val){

	struct symbol_node *current;
	current = head;

	while(current->next != NULL){
		if(strcmp(current->name,n) == 0){
			current->value = val;
			return;
		}
		current = current->next;
	}
	
	
	//return error!
}*/

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
					//statement_ptr = statement_ptr->side;
				}
				
				statement_ptr = statement_ptr->side;
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
	
	printf("\nname: %s\n", temp->name);
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
		printf(", Value: %d", current->value);
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


struct IR_node *generate_IR(struct dst_node *dst){
	
	//If we reached a NULL node, just return NULL as well
	if(dst == NULL){
		return (struct IR_node *)0;
	}

	if(dst->type == PROGRAM){
		return generate_IR(dst->down);
	}
	
	
	//should have a switch-case for every type of dst node
	switch(dst->type)
	{
		case VARIABLE_ASSIGNMENT: ;
			struct IR_node *new_IR_node = generate_IR(dst->down);
			struct IR_node *last_node = new_IR_node;
			while(last_node->next != (struct IR_node *)0)
				last_node = last_node->next;
			last_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node = last_node->next;
			last_node->instruction = POP;
			last_node->operand_type = IDENTIFIERS;
			last_node->p_code_operand.identifier = strdup(dst->name);
			last_node->next = generate_IR(dst->side);
			return new_IR_node;
			break;
		/*case VARIABLE_DECLARATION:
			struct IR_node *new_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			struct IR_node *last_node = new_IR_node;
			while(last_node->next != (struct IR_node *)0)
				last_node = last_node->next;
			last_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node = last_node->next;
			last_node->instruction = POP;
			last_node->operand_type = IDENTIFIERS;
			last_node->p_code_operand.identifier = strdup(dst->name);
			last_node->next = generate_IR(dst->side);
			return new_IR_node;
			break;*/
			
		case IF_STATEMENT: ;
			char *label_if_begin = gen_label();
			char *label_if_end = gen_label();
			struct IR_node *new_IF_condition_IR_node = generate_IR(dst->down); //p-code for if condition
			new_IF_condition_IR_node->label = label_if_begin;
			struct IR_node *last_node_IF = new_IF_condition_IR_node;
			while(last_node_IF->next != NULL)
				last_node_IF = last_node_IF->next;
			last_node_IF->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_IF = last_node_IF->next;
			last_node_IF->instruction = BRCF;
			last_node_IF->operand_type = IDENTIFIERS;
			last_node_IF->p_code_operand.identifier = label_if_end;
			last_node_IF->next = generate_IR(dst->side); //p-code for if body
			struct IR_node *last_node_IF_body = last_node_IF->next;
			while(last_node_IF_body->next != NULL)
				last_node_IF_body = last_node_IF_body->next;
			last_node_IF_body->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_IF_body = last_node_IF_body->next;
			last_node_IF_body->instruction = NOP;
			last_node_IF_body->operand_type = REGISTER;
			last_node_IF_body->p_code_operand.p_register = PC;
			break;
		
		//case EXPRESSION:
			
			
			
			
	}

}


//label generation function
char *gen_label()
{
	static int label_counter = 0;
	//asssuming here we just need up to 999 labels
	char *new_label = (char *) malloc(5);
	sprintf(new_label, "L%d", label_counter);
	label_counter++;
	return new_label;

}

void yyerror(char *s){ fprintf(stderr, " %s\n", s); }


