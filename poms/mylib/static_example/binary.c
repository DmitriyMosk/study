#include "binary.h"

FILE *BinaryCreate(char path[]) 
{ 
    FILE *thread = fopen(path, "wb"); 
    
    if (thread == NULL)
    { 
        printf("Sorry, file not opened.\n");
    }
    else 
        printf("File opened!\n"); 

    return thread;  
} 

void BinarySave(FILE *thread, struct Routes *info)
{ 
    int bytes = sizeof(info); 

    char *c; 

    c = (char *)info; 
    for(size_t i = 0; i < info->r_counts; i++)
    {
        fwrite(&(info->r[i]), sizeof(info->r[i]), 1, thread); 
    }
}