#ifndef TYPES_LIB
#define TYPES_LIB

typedef struct u_node
{
    int number;
    u_node *right;
} u_node;

typedef struct node
{
    node *right;
    u_node *down;
    u_node *upper;
} node;



#endif