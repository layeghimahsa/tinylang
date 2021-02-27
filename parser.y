%{
	int yylex(void);
	void yyerror(char *);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	extern int yylineno;
	int number_of_args = 1;

	//------------------------------------------------------------------------------
	
	//DST
	enum node_type {PROGRAM, FUNCTION_HEADER, FUNCTION, VARIABLE_DECLARATION, VARIABLE_ASSIGNMENT, IF_STATEMENT, ELSE_STATEMENT};
	
	struct dst_node
	{
		enum node_type type;
		char *name;
		int value;
		struct dst_node *down;
		struct dst_node *side;	
	};
		
	struct dst_node *dst;
	
	//------------------------------------------------------------------------------
		
	//symbol table
	enum symbol_type {FUCNTION, VARIABLE};
	struct symbol_node
	{
		char *name; //function name or variable name
		enum symbol_type TYPE;
		int value; //for identifier
		int arg_number; //for function
		char *scope;
		struct symbol_node *next;
	
	};
	
	struct symbol_node *symtable;
	
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
	
	// prototypes
	struct dst_node* new_dstnode_variabledeclaration(char *n);
	struct dst_node* new_dstnode_variableassignment(char *n);
	struct dst_node* new_dstnode_functiondeclaration(struct dst_node *dst_ptr);
	struct dst_node* new_program_dstnode();
	int check_semantics(struct dst_node *dst);
	void print_dst(struct dst_node *dst);
	struct IR_node *generate_IR(struct dst_node *dst);
	void add_to_symtable(struct symbol_node *head, struct dst_node *dst_ptr, char *n);
	int get(struct symbol_node *head, char *n);
	
	


%}

//Token Values
%type <identifier_name> variable_declaration
%type <dst_ptr> variable_assignment
%type <dst_ptr> function_header
%type <dst_ptr> function
%type <dst_ptr> if_statement
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

%start program


%%

program: function
	{
		dst = new_program_dstnode();
		dst->down = $1;
	} | ;
	

//function_list:	function function_list {$1->side = $2; $$ = $1; }
//	      | ;
	     
function: function_header LPAR statement_list RPAR
{
	$$ = new_dstnode_functiondeclaration($1);
	$$->down = $3;
};

function_header: FUNC IDENTIFIER LPAR function_args RPAR
{

	$$->name = $2;
	$$->value = number_of_args;
	$$->type = FUNCTION_HEADER;
	$$->down = NULL;
	$$->side = NULL;
	number_of_args = 1;
	 	
};

function_args: function_arg
	     | function_arg COMMA function_args	{ number_of_args += 1; printf("number of args: %d",number_of_args);}
	     ;
	     
function_arg: ARG IDENTIFIER;	     

variable_declaration: INT IDENTIFIER SC
{
	$$ = new_dstnode_variabledeclaration($2);
};


variable_assignment: IDENTIFIER ASSIGNMENT expr SC
{
	$$ = new_dstnode_variableassignment($1);
	$$->down = $3;
	add_to_symtable(symtable, $3, $1);
	 	
};

expr: NUMBER { $$ = $1; $$->value = $1; $$->type = VARIABLE_ASSIGNMENT;}  
    | IDENTIFIER { $$ = $1; $$->value = get(symtable, $1); $$->type = VARIABLE_ASSIGNMENT; }
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
	 | else_statement {$$ = $1;} ;
	 

statement_list: statement statement_list
{
	$1->side = $2;
	$$ = $1;
};


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



void add_to_symtable(struct symbol_node *head, struct dst_node *dst_ptr, char *n){

	struct symbol_node *current;
	current = head;
	
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = (struct symbol_node *) malloc(sizeof(struct symbol_node));
	current->next->value = dst_ptr->value;
	current->next->name = (char *) malloc(strlen(n)+1);
	strcpy(current->next->name,n);
	if(dst_ptr->type == VARIABLE_ASSIGNMENT){
		current->next->TYPE = VARIABLE;
		current->next->arg_number = 0;
	}
	current->next->next = NULL;
	return;

}

int get(struct symbol_node *head, char *n){
	int value;
	struct symbol_node *current;
	current = head;
	
	while(current->next != NULL){
		if(current->name == n){
			return current->value;
		}
		current = current->next;
	}
	
	//return error!
}


int check_semantics(struct dst_node *dst){

}

void print_dst(struct dst_node *dst){
	int i = 0;
	struct dst_node *temp;
	temp = dst;
	while(temp != NULL){
		printf("level %d\n",i);
		printf("name: %s\n",dst->name);
		printf("value: %d\n",dst->value);
		printf("type: %d\n",dst->type);
		/*if (dst->side != NULL){
			printf("level 0.%d\n",i);
			printf("name: %s\n",dst->name);
			printf("value: %d\n",dst->value);
			printf("type: %d\n",dst->type);
		}*/
		temp = temp->down;
		i++;
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

void yyerror(char *s){ fprintf(stderr, "line %d: %s\n", yylineno, s); }


