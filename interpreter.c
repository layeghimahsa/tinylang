#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "parser.h"
#include "interpreter.h"


void interpret(struct IR_node *IR)
{
	//resolve label addresses in IR
	struct IR_node *IR_label_ptr = IR;
	int addr = 0;
	int nargs;
	while(IR_label_ptr != NULL )
	{
		IR_label_ptr->address = addr;

		if(IR_label_ptr->label != (char *)0 ) //if we have assigned a label to IR instruction
		{
			resolve_label(IR_label_ptr->label, addr, IR);
		}
		IR_label_ptr = IR_label_ptr->next;
		addr++;
	}


	//set up environment
	
	int pc = 0;
	int bp = 0;
	int sp = 0;
	const int STACK_SIZE = 64000;
	int stack[STACK_SIZE];
	struct IR_node *instruction;
	
	//interpretation loop
	//while not at end address
	while(pc != 1)
	{
		//read instruction from IR
		instruction = get_instruction(IR,pc);
		//update environment
		switch(instruction->instruction)
		{
			case PUSH:
				switch(instruction->operand_type)
				{
					case REGISTER: ;
						int to_push;
						if(instruction->p_code_operand.p_register == SP)
							to_push = sp;
						else if(instruction->p_code_operand.p_register == BP)
							to_push = BP;
						else if(instruction->p_code_operand.p_register == PC)
							to_push = PC;
						stack[sp+1] = to_push;
						sp++;
						pc++;
						break;
					
					case CONSTANT:
						stack[sp+1] = instruction->p_code_operand.constant;
						sp++;
						pc++;
						break;
					case IDENTIFIERS: ;
						int identifier_offset;
						identifier_offset = get_offset(instruction->p_code_operand.identifier);
						stack[sp+1] = stack[bp+identifier_offset];
						sp++;
						pc++;
						break;
						
				
				}
				break;
			case POP:
				switch(instruction->operand_type)
				{
					case REGISTER: ;
						int to_pop;
						if(instruction->p_code_operand.p_register == SP)
							to_pop = sp;
						else if(instruction->p_code_operand.p_register == BP)
							to_pop = BP;
						else if(instruction->p_code_operand.p_register == PC)
							to_pop = PC;
						to_pop = stack[sp];
						sp--;
						pc++;
						break;
						
					case IDENTIFIERS: ;
						int identifier_offset;
						identifier_offset = get_offset(instruction->p_code_operand.identifier);
						stack[bp+identifier_offset] = stack[sp];
						sp--;
						pc++;
						break;
						
				
				}
				break;
			case NOP:
				pc++;
				break;
			case ADD:
				stack[sp-1] = stack[sp] + stack[sp-1];
				sp--;
				pc++;
				break;
			case SUB:
				stack[sp-1] = stack[sp] - stack[sp-1];
				sp--;
				pc++;
				break;
			case MUL:
				stack[sp-1] = stack[sp] * stack[sp-1];
				sp--;
				pc++;
				break;
			case DIV:
				stack[sp-1] = stack[sp] / stack[sp-1];
				sp--;
				pc++;
				break;
			case EQUALS:
				stack[sp-1] = ( stack[sp] == stack[sp-1] ) ? 1 : 0;
				sp--;
				pc++;
				break;
			case NOTEQUALS:
				stack[sp-1] = ( stack[sp] != stack[sp-1] ) ? 1 : 0;
				sp--;
				pc++;
				break;
			case LESS_EQUAL:
				stack[sp-1] = ( stack[sp] <= stack[sp-1] ) ? 1 : 0;
				sp--;
				pc++;
				break;
			case GREATER_EQUAL:
				stack[sp-1] = ( stack[sp] >= stack[sp-1] ) ? 1 : 0;
				sp--;
				pc++;
				break;
			case LESS_THAN:
				stack[sp-1] = ( stack[sp] < stack[sp-1] ) ? 1 : 0;
				sp--;
				pc++;
				break;
			case GREATER_THAN:
				stack[sp-1] = ( stack[sp] > stack[sp-1] ) ? 1 : 0;
				sp--;
				pc++;
				break;
			case AND:
				stack[sp-1] = stack[sp] & stack[sp-1];
				sp--;
				pc++;
				break;
			case OR:
				stack[sp-1] = stack[sp] | stack[sp-1];
				sp--;
				pc++;
				break;
			case NOT:
				stack[sp-1] = ( stack[sp-1] ) ? 0 : 1;
				pc++;
				break;
			case JMP:
				pc = instruction->p_code_operand.constant;
				break;
			case BRCT:
				if(stack[sp])
					pc = instruction->p_code_operand.constant;
				else
					pc++;
				sp--;
				break;
			case BRCF:
				if(!stack[sp])
					pc = instruction->p_code_operand.constant;
				else
					pc++;
				sp--;
				break;
			case CALL:
				sp = sp+2;
				nargs = instruction->args;
				stack[sp - nargs] = pc+1;
				stack[sp - nargs - 1] = bp;
				bp = sp - nargs;
				break;
			case RET:  ;
				nargs = instruction->p_code_operand.constant;
				sp = sp - nargs - 2;
				bp  = stack[sp]; //retreiving previous bp
				pc = stack[sp+1]; //retreiving return address
				stack[sp] = stack[sp+2+nargs]; //the return value is being stored here
				break;
		}
		//(optional): print environment
		printf("PC = %d, BP = %d, SP = %d\n",pc,bp,sp);
		printf("instruction = %s\n",to_string(instruction));
		int begin = sp;
		while(begin >= bp)
		{
			printf("\t%d\n",stack[begin]);
			begin--;
		}
	}
	
}


