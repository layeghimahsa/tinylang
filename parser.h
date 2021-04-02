#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdbool.h>

//DST
enum node_type {PROGRAM, FUNCTION_HEADER, FUNCTION, FUNCTION_CALL, FUNCTION_RET, VARIABLE_DECLARATION, VARIABLE_ASSIGNMENT, IF_STATEMENT, IF_CONDITION, IF_CONDITION_MULTIPLE, ELSE_STATEMENT, EXPRESSION, EXPRESSION_NUMBER, EXPRESSION_IDENTIFIER, EXPRESSION_FUNCTIONCALL};

struct dst_node
{
	enum node_type type;
	char *name;
	char *operator_name;
	int value;
	struct dst_node *down;
	struct dst_node *side;	
};
	
struct dst_node *dst;

//------------------------------------------------------------------------------
	
//symbol table
enum symbol_type {FUCNTION = 0, VARIABLE = 1}; //0 function, 1 variable
struct symbol_node
{
	char *name; //function name or variable name
	enum symbol_type type;
	int value; //for function args or variable value
	char *scope;
	struct symbol_node *next;

};

struct symbol_node *symtable;

	
//------------------------------------------------------------------------------

//P_code generarion 
enum p_code_inst {PUSH, POP, ADD, SUB, MUL, DIV, NOP, JMP, BRCT, BRCF, CALL, RET};
enum p_code_operand_type {REGISTER, CONSTANT, IDENTIFIERS};
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

};

//------------------------------------------------------------------------------
	



// prototypes
struct dst_node* new_dstnode_variabledeclaration(char *n);
struct dst_node* new_dstnode_variableassignment(char *n);
struct dst_node* new_dstnode_functiondeclaration(struct dst_node *dst_ptr);
struct dst_node* new_program_dstnode();
struct dst_node* new_dstnode_expr_number(int val);
struct dst_node* new_dstnode_expr_identifier(char *n);
struct dst_node* new_dstnode_expr(struct dst_node* first, char *n, struct dst_node* second);
struct dst_node* new_dstnode_expr_paranthesis(struct dst_node* first);
struct dst_node* new_dstnode_expr_functioncall(char *n, int val);
struct dst_node* new_dstnode_functioncall(char *n, int val);
struct dst_node* new_dstnode_functionret(char *n, int val);
struct dst_node* new_dstnode_if_condition(char *n, char *operator ,int val);
struct dst_node* new_dstnode_if_condition_multiple(struct dst_node* first, char *operator, struct dst_node* second);
int check_semantics(struct dst_node *dst);
void print_dst(struct dst_node *dst);
struct IR_node *generate_IR(struct dst_node *dst);
int get(struct symbol_node *head, char *n);
//void set(struct symbol_node *head, char *n, int val);
char* getType(int i);
void add_to_symtable(struct symbol_node **symtable, char *n, int val, int type, char *scope);
void print_symboltable(struct symbol_node *symtable);
char* getType_symtbale(int i);
bool is_function_exists(struct symbol_node *symtable, char *n);
bool is_variable_exists(struct symbol_node *symtable, char *n, char *scope);
int check_semantics(struct dst_node *dst);
char *gen_label();

struct IR_node *generate_IR(struct dst_node *dst);
const char* getInstructionName(enum p_code_inst inst);
const char* getOperandType(enum p_code_operand_type type);
const char* getRegisterName(enum p_code_register reg);
void print_IR(struct IR_node *IR);
void print_expr_nested(struct dst_node *dst);


#endif

