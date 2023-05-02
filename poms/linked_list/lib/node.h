#ifndef NODE_LIB 
#define NODE_LIB

#include "types.h" 


// Creators
node *CreateNode(); 
u_node *CreateUNode(); 


// Some node func
void NodeLink(node *source, node *destination); 
void NodeLinkUNodeUp(node *source, u_node *destination); 
void NodeLinkUNodeDown(node *source, u_node *destination); 

void NodePush(void *ptr1, void *ptr2); 
 
node *NextField(); 
u_node *NodeUp(); 
u_node *NodeDown(); 

u_node *UNodeFlush(); 
node *NodeFlush(); 




#endif 