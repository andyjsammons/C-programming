#ifndef GNODE_H
#define GNODE_H



typedef struct gnode_struct{
	
	char data[50];
	
	
	gnode_struct* left;
	gnode_struct* right;
	
	
} gnode;




#endif