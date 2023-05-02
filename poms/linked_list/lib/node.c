#include "node.h"
#include "malloc.h"

node *CreateNode() 
{ 
    node *root = (node *)malloc(sizeof(node));
    root->right = NULL;     
    root->up = NULL; 
    root->down = NULL;  

    return root; 
}

u_node *CreateUNode()
{ 
    u_node *u_root = (u_node *)malloc(sizeof(u_node)); 
    u_root->data = NULL; 
    u_root->right = NULL; 
}

void NodeLinkUNodeUp(node *source, u_node *destination)
{  
    source->up = destination; 
}

void NodeLinkUNodeDown(node *source, u_node *destination)
{ 
    source->down = destination; 
}

void NodeLink(node *source, node *destination)
{ 
    source->right = destination;
}

void UNodeLink(u_node *source, u_node *destination)
{
    source->right = destination; 
}