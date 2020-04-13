// Author : Abhinav Thakur
// Email  : compilepeace@gmail.com

// Description : This program aims at performing and printing tree nodes in a  BFT (Breadth First 
//				 Traversal).


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "./headers/tree.h"
#include "./headers/color.h"


int main()
{
	node *root = CreateNode(1);

	root->left = CreateNode(2);
	root->right = CreateNode(3);
	
	root->left->left = CreateNode(4);
	root->left->right = CreateNode(5);
	root->left->right = CreateNode(6);
	root->left->right = CreateNode(7);


	// Print elements via Breadth-First-Traversal
	PrintBFT(root);
}
