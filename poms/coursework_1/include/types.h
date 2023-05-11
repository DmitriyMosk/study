#ifndef LIB_CMATRIX_TYPES
#define LIB_CMATRIX_TYPES

typedef unsigned int size_t; 

typedef struct CArray
{ 
    char *_arr; 
    size_t size; 
} 
CArray; 

typedef struct CMatrix 
{ 
    char **_matrix;  
    size_t rows; 
    size_t cols; 
} 
CMatrix; 

typedef struct list 
{ 
    void *data; 
    void *next; 
} list; 

CMatrix *CreateCMatrix(size_t m, size_t n); 
CArray *GetRow(int row_i, CMatrix *mat); 

#endif 