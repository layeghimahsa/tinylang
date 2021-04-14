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
	int arg_temp;
	char *if_operator;
%}

//Token Values
%type <dst_ptr> variable_declaration
%type <dst_ptr> variable_assignment
%type <dst_ptr> function_list
%type <dst_ptr> function_header
%type <dst_ptr> function
%type <dst_ptr> if_statement
%type <dst_ptr> if_condition
%type <dst_ptr> if_conditions
%type <dst_ptr> else_statement
%type <dst_ptr> program
%type <dst_ptr> statement_list
%type <dst_ptr> statement
%type <dst_ptr> expr
%type <dst_ptr> function_call
%type <dst_ptr> function_ret


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
%token <identifier_name> EQUAL INEQUAL GREATER LESS GREATEREQUAL LESSEQUAL
%token <identifier_name> ANDS ORS NOTS
%token RETURN
%token IF ELSE
%token MAIN VOID
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
	arg_temp = number_of_args;
	number_of_args = 1; //make this 0 to see what will happen!!!!!!!!!!!!!!!!!!!!!!!!!! , (tested) result-> it seems it should be 1
	counter = 0;
	$$ = node;
	
	mother_function = $2; // This is used for variable scope //this is also for return (updated!)
	//printf("\nmother function is: %s\n", mother_function);
	//add_to_symtable(&symtable, $2, number_of_args, 0, "null");

};

function_args: ARG IDENTIFIER COMMA function_args { number_of_args = number_of_args + counter;}
	     | ARG IDENTIFIER  { counter = 1; } 
	     | VOID {number_of_args = 0;}        
	     ;
	          

variable_declaration: INT IDENTIFIER SC
{
	printf("\nvariable declaration detected\n");
	$$ = new_dstnode_variabledeclaration($2);
	//printf("\n I want to see what is the name of identifier here %s\n", $$->name);
	//add_to_symtable(&symtable, $2, 0, 1, mother_function);
};


variable_assignment: IDENTIFIER ASSIGNMENT expr SC
{
	printf("\nvariable assignment detected\n");
	current_identifier = $1;
	$$ = new_dstnode_variableassignment($1);
	$$->down = $3;
	$$->value = $$->down->value;
	print_expr_nested($3);
	
	//printf("\ncurrent identifier is: %s\n", current_identifier);
	//printf("valueeee: %d\n",current_value);
	//add_to_symtable(symtable, $1, $3);
	 	
} |  IDENTIFIER ASSIGNMENT expr  //this is for function call exception
{ 
	current_identifier = $1;
	$$ = new_dstnode_variableassignment($1);
	$$->down = $3;
	$$->value = $$->down->value;
};


expr: NUMBER  {$$ = new_dstnode_expr_number($1); } //$$->name = current_identifier; current_value = $1;}//add_variable_value(&variablenode, $$->name, $1);}
    | IDENTIFIER {$$ = new_dstnode_expr_identifier($1);}
    | expr PLUS expr {$$ = new_dstnode_expr($1, $2, $3);} 
    | expr MINUS expr {$$ = new_dstnode_expr($1, $2, $3);}
    | expr MULTIPLICATION expr {$$ = new_dstnode_expr($1, $2, $3); }
    | expr DIVISION expr {$$ = new_dstnode_expr($1, $2, $3); }
    | LPAR expr RPAR  {$$ = new_dstnode_expr_paranthesis($2); }
    | function_call {$$ = new_dstnode_expr_functioncall($1->name, $1->value); }; //the value should be changed to function return value!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    

if_statement: IF LPAR if_conditions RPAR LPAR statement_list RPAR
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = "if";
	node->value = 0;
	node->type = IF_STATEMENT;
	node->down = $3;
	(node->down)->side = $6;
	((node->down)->side)->down = NULL;
	$$ = node;

} | IF LPAR if_conditions RPAR LPAR statement_list RPAR else_statement 

{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = "if_else";
	node->value = 0;
	node->type = IF_STATEMENT;
	node->down = $3;
	(node->down)->side = $6;
	((node->down)->side)->down =$8;
	$$ = node;

};

if_conditions: if_condition {$$->down = new_dstnode_if_condition(current_identifier, if_operator, current_value);}
	     | LPAR if_conditions RPAR ANDS LPAR if_conditions RPAR { $$ = new_dstnode_if_condition_multiple($2, $4, $6);}
	     | LPAR if_conditions RPAR ORS LPAR if_conditions RPAR { $$ = new_dstnode_if_condition_multiple($2, $4, $6);}
	     | NOTS LPAR if_conditions RPAR { $$ = new_dstnode_if_condition_multiple_not($3, $1);} ;

if_condition: IDENTIFIER EQUAL NUMBER {$$ = new_dstnode_if_condition($1, $2, $3); current_identifier=$1; if_operator=$2; current_value = $3;}
	   |IDENTIFIER INEQUAL NUMBER {$$ = new_dstnode_if_condition($1, $2, $3); current_identifier=$1; if_operator=$2; current_value =$3;}
	   |IDENTIFIER GREATER NUMBER {$$ = new_dstnode_if_condition($1, $2, $3); current_identifier=$1; if_operator=$2; current_value =$3;}
	   |IDENTIFIER LESS NUMBER {$$ = new_dstnode_if_condition($1, $2, $3);  current_identifier=$1; if_operator = $2; current_value = $3; }
	   |IDENTIFIER GREATEREQUAL NUMBER {$$ = new_dstnode_if_condition($1, $2, $3); current_identifier=$1; if_operator=$2; current_value =$3;}
	   |IDENTIFIER LESSEQUAL NUMBER {$$ = new_dstnode_if_condition($1, $2, $3); current_identifier=$1; if_operator=$2; current_value = $3;};
	   

