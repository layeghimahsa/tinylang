#ifndef HEADER_FILE
#define HEADER_FILE

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
struct dst_node* new_dstnode_functiondeclaration(struct dst_node *dst_ptr);
struct dst_node* new_program_dstnode();
int check_semantics(struct dst_node *dst);
void print_dst(struct dst_node *dst);
struct IR_node *generate_IR(struct dst_node *dst);
void add_to_symtable(struct symbol_node *head, char *n, int val);
int get(struct symbol_node *head, char *n);
char* getType(int i);

#endif

