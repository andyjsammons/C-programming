#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "gnode.h"



typedef struct binTree_struct{
	int height= 0;
	int size = 0;
	gnode* root;
} binTree;


void initialize(binTree* bt);
bool search(binTree* bt, int key);
void insert(binTree* bt, int item);
void printinorder(binTree* bt);
void printpreorder(binTree* bt);
int btsize(binTree* bt);
int treeheight(binTree* bt);



#endif