else_statement: ELSE LPAR statement_list RPAR
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = "else";
	node->value = 0;
	node->type = ELSE_STATEMENT;
	node->down = $3; //I was wondering why here it is ok that else does not have a statement_list. For if statement that is not true.
	node->side = NULL;
	$$ = node;
};
	    

statement: variable_declaration {$$ = $1; printf("\n [VD] name: %s\n",$$->name);}
	 | variable_assignment {$$ = $1; printf("\n [VA] name: %s\n",$$->name);} 
	 | if_statement {$$ = $1; printf("\n [IF] name: %s\n",$$->name);}
	 | else_statement {$$ = $1; printf("\n [EL] name: %s\n",$$->name);}
	 | function_call {$$ = $1; printf("\n [FU] name: %s\n",$$->name);}
	 | function_ret {$$ = $1; printf("\n [RE] name: %s\n",$$->name);};
	 

statement_list: statement statement_list { $1->side = $2; $$ = $1; }
		| { $$ = NULL;};
		
		
function_call: IDENTIFIER LPAR params RPAR SC {
			printf("\ndetecting function call\n");
			$$ = new_dstnode_functioncall($1, number_of_args);
			number_of_args = 1; 
			counter = 0;
		};

params: IDENTIFIER COMMA params { number_of_args = number_of_args + counter;}
	| IDENTIFIER  { counter = 1; } 
	| VOID {number_of_args = 0;}        
	;  
	
function_ret: RETURN LPAR expr RPAR SC { $$ = new_dstnode_functionret(mother_function, arg_temp /*$3->value*/); } //I set func_ret value to function number of args not return value; used for IR later
	     | RETURN expr SC { $$ = new_dstnode_functionret(mother_function, arg_temp);}
	     | RETURN NUMBER { $$ = new_dstnode_functionret(mother_function, arg_temp);};


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
	node->name = "main"; // I changed form "program" to "main" for IR generation purpose
	node->value = 0;
	node->type = PROGRAM;
	node->down = NULL;
	node->side = NULL;
	return node;
}


struct dst_node* new_dstnode_expr_number(int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION_NUMBER;
	node->name = NULL;
	node->operator_name = NULL; //This will be used later for detecting end of nested expr
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_expr_identifier(char *n)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION_IDENTIFIER;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->operator_name = NULL;
	node->value = 0;
	node->down = NULL;
	node->side = NULL;
	return node;

}


struct dst_node* new_dstnode_expr(struct dst_node* first, char *n, struct dst_node* second)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION;
	node->operator_name = (char *) malloc(strlen(n)+1);
	strcpy(node->operator_name,n);
	node->value = 0;
	node->side = first;
	node->side->side = second;
	return node;

}

struct dst_node* new_dstnode_expr_paranthesis(struct dst_node* first)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION_PARANTHESIS;
	node->name = NULL;
	node->operator_name = (char *) malloc(strlen(first->operator_name)+1);
	strcpy(node->operator_name, first->operator_name);
	node->value = 0;
	node->side = first;
	return node;

}


struct dst_node* new_dstnode_expr_functioncall(char *n, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION_FUNCTIONCALL;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}


