#include "stdio.h"
#include "stdlib.h"
#include "fbinary.h"

FILE *BinaryCreate(char path[]) 
{ 
    FILE *thread = fopen(path, "wb"); 
    
    if (thread == NULL)
    { 
        printf("Sorry, file not opened.\n");
        exit(0); 
    }
    else 
        printf("File opened!\n"); 

    return thread;  
} 

FILE *BinaryFill(FILE *thread) 
{ 

}