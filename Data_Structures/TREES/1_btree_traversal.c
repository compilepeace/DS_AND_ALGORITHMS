// Author : Abhinav Thakur
// Email  : compilepeace@gmail.com

// Description : There are typically 2 ways in which tree traversal takes place i.e. -
//				 1.	BFT (Breadth First Traversal)
//				 2. DFT (Depth First Traversal)
//				 This program introduces DFT, i.e. Pre-order, In-order and Post-order traversal. 
//				 Creates and prints 7 nodes accordingly.


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include "./headers/tree.h"
#include "./headers/color.h"



int main()
{
	node *root = CreateNode(1);

	root->left = CreateNode(2);
	root->right = CreateNode(3);
	
	root->left->left = CreateNode(4);
	root->left->right = CreateNode(5);
	
	root->right->left = CreateNode(6);
	root->right->right = CreateNode(7);


	fprintf(stdout, GREEN"\n[+]"RESET" In PreOrder  : ");
	PrintPreOrder(root);	
	fprintf(stdout, "\n");

	
	fprintf(stdout, GREEN"[+]"RESET" In InOrder   : " );
	PrintInOrder(root);
	fprintf(stdout, "\n");

	
	fprintf(stdout, GREEN"[+]"RESET" In PostOrder : ");
	PrintPostOrder(root);
	fprintf(stdout, "\n\n");

return 0;
}
