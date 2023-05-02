#include "stdio.h"
#include "stdlib.h"
#include "time.h" 

#include "lib/types.h" 
#include "lib/node.h"

int main()
{ 
    srand(time(NULL)); 

    size_t counts; 
    printf("Elements count: "); scanf("%li", &counts); 
    int *items = (int*)malloc(sizeof(int) * counts); 
    
    for(size_t i = 0; i < counts; i++)
    {
        items[i] = rand() % (10 + 1); 
    }; 

    node *root = CreateNode(); 
    u_node *up = CreateUNode(), *down = CreateUNode(); 
 
    NodeLinkUNodeUp(root, up); 
    NodeLinkUNodeDown(root, down);  

    root->up->data = (int*)5; 
    
    node *child = CreateNode(); 
    u_node *child_up = CreateUNode(), *child_down = CreateUNode();

    NodeLink(root, child); 

    NodeLinkUNodeUp(child, child_up); 
    NodeLinkUNodeUp(child, child_down);

    root->right->down->data = (int*)5;

    printf("%i", root->right->down->data); 

    node *n_fisrtnode = NULL, *n_lastnode = NULL; 
    u_node *un_lastnode = NULL;  

    printf("=======[Act: <console command>]=======\n");
    printf("Delete node: <dn>\n"); 
    printf("Right: <r>\n");
    printf("Left: <l>\n"); 
    printf("Up: <u>\n"); 
    printf("Down: <d>\n"); 
    printf("Exit: <ex>\n");
    printf("=======================================\n");

    return 0; 
}