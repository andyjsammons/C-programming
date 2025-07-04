#ifndef STACK_H
#define STACK_H

#include "node.h"



typedef struct stack_struct{
	int size;
	Node* top;
} Stack;


void initialize(Stack* s);
void push(Stack* s, char* str);
void pop(Stack* s, char* str);
void peek(Stack* s, char* str);
bool is_empty(Stack* s);
int get_length(Stack* s);
void display(Stack* s);



#endif

	
	