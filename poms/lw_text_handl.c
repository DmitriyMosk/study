#include "stdio.h" 
#include "stdlib.h"
#include "malloc.h"
typedef struct C_STRING { 
    char *data; 
    size_t len; 
} C_STRING; 
typedef struct INT_ARRAY { 
    int *data; 
    size_t len; 
} INT_ARRAY; 


#define RandMax 50
#define RandMin 10 
#define WorkFilePath "txts/text_handl_txt.txt"

INT_ARRAY *__create_int_array(size_t len); 
void __unset_int_array(INT_ARRAY *ia); 
size_t GetSize(INT_ARRAY *ia); 
void Set(INT_ARRAY *ia, const int index, const int val); 
int Get(INT_ARRAY *ia, const int index); 
void Randomize(INT_ARRAY *ia); 
void PrintArray(INT_ARRAY *ia); 
void ToFile(INT_ARRAY *ia);
void WorkStart(); 

int main() 
{  
    size_t arr_len = 0; 
    printf("Array size: "); scanf("%li", &arr_len); 

    INT_ARRAY *ia = __create_int_array(arr_len); 
    Randomize(ia);
    PrintArray(ia); 

    ToFile(ia); 
    
    WorkStart(); 

    return 0; 
}

void WorkStart() 
{ 
    FILE *thread;
    thread = fopen(WorkFilePath, "r");  
    
    printf("Start reading file\n");
    char buff; 
    size_t count_numbers = 0; 
    while((buff = fgetc(thread)) != EOF) 
    {
        printf("%c ", buff);
        if ( buff == ' ' || buff == '\0')
        { 
            count_numbers++; 
        }
    }
    printf("numbers finded: %li", count_numbers);
    INT_ARRAY *ia = __create_int_array(count_numbers);

    int index = 0; 
    printf("Dsdasd");
    while(fscanf(thread, "%i ", ia->data[index]) != EOF)
    { 
        printf("%i\n", index);
        index++;  
    }

    PrintArray(ia); 
}

INT_ARRAY *__create_int_array(size_t len) 
{ 
    INT_ARRAY *ia = (INT_ARRAY*)malloc(sizeof(INT_ARRAY)); 

    ia->data = (int *)malloc(sizeof(int)*len); 
    ia->len = len;

    return ia;
}
size_t GetSize(INT_ARRAY *ia){ return ia->len; } 
void Set(INT_ARRAY *ia, const int index, const int val) { if(GetSize(ia) > index) ia->data[index] = val; }
int Get(INT_ARRAY *ia, const int index) { if(GetSize(ia) > index) return ia->data[index]; else return -19999; }  

void Randomize(INT_ARRAY *ia)
{   
    size_t i; 
    for(i = 0; i < GetSize(ia); i++) 
    { 
        Set(ia, i, rand() % (RandMax - RandMin + 1) + RandMin); 
    }
} 

void PrintArray(INT_ARRAY *ia)
{ 
    printf("\n\n"); 
    size_t i; 
    for(i = 0; i < GetSize(ia); i++)
    { 
        printf("%i ", Get(ia, i)); 
    }
    printf("\n\n"); 
}

void ToFile(INT_ARRAY *ia)
{ 
    FILE *thread; 
    thread = fopen(WorkFilePath, "w+"); // create if exists
    
    if ( thread == NULL ) 
    { 
        printf("fopen: failed\n");
        exit(1); 
    }
    else 
    { 
        printf("fopen: succes\n"); 
    }

    for(size_t i = 0; i < GetSize(ia); i++)
    { 
        fprintf(thread, "%i ", Get(ia, i));
    }

    fclose(thread); 
    __unset_int_array(ia);
}

void __unset_int_array(INT_ARRAY *ia)
{ 
    free(ia->data); 
    free(ia); 
}