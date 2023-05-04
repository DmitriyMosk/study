#include "types.h" 
#include "stdlib.h"
#include "malloc.h"

IArray *IArrayCreate(size_t blocks)
{
    IArray *arr = NULL; 
    
    arr->data = (int*)malloc(sizeof(int)*blocks); 
    arr->len = blocks; 

    return arr; 
}

void IArrayRandomize(IArray *arr, Range range)
{ 
    for(size_t i = 0; i < arr->len; i++)
    { 
        arr->data[i] = rand() % (range.max - range.min + 1) + range.min; 
    }
}

Range _Range(int min, int max)
{ 
    Range range; 
    range.min = min; 
    range.max = max; 

    return range; 
}

