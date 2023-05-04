#include "node.h"
#include "malloc.h"
#include "stdio.h"

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

    return u_root; 
}

node *NodePush(node *prev)
{ 
    node *inode = CreateNode();

    if(prev != NULL)
        prev->right = inode; 

    return inode; 
}

u_node *UNodePush(u_node *prev, node *source, const char pos, int val)
{ 
    u_node *uinode = CreateUNode(); 

    uinode->data = (int*)val; 

    if(prev != NULL)
        prev->right = uinode;

    if(pos == 'd' && source != NULL)
        source->down = uinode; 
    
    if(pos == 'u' && source != NULL)
        source->up = uinode; 

    return uinode; 
}

node *NextNode(node *n)
{ 
   return n->right;  
}

void UNodePop(u_node *prev)
{ 
    
}

void NodeFlush(node *start_node)
{
    
}