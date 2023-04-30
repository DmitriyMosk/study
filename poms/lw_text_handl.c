#include "stdio.h" 
#include "stdlib.h"

#define RandMax 50
#define RandMin 10 

typedef struct IntArray { 
    int *data; 
    size_t size; 
} INT_ARRAY; 

void FileFill(FILE *thread, int *data); 

INT_ARRAY *Array(size_t size); 
void ArrayRandomize(INT_ARRAY *array);
void ArraySet(INT_ARRAY *arr, int val, int index); 
int ArrayGet(INT_ARRAY *array, int index); 
void ArrayPrint(INT_ARRAY *array); 
 
int main(void) 
{ 
    FILE *thread = NULL; 
    thread = fopen("a+", "txts/text_handl_txt.txt"); 
    
    size_t arr_size; 
    printf("Insert array size: "); scanf("%li ", arr_size); 

    INT_ARRAY *arr = NULL; 
    arr = Array(arr_size); 

    ArrayRandomize(arr);  
    
    
    return 0;
}

void FileFill(FILE *thread, int *data) 
{ 
    
}

INT_ARRAY *Array(size_t size) 
{ 
    INT_ARRAY *arr = NULL; 
    arr->data = (int *) malloc(sizeof(int) * size); 
    arr->size = size;
}

void ArrayRandomize(INT_ARRAY *array) 
{ 
    for(size_t i = 0; i < array->size; i++)
    {
        array->data[i] = rand() % ( RandMax - RandMin + 1 ) + RandMin; 
    }
}

void ArraySet(INT_ARRAY *arr, int val, int pos) 
{ 
    if (pos >= arr->size) 
        printf("ERROR %i sets %i in array size %i", pos, val, arr->size); 
    else 
        arr->data[pos] = val; 
}

int ArrayGet(INT_ARRAY *arr, int index)
{ 
    if ( index >= arr->size )
    { 
        printf("ERROR %i get in array size %i", index, arr->size); 
        return NULL;
    }
    else 
    { 
        return arr->data[index]; 
    }
        
}

void ArrayPrint(INT_ARRAY *arr)
{ 
    printf("\n\n");
    for(size_t i = 0; i < arr->size; i++)
    { 
        printf("%i ", arr->data[i]); 
    }
    printf("\n\n");
}