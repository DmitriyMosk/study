#include "list.h" 
#include "stdio.h" 
#include "malloc.h"

list *ListCell()
{
    list *cell = (list*)malloc(sizeof(list)); 
    cell->val = NULL;
    cell->right = NULL; 
}

void ListPop(list *ptr, list *last, int val) 
{  
     
}

void ListPush(list *ptr, list *last, int val)
{
    list *cell = ListCell(); 
    cell->val = (int*)val;  

    last->right = cell; 
}