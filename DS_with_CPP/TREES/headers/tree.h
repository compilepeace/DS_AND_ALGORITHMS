// Now 'struct node' has a synonym called 'node'


#pragma once
#include "color.h"



typedef struct Node
{
    int64_t data;
    struct Node *left;
    struct Node *right;
} node;



node *CreateNode(int64_t );
void PrintBFT(node *);
void PrintPreOrder(node *);
void PrintPostOrder(node *);
void PrintInOrder(node *);



// allocates space for a new node on heap segment and returns a pointer to the allocated memory
node *CreateNode(int64_t value)
{
    node *ptr = (node *)malloc(sizeof(node));

    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}



/*
// Print in Breadth-First-Search Order (i.e. print the nodes level-wise)
void PrintBFT(node *root_node)
{

	if (root_node == NULL)
		return;
	
	else
	{
		// Print root->data
		fprintf(stdout, RED"%ld ", root_node->data);

		// Print root->left
		fprintf(stdout, YELLOW"%ld ", root_node->left->data);
	
		// Print root->right
		fprintf(stdout, GREEN"%ld ", root_node->right->data);
	}
}
*/


// Print in Pre-Order traversal
void PrintPreOrder(node *root_node)
{
	if (root_node == NULL)
		return;


    // print root
    printf(YELLOW"%ld ", root_node->data);

		// Print left
        if (root_node->left != NULL)
            PrintPreOrder(root_node->left);

		// Print right  		
        if (root_node->right != NULL)
            PrintPreOrder(root_node->right);
}



// Print in Post-Order traversal
void PrintPostOrder(node *root_node)
{
	if (root_node == NULL)
		return;
	
	// print left
	if (root_node->left != NULL)
		PrintPostOrder(root_node->left);	

	// print right
	if (root_node->right != NULL)
		PrintPostOrder(root_node->right);

	// Print root
	printf(BLUE"%ld ", root_node->data);
}



// Print in In-Order traversal
void PrintInOrder(node *root_node)
{
	if (root_node == NULL)
		return;

	// print left
	if (root_node->left != NULL)
		PrintInOrder(root_node->left);

	// print root
	printf(RED"%ld ", root_node->data);

	// print right 
	if (root_node->right != NULL)
		PrintInOrder(root_node->right);
}