struct dst_node* new_dstnode_functioncall(char *n, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = FUNCTION_CALL;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_functionret(char *n, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = FUNCTION_RET;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_if_condition(char *n, char *operator ,int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = IF_CONDITION;
	node->value = val;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->operator_name = (char *) malloc(strlen(operator)+1);
	strcpy(node->operator_name,operator);
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_if_condition_multiple(struct dst_node* first, char *operator, struct dst_node* second)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = IF_CONDITION_MULTIPLE;
	node->name = "if_condition_multiple";
	node->operator_name = (char *) malloc(strlen(operator)+1);
	strcpy(node->operator_name,operator);
	node->down = first;
	//printf("\n1. in dst: type of dst node is %s\n", getType(node->side->type));
	(node->down)->side = second;
	//printf("2. in dst: type of dst node is %s\n", getType(node->side->side->type));
	return node;

}

struct dst_node* new_dstnode_if_condition_multiple_not(struct dst_node* first, char *operator)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->down = first;
	node->type = IF_CONDITION_MULTIPLE_NOT;
	node->operator_name = (char *) malloc(strlen(operator)+1);
	strcpy(node->operator_name,operator);
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
	
	return -1000000; //error value for not funding a variable or function 
	//return error!
}



int check_semantics(struct dst_node *dst){
	
	//error types -> 0 = duplicate function
	int error = 0;
	
	//-----------------------------------------1.function declaration------------------------------------
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
			printf("-A function is declered before!\n");
			//return error;
		}else{
			add_to_symtable(&symtable, func_name, func_ptr->value, 0, "null");
		}
		func_ptr = func_ptr->side;
	}
	
	
	//--------------------------------------2.variable declaration----------------------------------------
	struct dst_node *statement_ptr;
	struct dst_node *if_statement_ptr;
	
	func_ptr = dst->down;
	
	while(func_ptr != NULL){
		
		if(func_ptr->down != NULL){
			
			if(func_ptr->down->type == VARIABLE_DECLARATION){
				char * variable_name = func_ptr->down->name;
				char * scope = func_ptr->name;
				
				bool result = is_variable_exists(symtable, variable_name, scope);
				
				if(result == true){
					error += 1; //duplicate variable in matching scope
					printf("- Variable %s is declered before!\n", variable_name);
				} else{
					add_to_symtable(&symtable, variable_name, 0, 1, scope);
				}
			}
			
			if(func_ptr->down->type == IF_STATEMENT){
				if_statement_ptr = ((func_ptr->down)->down)->side;
				if(if_statement_ptr->type == VARIABLE_DECLARATION){
					char * variable_name = if_statement_ptr->name;
					char * scope = func_ptr->down->name;
					
					bool result = is_variable_exists(symtable, variable_name, scope);
					
					if(result == true){
						error += 1; //duplicate variable in matching scope
						printf("- Variable %s is declered before!\n", variable_name);
						//return error;
					} else{
						add_to_symtable(&symtable, variable_name, 0, 1, scope);
					}
				}
			}
			
			//going through all other nodes
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
				if(statement_ptr->side->type == VARIABLE_DECLARATION){
					char * variable_name = statement_ptr->side->name;
					char * scope = func_ptr->name;
					bool result = is_variable_exists(symtable, variable_name, scope);
					if(result == true){
						error += 1; //duplicate variable in matching scope
						printf("- Variable %s is declered before!\n", variable_name);
					}else{
						add_to_symtable(&symtable, variable_name, 0, 1, scope);
					}
				}
				
				
				if(statement_ptr->side->type == IF_STATEMENT){
				
					if_statement_ptr = ((statement_ptr->side)->down)->side;
					if(if_statement_ptr->type == VARIABLE_DECLARATION){
						char * variable_name = if_statement_ptr->name;
						char * scope = statement_ptr->side->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == true){
							error += 1; //duplicate variable in matching scope
							printf("- Variable %s is declered before!\n", variable_name);
							//return error;
						} else{
							add_to_symtable(&symtable, variable_name, 0, 1, scope);
						}
					}
					
					while(if_statement_ptr->side != NULL){
					
						if(if_statement_ptr->side->type == VARIABLE_DECLARATION){
							char * variable_name = if_statement_ptr->side->name;
							char * scope = statement_ptr->side->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == true){
								error += 1; //duplicate variable in matching scope
								printf("- Variable %s is declered before!\n", variable_name);
								//return error;
							} else{
								add_to_symtable(&symtable, variable_name, 0, 1, scope);
							}
						}
						
						if_statement_ptr = if_statement_ptr->side;
					}
				
				}
				
				statement_ptr = statement_ptr->side;
			}
			
		}
		
		func_ptr = func_ptr->side;
	} 
	

	
	//----------------------------------3.function use--------------------------------------------------------
	func_ptr = dst->down;
	
	while(func_ptr != NULL){
		
		if(func_ptr->down != NULL){
		
			//FUNCTION CALL	
			if((func_ptr->down)->type == FUNCTION_CALL ) { 
			
				char * variable_name = (func_ptr->down)->name;
				int arg = (func_ptr->down)->value;
				
				if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){ //first is for arg_number incompatibility and the second one is for not existance 
					error += 1; //function call is not allowed. 
					if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
						printf("- Funcion ' %s 'is not declered\n", variable_name);
					} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
						printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
					}
				}
			
			}
			
			//FUNCTION CALL IN VARIABLE ASSIGNMENT
			if((func_ptr->down)->type == VARIABLE_ASSIGNMENT){
				if(((func_ptr->down)->down)->type == EXPRESSION_FUNCTIONCALL){
					char * variable_name = ((func_ptr->down)->down)->name;
					int arg = ((func_ptr->down)->down)->value;
					if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
						error += 1; //function call is not allowed. 
						if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
							printf("- Funcion ' %s 'is not declered\n", variable_name);
						} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
							printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
						}
					}
				}
			}
			
			//FUNCTION CALL IN IF STATEMENT
			if((func_ptr->down)->type == IF_STATEMENT){
			
				if_statement_ptr = ((func_ptr->down)->down)->side;
				
				if(if_statement_ptr->type ==  FUNCTION_CALL){
				
					char * variable_name = if_statement_ptr->name;
					int arg = if_statement_ptr->value;
				
					if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){   
						error += 1; //function call is not allowed. 
						if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
							printf("- Funcion ' %s 'is not declered\n", variable_name);
						} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
							printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
						}
					}	
				
				} //end of function call 
				
				if(if_statement_ptr->type == VARIABLE_ASSIGNMENT){
					if( (if_statement_ptr->down)->type == EXPRESSION_FUNCTIONCALL){
					
						char * variable_name = ((if_statement_ptr)->down)->name;
						int arg = ((if_statement_ptr)->down)->value;
						if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
							error += 1; //function call is not allowed. 
							if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
								printf("- Funcion ' %s 'is not declered\n", variable_name);
							} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
								printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
							}
						}
					}	
				} //end of variable assignment
				
				while(if_statement_ptr->side != NULL){
				
					if((if_statement_ptr->side)->type ==  FUNCTION_CALL){
				
						char * variable_name = ((if_statement_ptr->side))->name;
						int arg = ((if_statement_ptr->side))->value;
					
						if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){   
							error += 1; //function call is not allowed. 
							if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
								printf("- Funcion ' %s 'is not declered\n", variable_name);
							} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
								printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
							}
						}	
				
					} //end of function call 
				
					if((if_statement_ptr->side)->type == VARIABLE_ASSIGNMENT){
						if( ((if_statement_ptr->side)->down)->type == EXPRESSION_FUNCTIONCALL){
						
							char * variable_name = ((if_statement_ptr->side)->down)->name;
							int arg = (((if_statement_ptr->side))->down)->value;
							if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
								error += 1; //function call is not allowed. 
								if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
									printf("- Funcion ' %s 'is not declered\n", variable_name);
								} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
									printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
								}
							}
						}	
					} //end of variable assignment
					
					if_statement_ptr = if_statement_ptr->side;
				}
			
			}
		
			
			//------------------Going through other statements in function---------------------
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
			
				if((statement_ptr->side)->type == FUNCTION_CALL) {
			
					char * variable_name = (statement_ptr->side)->name;
					int arg = (statement_ptr->side)->value;
				
					if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){ 
						error += 1; //function call is not allowed. 
						if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
							printf("- Funcion ' %s 'is not declered\n", variable_name);
						} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
							printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
						}
					}
			
				}
				
				
				if((statement_ptr->side)->type == VARIABLE_ASSIGNMENT){
					if(((statement_ptr->side)->down)->type == EXPRESSION_FUNCTIONCALL){
						char * variable_name = ((statement_ptr->side)->down)->name;
						int arg = ((statement_ptr->side)->down)->value;
						if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
							error += 1; //function call is not allowed. 
							if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
								printf("- Funcion ' %s 'is not declered\n", variable_name);
							} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
								printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
							}
						}
					}
				}

				
				if((statement_ptr->side)->type == IF_STATEMENT){
			
					if_statement_ptr = ((statement_ptr->side)->down)->side;
					
					if(if_statement_ptr->type ==  FUNCTION_CALL){
					
						char * variable_name = if_statement_ptr->name;
						int arg = if_statement_ptr->value;
					
						if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){   
							error += 1; //function call is not allowed. 
							if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
								printf("- Funcion ' %s 'is not declered\n", variable_name);
							} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
								printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
							}
						}	
					
					} //end of function call 
					
					if(if_statement_ptr->type == VARIABLE_ASSIGNMENT){
						if( (if_statement_ptr->down)->type == EXPRESSION_FUNCTIONCALL){
						
							char * variable_name = (if_statement_ptr->down)->name;
							int arg = ((if_statement_ptr)->down)->value;
							if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
								error += 1; //function call is not allowed. 
								if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
									printf("- Funcion ' %s 'is not declered\n", variable_name);
								} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
									printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
								}
							}
						}	
					} //end of variable assignment
				
					while(if_statement_ptr->side != NULL){
					
						if((if_statement_ptr->side)->type ==  FUNCTION_CALL){
					
							char * variable_name = ((if_statement_ptr->side))->name;
							int arg = ((if_statement_ptr->side))->value;
						
							if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){   
								error += 1; //function call is not allowed. 
								if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
									printf("- Funcion ' %s 'is not declered\n", variable_name);
								} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
									printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
								}
							}	
					
						} //end of function call 
					
						if((if_statement_ptr->side)->type == VARIABLE_ASSIGNMENT){
							if( ((if_statement_ptr->side)->down)->type == EXPRESSION_FUNCTIONCALL){
							
								char * variable_name = ((if_statement_ptr->side)->down)->name;
								int arg = (((if_statement_ptr->side))->down)->value;
								if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
									error += 1; //function call is not allowed. 
									if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
										printf("- Funcion ' %s 'is not declered\n", variable_name);
									} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
										printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
									}
								}
							}	
						} //end of variable assignment
						
						if_statement_ptr = if_statement_ptr->side;
					}
			
				}

				
				statement_ptr = statement_ptr->side;
			}
			
		}
		
		func_ptr = func_ptr->side;
		
	} 
	
		
	//----------------------------------4.variable use--------------------------------------------------------
	
	func_ptr = dst->down;
	struct dst_node *expr_ptr;
	
	while(func_ptr != NULL){
		
		if(func_ptr->down != NULL){
		
			//VARIABLE ASSIGNMENT	
			if((func_ptr->down)->type == VARIABLE_ASSIGNMENT ) { 
			
				char * variable_name = (func_ptr->down)->name;
				char * scope = func_ptr->name;
				
				bool result = is_variable_exists(symtable, variable_name, scope);
				
				if(result == false){
					error += 1; //variable is not declared!
					printf("- Variable %s is not declared before!\n", variable_name);
				} 
				
				expr_ptr = (func_ptr->down)->down;
				if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
						char * variable_name = expr_ptr->name;
						char * scope = func_ptr->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1; 
							printf("- Variable %s is not declared before!\n", variable_name);
						} 
				}
				
				while(expr_ptr->side != NULL){
					if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
						char * variable_name = (expr_ptr->side)->name;
						char * scope = func_ptr->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1; 
							printf("- Variable %s is not declared before!\n", variable_name);
						} 
					}
					
					expr_ptr = expr_ptr->side;
				}
			
			}
			
			//IF STATEMENT
			if(func_ptr->down->type == IF_STATEMENT){
			
				if_statement_ptr = ((func_ptr->down)->down)->side;
				
				if(if_statement_ptr->type == VARIABLE_ASSIGNMENT){
					char * variable_name = if_statement_ptr->name;
					char * scope = func_ptr->down->name; //it should changeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee. maybe there are so many if else
					
					bool result = is_variable_exists(symtable, variable_name, scope);
					
					if(result == false){
						error += 1;
						printf("- Variable %s is not declared before!\n", variable_name);
					} 
					
					expr_ptr = if_statement_ptr->down;
					if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
							char * variable_name = expr_ptr->name;
							char * scope = func_ptr->down->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1; 
								printf("- Variable %s is not declared before!\n", variable_name);
							} 
					}
					
					while(expr_ptr->side != NULL){
						if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
							char * variable_name = (expr_ptr->side)->name;
							char * scope = func_ptr->down->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1; 
								printf("- Variable %s is not declared before!\n", variable_name);
							} 
						}
						
						expr_ptr = expr_ptr->side;
					}
			
						
				}
				
				while(if_statement_ptr->side != NULL){
					if(if_statement_ptr->side->type == VARIABLE_ASSIGNMENT){
						char * variable_name = if_statement_ptr->side->name;
						char * scope = func_ptr->down->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1;
							printf("- Variable %s is not declared before!\n", variable_name);
						}
						
						expr_ptr = if_statement_ptr->side->down;
						if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
								char * variable_name = expr_ptr->name;
								char * scope = func_ptr->down->name;
								
								bool result = is_variable_exists(symtable, variable_name, scope);
								
								if(result == false){
									error += 1; 
									printf("- Variable %s is not declared before!\n", variable_name);
								} 
						}
						
						while(expr_ptr->side != NULL){
							if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
								char * variable_name = (expr_ptr->side)->name;
								char * scope = func_ptr->down->name;
								
								bool result = is_variable_exists(symtable, variable_name, scope);
								
								if(result == false){
									error += 1; 
									printf("- Variable %s is not declared before!\n", variable_name);
								} 
							}
							
							expr_ptr = expr_ptr->side;
						}
					}
					
					if_statement_ptr = if_statement_ptr->side;
				}
					
			}//end of if statement case
			
			
			
			//going through all other nodes
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
				
				//VARIABLE ASSIGNMENT	
				if(statement_ptr->side->type == VARIABLE_ASSIGNMENT ) { 
					
					char * variable_name = statement_ptr->side->name;
					char * scope = func_ptr->name;
						
					bool result = is_variable_exists(symtable, variable_name, scope);
						
					if(result == false){
						error += 1; //variable is not declared!
						printf("- Variable %s is not declared before!\n", variable_name);
					} 
						
					expr_ptr = statement_ptr->side->down;
					if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
						char * variable_name = expr_ptr->name;
						char * scope = func_ptr->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1; 
							printf("- Variable %s is not declared before!\n", variable_name);
						} 
					}
						
					while(expr_ptr->side != NULL){
						if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
							char * variable_name = (expr_ptr->side)->name;
							char * scope = func_ptr->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1; 
								printf("- Variable %s is not declared before!\n", variable_name);
							} 
						}
							
						expr_ptr = expr_ptr->side;
					}
				
				}
				
				//IF STATEMENT
				if(statement_ptr->side->type == IF_STATEMENT){
				
					if_statement_ptr = ((statement_ptr->side)->down)->side;
					
					if(if_statement_ptr->type == VARIABLE_ASSIGNMENT){
						char * variable_name = if_statement_ptr->name;
						char * scope = statement_ptr->side->name; //it should changeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee. maybe there are so many if else
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1;
							printf("- Variable %s is not declared before!\n", variable_name);
						} 
						
						expr_ptr = if_statement_ptr->down;
						if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
							char * variable_name = expr_ptr->name;
							char * scope = func_ptr->down->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1; 
								printf("- Variable %s is not declared before!\n", variable_name);
							} 
						}
						
						while(expr_ptr->side != NULL){
							if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
								char * variable_name = (expr_ptr->side)->name;
								char * scope = statement_ptr->side->name;
								
								bool result = is_variable_exists(symtable, variable_name, scope);
								
								if(result == false){
									error += 1; 
									printf("- Variable %s is not declared before!\n", variable_name);
								} 
							}
							
							expr_ptr = expr_ptr->side;
						}
				
							
					}
					
					while(if_statement_ptr->side != NULL){
						if(if_statement_ptr->side->type == VARIABLE_ASSIGNMENT){
							char * variable_name = if_statement_ptr->side->name;
							char * scope = statement_ptr->side->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1;
								printf("- Variable %s is not declared before!\n", variable_name);
							}
							
							expr_ptr = if_statement_ptr->side->down;
							if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
								char * variable_name = expr_ptr->name;
								char * scope = statement_ptr->side->name;
								
								bool result = is_variable_exists(symtable, variable_name, scope);
								
								if(result == false){
									error += 1; 
									printf("- Variable %s is not declared before!\n", variable_name);
								} 
							}
							
							while(expr_ptr->side != NULL){
								if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
									char * variable_name = (expr_ptr->side)->name;
									char * scope = statement_ptr->side->name;
									
									bool result = is_variable_exists(symtable, variable_name, scope);
									
									if(result == false){
										error += 1; 
										printf("- Variable %s is not declared before!\n", variable_name);
									} 
								}
								
								expr_ptr = expr_ptr->side;
							}
						}
						
						if_statement_ptr = if_statement_ptr->side;
					}
						
				}//end of if statement case
			
			
				statement_ptr = statement_ptr->side;
			}
			
			
			
				
		
		}
		
		
		func_ptr = func_ptr->side;
		
	} 	
	
	
	return error;
	
	
} //end of check_semantics

