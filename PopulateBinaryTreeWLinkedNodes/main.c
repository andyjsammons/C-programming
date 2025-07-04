#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "gnode.h"



int main(){
	FILE* infile = NULL;
	
	int numbers[10];
	int index;
	
	infile = fopen("myfile.txt","r");
	
	
	
	for (int i = 0; i < 10; i++){
		fscanf(infile,"%d",numbers[i]);
	}
		
		
		
	return 0;
}
		


