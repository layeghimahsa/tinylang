#ifndef INTERPRETER_HEADER_FILE
#define INTERPRETER_HEADER_FILE

#include <stdbool.h>


	
struct name_node //used for get_offset in interpreter
{
	char *name; 
	int index;
	struct name_node *next;

};

struct name_node *node;


void interpret(struct IR_node *IR);
int get_offset(char *n);
int name_exists(struct name_node *node, char *n);
void add_to_name_node(struct name_node **node, char *n, int index);
char * to_string (struct IR_node *instruction);
struct IR_node * get_instruction(struct IR_node *IR , int pc);
void resolve_label(char *l, int addr, struct IR_node *IR);




#endif

