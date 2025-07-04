#include "BinaryTree.h"
#include "gnode.h"
#include <stdio.h>



void orderprint(gnode node);
void preorderprint(gnode node);
void postorderprint(gnode node);


void postorderprint(gnode node){
	if (node == NULL){
		return;
	}
	postorderprint(node.left);
	postorderprint(node.right);
	printf("%d ", node.data);
}
	


void preorderprint(gnode node){
	
	
	if (node == NULL){
		
		return ;
	}
	printf("%d ", node.data);

	preorderprint(node.left);
	preorderprint(node.right);
		
	
}

void orderprint(gnode node){
	gnode thisNode;
	thisNode = node;
		
	if (node == NULL){
		printf("%d ",node.data);
		return;
	}
	orderprint(node.left);
	printf("%d ", node.data);
	orderprint(node.right);
}



void initialize(binTree* bt){
	
	bt->root = NULL;
	bt->size = 0;
}



bool search(binTree* bt, int key){
	
	gnode ROOT = bt->root;
	
	while (ROOT.left != NULL && ROOT.right){
		if (ROOT.data == key){
			return true;
		}
		else if (key < ROOT.data){
			ROOT = ROOT.left;
		}
		else if (key > ROOT.data){
			ROOT = ROOT.right;
		}
	}
	
	return false;
}


void insert(binTree* bt, int item){
	
	gnode thisNode;
	strcpy(thisNode.data, item);
	
	
	if (bt->root == NULL){
		bt->size++;
		bt->root = thisNode;
		item.right = NULL;
		item.left = NULL;
		
	}
	else{
		node current = bt->root;
		while (current != NULL){
			if (current.data > thisNode.data){
				if (current.left == NULL){
					current.left = thisNode;
					current = NULL;
				}
		
				
			}
		}
		
	else if (item.data > thisNode.data){
		
		thisNode = thisNode.right;
		insert(&thisNode,item);
		
	}
}

void printinorder(binTree*bt){
	
	gnode* thisNode;
	thisNode = bt->root;
	orderprint(*thisNode);
		
}


void printpreorder(binTree* bt){
	
	gnode* thisNode = bt->root;
	preorderprint(*thisNode);
}


void printpostorder(binTree* bt){
	
	gnode* thisNode = bt->root;
	postorderprint(*thisNode);
}


int btsize(binTree* bt){
	return bt->size;
}

//int treeheight(binTree* bt){
	

				
				
				
				
				

				
		