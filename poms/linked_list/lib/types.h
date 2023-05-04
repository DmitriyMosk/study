#ifndef TYPES_LIB
#define TYPES_LIB

typedef struct node node_t;
typedef struct u_node unode_t;
typedef unsigned int size_t; 
typedef struct u_node
{
    int *data;
    unode_t *right;
} u_node;

typedef struct node
{
    node_t *right;
    u_node *down;
    u_node *up;
} node;

typedef struct IArray  
{ 
    int *data; 
    size_t len; 
} IArray; 

typedef struct Range
{
    int min; 
    int max; 
} Range;

#endif