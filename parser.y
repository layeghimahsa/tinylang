%{
	int yylex(void);
	void yyerror(char *);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern int yylineno;
	int number_of_args = 1;
	int counter = 0;

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
	

	
	// prototypes
	struct dst_node* new_dstnode_variabledeclaration(char *n);
	struct dst_node* new_dstnode_variableassignment(char *n, int val);
	struct dst_node* new_dstnode_functiondeclaration(struct dst_node* dst);
	struct dst_node* new_program_dstnode();
	
	


%}

//Token Values
%type <dst_ptr> program
%type <dst_ptr> function
%type <dst_ptr> function_header
%type <dst_ptr> variable_declaration
%type <dst_ptr> variable_assignment
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
%token SC 
%token COMMA
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
	};
	

	     
function: function_header LPAR statement RPAR
	{
		$$ = new_dstnode_functiondeclaration($1);
	
	};

function_header: FUNC IDENTIFIER LPAR function_arg RPAR
		{
			struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
			node->name = $2;
			node->value = 1;
			node->type = FUNCTION_HEADER;
			node->down = NULL;
			node->side = NULL;
			$$ = node;
		};


function_arg: ARG IDENTIFIER;                           
	     
	          

variable_declaration: INT IDENTIFIER SC
{
	$$ = new_dstnode_variabledeclaration($2);
};


variable_assignment: IDENTIFIER ASSIGNMENT expr SC
{
	$$ = new_dstnode_variableassignment($1, $3);
	//add_to_symtable(symtable, $1, $3);
	 	
};

expr: NUMBER  
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')'  { $$ = $2; };


	    

statement: variable_declaration {$$ = $1;}
	 | variable_assignment {$$ = $1;};
	 



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

struct dst_node* new_dstnode_functiondeclaration(struct dst_node* dst)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = FUNCTION;
	node->name = (char *) malloc(strlen(dst->name)+1);
	strcpy(node->name,dst->name);
	node->value = dst->value;
	node->down = NULL;
	node->side = NULL;
	
	printf("name %s\n",node->name);
	printf("value %d\n",node->value);
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





void yyerror(char *s){ fprintf(stderr, " %s\n", s); }


