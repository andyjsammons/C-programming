#include "stack.h"
#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




void initialize(Stack* s){
	//Node* newnode = (Node*)malloc(sizeof(Node));
	s->size = 0;
	s->top = NULL;
	
}

void push(Stack* s, char* str){
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (is_empty(s)){
		s->top = newnode;
		strcpy(s->top->data, str);
		newnode->nextNode = NULL;
		
	}
	else{
		//Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->nextNode = s->top;
		strcpy(newnode->data, str);
		s->top = newnode;
	}
	s->size++;
}

void pop(Stack* s, char* str){
	
	Node* tempItem;
	tempItem = s->top->nextNode;
	printf("%s\n",s->top->data);
	free(s->top);
	s->top = tempItem;
	s->size--;
}

void peek(Stack* s, char* str){
	printf("%s ",s->top->data);
	printf("%s\n",s->top->nextNode->data);
}

bool is_empty(Stack* s){
	return s->size == 0;
}

int get_length(Stack* s){
	return s->size;
}