void print_dst(struct dst_node *dst){

	struct dst_node *temp;
	struct dst_node *func_ptr;
	struct dst_node *statement_ptr;
	struct dst_node *if_ptr;
	struct dst_node *if_cond;
	struct dst_node *else_ptr;
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
			printf("\n->\n");
			printf("\tname: %s", func_ptr->down->name);
			printf(", type: %s", getType(func_ptr->down->type));
			printf(", value or arg: %d", func_ptr->down->value);
			
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
				printf("\n->\n");
				printf("\tname: %s", statement_ptr->side->name);
				printf(", type: %s", getType(statement_ptr->side->type));
				printf(", value or arg: %d", statement_ptr->side->value);
				
				//printing if statement and statements in if body
				if(statement_ptr->side->type == IF_STATEMENT){
					if_ptr = ((statement_ptr->side)->down)->side;
					if_cond = ((statement_ptr->side)->down)->down;
					else_ptr = if_ptr->down;
					
					if(if_cond != NULL){
						printf("\n->\n");
						printf("\t\tname: %s", if_cond->name);
						printf(", type: %s", getType(if_cond->type));
						printf(", value or arg: %d", if_cond->value);
					}
	
					while(if_cond->side != NULL){
					
						printf("\t\n->\n");
						printf("\t\tname: %s", if_cond->side->name);
						printf(", type: %s", getType(if_cond->side->type));
						printf(", value or arg: %d", if_cond->side->value);
						if_cond = if_cond->side;
					}
					
					if(if_ptr != NULL){
						printf("\n->\n");
						printf("\t\t-------------------------if---------------------------\n\n");
						printf("\t\tname: %s", if_ptr->name);
						printf(", type: %s", getType(if_ptr->type));
						printf(", value or arg: %d", if_ptr->value);
					}
	
					while(if_ptr->side != NULL){
					
						printf("\t\n->\n");
						printf("\t\tname: %s", if_ptr->side->name);
						printf(", type: %s", getType(if_ptr->side->type));
						printf(", value or arg: %d", if_ptr->side->value);
						if_ptr = if_ptr->side;
					}
					
					//printing else statements if available
					
					if( else_ptr != NULL){
						
						else_ptr = else_ptr->down;
						printf("\n->\n");
						printf("\t\t-------------------------else-------------------------\n\n");
						printf("\t\tname: %s", else_ptr->name);
						printf(", type: %s", getType(else_ptr->type));
						printf(", value or arg: %d", else_ptr->value);
						while(else_ptr->side != NULL){
							printf("\n->\n");
							printf("\t\tname: %s", else_ptr->side->name);
							printf(", type: %s", getType(else_ptr->side->type));
							printf(", value or arg: %d", else_ptr->side->value);
							else_ptr = else_ptr->side;
						} 
					}
					
				}
				
				statement_ptr = statement_ptr->side;
			}
		}
		
		func_ptr = func_ptr->side;
		printf("\n---------------------------------------------------------------\n");
	
	}

}