void resolve_label(char *l, int addr, struct IR_node *IR)
{
	struct IR_node *IR_label_ptr = IR;
	printf("label : %s\n", l);
	printf("addrr : %d\n", addr);
	while(IR_label_ptr != NULL)
	{
		if((IR_label_ptr->instruction == JMP) || (IR_label_ptr->instruction == CALL) || (IR_label_ptr->instruction == BRCT) || (IR_label_ptr->instruction == BRCF) )
		{
			if(strcmp(IR_label_ptr->p_code_operand.identifier,l)==0){
				IR_label_ptr->p_code_operand.constant = addr; //we assign an address to each label. address is stored in p_code_operand constant. 
			}
		}
		IR_label_ptr = IR_label_ptr->next;
	}
}

struct IR_node * get_instruction(struct IR_node *IR , int pc){

	while(IR->address != pc){
		IR = IR->next;
	}
	
	return IR;
	/*if((IR->instruction != JMP) && (IR->instruction != BRCT) && (IR->instruction != BRCF) && (IR->instruction != CALL) ){
		next_IR = IR->next;
		return next_IR;
	}*/
	
}

int get_offset(char *n){
	int offset = 0;
	offset += name_exists(node, n);
	return offset;
	
}


int name_exists(struct name_node *node, char *n){
	
	int index = 0;
	while(node != NULL){
		if(strcmp(node->name, n) == 0){
			return node->index;
		}
		node = node->next;
		index++;
	}
	
	add_to_name_node(&node, n, index);
	return index;
	
}


void add_to_name_node(struct name_node **node, char *n, int index){



	struct name_node * new_node = (struct name_node *) malloc(sizeof(struct name_node)); 
	  
	struct name_node  *last = *node;  
	  
	new_node->name = (char *) malloc(strlen(n)+1);
	strcpy(new_node->name,n);
	new_node->index = index;
	new_node->next = NULL; 
	  

	if (*node == NULL) 
	{ 
	   *node = new_node; 
	   return; 
	} 
	  
	while (last->next != NULL) 
		last = last->next; 
	  
	last->next = new_node; 
	return; 


}

char * to_string (struct IR_node *instruction){
	
	char *str;
	
	if(instruction->label != NULL){
		strcat(str, instruction->label);
		strcat(str, "  ");
	}
		
	const char * instr_name;
	enum p_code_inst inst = instruction->instruction;
	
	if(inst == PUSH || inst == POP  || inst == JMP || inst == BRCT || inst == BRCF || inst == CALL || inst == RET ){
		instr_name = getInstructionName(inst);
		strcat(str, instr_name);
		strcat(str, "  ");
		
		if(instruction->operand_type == IDENTIFIERS){
			strcat(str, instruction->p_code_operand.identifier);
		} else if(instruction->operand_type == CONSTANT){
			//char *strint;
			//itoa(instruction->p_code_operand.constant,strint,10);
			strcat(str, "number");
		} else if(instruction->operand_type == REGISTER){
			strcat(str, getRegisterName(instruction->p_code_operand.p_register));
		} else {
			strcat(str, "  ");
		}
	}else{
		instr_name = getInstructionName(inst);
		strcat(str, instr_name);
		strcat(str, "  ");
	}
				
	return str;
}


