// Now 'struct node' has a synonym called 'node'


#pragma once
#include "color.h"


typedef struct Node
{
    int64_t data;
    struct Node *left;
    struct Node *right;
} node;



node *newnode(int64_t );
void print_tree(node *);


// allocates space for a new node on heap segment and returns a pointer to the allocated memory
node *newnode(int64_t value)
{
    node *ptr = (node *)malloc(sizeof(node));

    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}


// Prints the tree bellow 'root_node'
void print_tree(node *root_node)
{

    // print the node's data
    printf(GREEN"%ld ", root_node->data);


        // print the value there and print the tree bellow if (if exists) by again calling print_tree
        if (root_node->left != NULL)
            //printf(GREEN"%ld ", root_node->left->data); 
            print_tree(root_node->left);


        if (root_node->right != NULL)
            //printf(MAGENTA"%ld ", root_node->right->data);
            print_tree(root_node->right);

}

