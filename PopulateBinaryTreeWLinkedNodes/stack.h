#ifndef STACK_H
#define STACK_H



typedef struct stack_struct{
	int size;
	Node top;
} Stack;


void initialize(Stack* s);
void push(Stack* s, char* str);
void pop(Stack* s, char* str);
void peek(stack* s, char* str);
bool is_empty(Stack* s);
int getlength(Stack* s);
void display(Stack* s);



#endif

	
	