void print_expr_nested(struct dst_node *dst){

	printf("\n------------------------------------------------------------------------------------\n");
	printf("\t\tname: %s", dst->name);
	printf(", type: %s", getType(dst->type));
	printf(", value or arg: %d", dst->value);
	printf(", operator: %s", dst->operator_name);

	while(dst->side != NULL){
		printf("\n------------------------------------------------------------------------------------\n");
		printf("\t\tname: %s", dst->side->name);
		printf(", type: %s", getType(dst->side->type));
		printf(", value or arg: %d", dst->side->value);
		printf(", operator: %s", dst->side->operator_name);
		
		dst = dst->side;
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
		name = "FUNCTION_CALL";
		break;
	case 4:
		name = "FUNCTION_RET";
		break;
	case 5:
		name = "VARIABLE_DECLARATION";
		break;
	case 6: 
		name = "VARIABLE_ASSIGNMENT";
		break;
	case 7: 
		name = "IF_STATEMENT";
		break;
	case 8: 
		name = "IF_CONDITION";
		break;
	case 9:
		name = "IF_CONDITION_MULTIPLE";
		break;
	case 10: 
		name = "IF_CONDITION_MULTIPLE_NOT";
		break;
	case 11:
		name = "ELSE_STATEMENT";
		break;	
	case 12: 
		name = "EXPRESSION";
		break;	
	case 13: 
		name = "EXPRESSION_NUMBER";
		break;	
	case 14: 
		name = "EXPRESSION_IDENTIFIER";
		break;	
	case 15:
		name = "EXPRESSION_FUNCTIONCALL";
		break;
	case 16: 
		name = "EXPRESSION_PARANTHESIS";
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
	

	if(dst == NULL){
		return NULL;
	}

	if(dst->type == PROGRAM){
		printf("in program case.\n");
		struct IR_node *new_prog_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node)); 
		new_prog_IR_node->instruction = CALL;
		new_prog_IR_node->operand_type = IDENTIFIERS;
		new_prog_IR_node->p_code_operand.identifier = dst->name;
		new_prog_IR_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
		char *label_here = gen_label();
		new_prog_IR_node->next->label = label_here;
		new_prog_IR_node->next->instruction = JMP;
		new_prog_IR_node->next->operand_type = IDENTIFIERS;
		new_prog_IR_node->next->p_code_operand.identifier = label_here;
		new_prog_IR_node->next->next = generate_IR(dst->down);
		return new_prog_IR_node;
	}
	
	
	//should have a switch-case for every type of dst node
	switch(dst->type)
	{
	
		case FUNCTION_CALL: ;//this should be changed to function call later
			printf("in function call case.\n");
			struct IR_node *new_func_call_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node)); 
			new_func_call_IR_node->instruction = CALL;
			new_func_call_IR_node->operand_type = IDENTIFIERS;
			new_func_call_IR_node->p_code_operand.identifier = dst->name;
			new_func_call_IR_node->address = dst->value; //my design decison is to put number of function arguments in IR address
			new_func_call_IR_node->next = generate_IR(dst->side);
			return new_func_call_IR_node;
			break;
		
		case FUNCTION_RET: ;//this should be added and definitely be changed.
			printf("in function return case.\n");
			struct IR_node *new_func_ret_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node)); 
			new_func_ret_IR_node->instruction = RET;
			new_func_ret_IR_node->operand_type = CONSTANT;
			new_func_ret_IR_node->p_code_operand.constant = dst->value;
			return new_func_ret_IR_node;
			break;
		
		case FUNCTION: ;
			printf("in function case.");
			char *label_function_begin = gen_label();
			printf("  function begin label : %s \n", label_function_begin);
			struct IR_node *new_func_IR_node = generate_IR(dst->down); //p-code for the first statement in function body
			new_func_IR_node->label = label_function_begin;
			struct IR_node *last_node_func = new_func_IR_node;
			while(last_node_func->next != NULL)
				last_node_func = last_node_func->next;
			last_node_func->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_func->next = generate_IR(dst->side);
			return new_func_IR_node;
			break;
					
		case VARIABLE_ASSIGNMENT: ;
			printf("in variable assignment case.\n");
			struct IR_node *new_IR_node = generate_IR(dst->down);
			struct IR_node *last_node = new_IR_node;
			while(last_node->next != NULL)
				last_node = last_node->next;
			last_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node = last_node->next;
			last_node->instruction = POP;
			last_node->operand_type = IDENTIFIERS;
			last_node->p_code_operand.identifier = strdup(dst->name);
			last_node->next = generate_IR(dst->side);
			return new_IR_node;
			break;
			
		case VARIABLE_DECLARATION: ;
			printf("in variable declaration case.\n");
			
			return generate_IR(dst->side);
			break;
			
		case IF_STATEMENT: ;
			printf("in if statement case.\n");
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
			last_node_IF->next = generate_IR(dst->down->side); //p-code for if body
			struct IR_node *last_node_IF_body = last_node_IF->next;
			while(last_node_IF_body->next != NULL)
				last_node_IF_body = last_node_IF_body->next;
			last_node_IF_body->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_IF_body = last_node_IF_body->next;

			if(((dst->down)->side)->down != NULL){
				last_node_IF_body = generate_IR(((dst->down)->side)->down); //p-code for else
				last_node_IF_body->label = label_if_end; //if_end_label should be assigned to either begining of the else statement or anything after if body finishes
				last_node_IF_body->next = generate_IR(dst->side);
			}else{
				last_node_IF_body = generate_IR(dst->side);
				last_node_IF_body->label = label_if_end; //if_end_label should be assigned to either begining of the else statement or anything after if body finishes
			}

			return new_IF_condition_IR_node;
			break;
		
		case IF_CONDITION: ;
			printf("in if condition case.\n");
			struct IR_node *new_IF_condition_single_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_IF_condition_single_IR_node->instruction = PUSH; 
			new_IF_condition_single_IR_node->operand_type = CONSTANT;
			new_IF_condition_single_IR_node->p_code_operand.constant = dst->value;
			new_IF_condition_single_IR_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_IF_condition_single_IR_node->next->instruction = PUSH; 
			new_IF_condition_single_IR_node->next->operand_type = IDENTIFIERS;
			new_IF_condition_single_IR_node->next->p_code_operand.identifier = dst->name;
			new_IF_condition_single_IR_node->next->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			
			if(strcmp(dst->operator_name,"==") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = EQUALS;
			} else if(strcmp(dst->operator_name,"!=") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = NOTEQUALS;
			} else if(strcmp(dst->operator_name,">") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = GREATER_THAN;
			} else if(strcmp(dst->operator_name,"<") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = LESS_THAN;
			} else if(strcmp(dst->operator_name,">=") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = GREATER_EQUAL;
			} else if(strcmp(dst->operator_name,"<=") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = LESS_EQUAL;
			} 
			
			
			return new_IF_condition_single_IR_node;
			break;
		
		case IF_CONDITION_MULTIPLE: ;
			printf("in if condition multiple case.\n");
			struct IR_node *new_IF_condition_multiple_first_IR_node = generate_IR(dst->down); //p-code for first if condition result
			struct IR_node *last_node_fisrt_if_cond = new_IF_condition_multiple_first_IR_node;
			while(last_node_fisrt_if_cond->next != NULL)
				last_node_fisrt_if_cond = last_node_fisrt_if_cond->next;
			/*last_node_fisrt_if_cond->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_fisrt_if_cond = last_node_fisrt_if_cond->next;
			last_node_fisrt_if_cond->instruction = PUSH; 
			last_node_fisrt_if_cond->operand_type = CONSTANT;
			last_node_fisrt_if_cond->p_code_operand.constant = dst->side->value;*/
			
			
			struct IR_node *new_IF_condition_multiple_second_IR_node = generate_IR(dst->down->side); //p-code for second if condition result
			struct IR_node *last_node_second_if_cond = new_IF_condition_multiple_second_IR_node;
			while(last_node_second_if_cond->next != NULL)
				last_node_second_if_cond = last_node_second_if_cond->next;
			/*last_node_second_if_cond->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_second_if_cond = last_node_second_if_cond->next;
			last_node_second_if_cond->instruction = PUSH; 
			last_node_second_if_cond->operand_type = CONSTANT;
			last_node_second_if_cond->p_code_operand.constant = dst->side->side->value;*/
			
			//last_node_fisrt_if_cond->next = last_node_second_if_cond;
			
			
			struct IR_node *new_operation_cond_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_fisrt_if_cond->next = new_IF_condition_multiple_second_IR_node;
			last_node_second_if_cond->next = new_operation_cond_IR_node;
			//last_node_second_if_cond->next = new_operation_cond_IR_node;
			
			if(strcmp(dst->operator_name,"&&") == 0){
				new_operation_cond_IR_node->instruction = AND;
			} else if(strcmp(dst->operator_name,"||") == 0){
				new_operation_cond_IR_node->instruction = OR;
			} 
			
			return new_IF_condition_multiple_first_IR_node;
			break;
			
			
		case IF_CONDITION_MULTIPLE_NOT: ;
			printf("in if condition not case.\n");
			struct IR_node *new_IF_condition_multiple_not_IR_node = generate_IR(dst->side); //p-code for (not) if condition result
			struct IR_node *last_node_not_if_cond = new_IF_condition_multiple_not_IR_node;
			while(last_node_not_if_cond->next != NULL)
				last_node_not_if_cond = last_node_not_if_cond->next;
			last_node_not_if_cond->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_not_if_cond = last_node_not_if_cond->next;
			last_node_not_if_cond->instruction = PUSH; 
			last_node_not_if_cond->operand_type = CONSTANT;
			last_node_not_if_cond->p_code_operand.constant = dst->side->value;
			
			struct IR_node *new_operation_not_cond_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_not_if_cond->next = new_operation_not_cond_IR_node;
			new_operation_not_cond_IR_node->instruction = NOT;
			
			return new_IF_condition_multiple_not_IR_node;
			break;	
		
			
		case ELSE_STATEMENT: ;
			printf("in else statement case.\n");
			struct IR_node *new_else_IR_node = generate_IR(dst->down); //p-code for else body
			new_else_IR_node->next = generate_IR(dst->side);
			return new_else_IR_node;
			break;
			
			
		case EXPRESSION: ;
			printf("in expression case.\n");
			
			struct IR_node *new_first_expr_IR_node = generate_IR(dst->side); //p-code for first expression result
		
			struct IR_node *new_second_expr_IR_node = generate_IR(dst->side->side); //p-code for second expression result
			

			struct IR_node *new_operation_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));			
			new_first_expr_IR_node->next = new_second_expr_IR_node;
			new_second_expr_IR_node->next = new_operation_IR_node;

			if(strcmp(dst->operator_name,"+") == 0){
				new_operation_IR_node->instruction = ADD;
			} else if(strcmp(dst->operator_name,"-") == 0){
				new_operation_IR_node->instruction = SUB;
			} else if(strcmp(dst->operator_name,"*") == 0){
				new_operation_IR_node->instruction = MUL;
			} else if(strcmp(dst->operator_name,"/") == 0){
				new_operation_IR_node->instruction = DIV;
			}
			
			return new_first_expr_IR_node;
			
			break;
			
			
		case EXPRESSION_PARANTHESIS: ;
			printf("in expression paranthesis case.\n");
			
			struct IR_node *new_first_expr_par_IR_node = generate_IR(dst->side); //p-code for first expression result
		
			struct IR_node *new_operation_par_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_first_expr_par_IR_node->next = new_operation_par_IR_node;
			
			
			if(strcmp(dst->operator_name,"+") == 0){
				new_operation_par_IR_node->instruction = ADD;
			} else if(strcmp(dst->operator_name,"-") == 0){
				new_operation_par_IR_node->instruction = SUB;
			} else if(strcmp(dst->operator_name,"*") == 0){
				new_operation_par_IR_node->instruction = MUL;
			} else if(strcmp(dst->operator_name,"/") == 0){
				new_operation_par_IR_node->instruction = DIV;
			}
			
			return new_first_expr_par_IR_node;
			
			break;
			
		case EXPRESSION_NUMBER: ;
			printf("in expression number case.\n");
			struct IR_node *new_number_expr_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_number_expr_IR_node->instruction = PUSH;
			new_number_expr_IR_node->operand_type = CONSTANT;
			new_number_expr_IR_node->p_code_operand.constant = dst->value;
			return new_number_expr_IR_node;
			break;
			
		case EXPRESSION_IDENTIFIER: ;
			printf("in expression identifier case.\n");
			struct IR_node *new_identifier_expr_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_identifier_expr_IR_node->instruction = PUSH;
			new_identifier_expr_IR_node->operand_type = IDENTIFIERS;
			new_identifier_expr_IR_node->p_code_operand.identifier = dst->name;
			return new_identifier_expr_IR_node;
			break;
			
		case EXPRESSION_FUNCTIONCALL:
			printf("in expression function call case.\n");
			struct IR_node *new_expr_func_call_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node)); 
			new_expr_func_call_IR_node->instruction = CALL;
			new_expr_func_call_IR_node->operand_type = IDENTIFIERS;
			new_expr_func_call_IR_node->p_code_operand.identifier = dst->name;
			new_expr_func_call_IR_node->address = dst->value; //my design decison is to put number of function arguments in IR address
			//new_func_call_IR_node->next = generate_IR(dst->side);
			return new_expr_func_call_IR_node;
		
		case FUNCTION_HEADER: // should never happens
			printf("in function header case.\n");
			break;
		
		default:
			printf("in default case.\n");
			printf("type of dst node is %d\n", dst->type);
			break;	
	
			
					
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


