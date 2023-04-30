#include "stdio.h" 
#include "stdlib.h"
#include "malloc.h"

#define RandMax 50
#define RandMin 10 
#define WorkFilePath "txts/text_handl_txt.txt"

typedef struct C_STRING { 
    char *data; 
    size_t size; 
} C_STRING; 

void FileFill(FILE *thread); 

C_STRING *Array(size_t size); 
void StringRandomize(C_STRING *array);
void CharSet(C_STRING *arr, const char val, const int index); 
int CharGet(C_STRING *array, const int index); 
void StringPrint(C_STRING *array); 
void StringFree(C_STRING *arr); 
void StartHandl(); 

int main(void) 
{ 
    FILE *thread; 
    thread = fopen(WorkFilePath, "w+"); 
    
    if ( thread == NULL  )
    { 
        printf("fopen: filed");
        return 0; 
    }
    else
    {
        printf("fopen: succes\nStart working\n");
    }

    FileFill(thread); 

    StartHandl(); 
    return 0;
} 

void StartHandl()
{ 
    FILE *thread;
    thread = fopen(WorkFilePath, 'a');

    if ( thread == NULL  )
    { 
        printf("fopen worker: filed");
        return 0; 
    }
    else
    {
        printf("fopen worker: succes\nStart working\n");
    }


}

void FileFill(FILE *thread) 
{ 
    size_t arr_size; 
    printf("Insert array size: "); scanf("%li", &arr_size); 

    C_STRING *arr = Array(arr_size); 

    StringRandomize(arr);  
    StringPrint(arr); 

    for(size_t i = 0; i < arr->size; i++)
    { 
        fprintf(thread, "%d", arr->data[i]);
    }
    
    //fputs(arr->data, thread);

    StringFree(arr);
}

C_STRING *Array(size_t size) 
{ 
    C_STRING *arr = (C_STRING*)malloc(sizeof(C_STRING));  

    arr->data = (char *)malloc(sizeof(char)*size); 
    arr->size = size;

    return arr;
}

void StringRandomize(C_STRING *array) 
{ 
    for(size_t i = 0; i < array->size; i++)
    {
       CharSet(array, rand() % ( RandMax - RandMin + 1 ) + RandMin, i); 
    }
}

void ArraySet(C_STRING *arr, const int val, const int pos) 
{ 
    if (pos >= arr->size) 
        printf("ERROR %i sets %i in array size %i", pos, val, arr->size); 
    else 
        arr->data[pos] = val; 
}

int ArrayGet(C_STRING *arr, const int index)
{ 
    if ( index >= arr->size )
    { 
        printf("ERROR %i get in array size %i", index, arr->size); 
        return 0;
    }
    else 
    { 
        return arr->data[index]; 
    }
        
}

void ArrayPrint(C_STRING *arr)
{ 
    printf("\n\n");
    for(size_t i = 0; i < arr->size; i++)
    { 
        printf("%i ", arr->data[i]); 
    }
    printf("\n\n");
}

void ArrayFree(C_STRING *arr)
{
    free(arr->data);
    free(arr);
}