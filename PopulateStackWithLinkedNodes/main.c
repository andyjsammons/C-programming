#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "node.h"





int main(){
	Stack s;
	FILE* infile = NULL;
	char c;
	char data[250];
	int index = 0;
	
	infile = fopen("tempfile.txt","r");
	
	if (infile == NULL) {
		printf("Hello- file did not open");
		return -1;
	}
	
	initialize(&s);
	
	while (1){
		
		if (feof(infile)){
			break;
		}
		
		fscanf(infile,"%s",data);
		if (strcmp(data, "-") != 0){
			push(&s, data);
		}
		else if (strcmp(data, "-") == 0){
			pop(&s, data);
		}
		//printf("%s\n",data);
		
	}
	
	peek(&s, data);

	
	return 0;
}