//print IR 

void print_IR(struct IR_node *IR){
	
	
	struct IR_node *current;
	current = IR;
	
	while(current != NULL){
	
		if(current->label != NULL){
			printf(" %s\t", current->label);
		}
		
		enum p_code_inst inst = current->instruction;
		
		if(inst == PUSH || inst == POP  || inst == JMP || inst == BRCT || inst == BRCF || inst == CALL || inst == RET ){
			printf(" %s\t", getInstructionName(current->instruction));
			if(current->operand_type == IDENTIFIERS){
				printf(" %s\n", current->p_code_operand.identifier);
			} else if(current->operand_type == CONSTANT){
				printf(" %d\n", current->p_code_operand.constant);
			} else if(current->operand_type == REGISTER){
				printf(" %s\n", getRegisterName(current->p_code_operand.p_register));
			} else {
				printf("\n");
			}
		}else{
			printf(" %s\n", getInstructionName(current->instruction));
		}
				
		current = current->next;
	}

}

const char* getInstructionName(enum p_code_inst inst) 
{
   switch (inst) 
   {
      case 0: return "PUSH"; break;
      case 1: return "POP"; break;
      case 2: return "ADD"; break;
      case 3: return "SUB"; break;
      case 4: return "MUL"; break;
      case 5: return "DIV"; break;
      case 6: return "NOP"; break;
      case 7: return "JMP"; break;
      case 8: return "BRCT"; break;
      case 9: return "BRCF"; break;
      case 10: return "AND"; break;
      case 11: return "OR"; break;
      case 12: return "NOT"; break;
      case 13: return "EQUALS"; break;
      case 14: return "NOTEQUALS"; break;
      case 15: return "LESS_EQUAL"; break;
      case 16: return "GREATER_EQUAL"; break;
      case 17: return "LESS_THAN"; break;
      case 18: return "GREATER_THAN"; break;
      case 19: return "CALL"; break;
      case 20: return "RET"; break;
      default: break;

   }
}

const char* getOperandType(enum p_code_operand_type type){

	switch (type) 
	   {
	      case REGISTER: return "REGISTER";
	      case CONSTANT: return "CONSTANT";
	      case IDENTIFIERS: return "IDENTIFIERS";
	      
	   }
} 

const char* getRegisterName(enum p_code_register reg){

	switch (reg) 
	   {
	      case PC: return "PC";
	      case SP: return "SP";
	      case BP: return "BP";
	      
	   }
} 



void yyerror(char *s){ fprintf(stderr, " %s\n", s); }


