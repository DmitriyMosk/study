#ifndef NODE_LIB 
#define NODE_LIB

#include "types.h" 


// Creators
node *CreateNode(); 
u_node *CreateUNode(); 

// DataWorker 
node *NodePush(node *prev); 
u_node *UNodePush(u_node *prev, node *source, const char pos, int data); 

// Some node func
node *NextNode(node *n); 

void NodePop(node *cur); 
void UNodePop(u_node *cur); 

void NodeFlush(node *start_node); 




#endif 