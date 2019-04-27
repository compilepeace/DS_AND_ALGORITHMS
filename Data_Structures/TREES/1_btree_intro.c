// Author : Abhinav Thakur
// Email  : compilepeace@gmail.com

// Description : This program creates a simple tree with 7 nodes in it.


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include "tree.h"
#include "color.h"



int main()
{
	node *root = newnode(1);

	root->left = newnode(2);
	root->right = newnode(3);
	
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	
	root->right->left = newnode(6);
	root->right->right = newnode(7);

	print_tree(root);	

return 0;
}
