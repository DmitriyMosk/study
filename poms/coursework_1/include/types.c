#include "types.h" 

CMatrix *CreateCMatrix(size_t m, size_t n) 
{ 
    CMatrix *matr = (CMatrix*)malloc(sizeof(CMatrix)); 

    matr->rows = m; 
    matr->cols = n; 

    matr->_matrix = (char**)malloc(sizeof(char*)*m); 
    for(size_t i = 0; i < n; i++)
    { 
        matr->_matrix[i] = (char*)malloc(sizeof(char)*n); 
    }

    return matr; 
} 

CArray *GetRow(int row_i, CMatrix *mat)
{ 
    CArray *arr; 

    arr->size = mat->cols;

    arr->_arr = (char *)malloc(sizeof(char)*arr->size); 

    for(size_t i = 0; i < arr->size; i++)
    { 
        arr->_arr[i] = mat->_matrix[row_i][i]; 
    }

    return arr; 
}

char GetElement(size_t row_id, size_t col_id, CMatrix *mat)
{ 
    return mat->_matrix[row_id][col_id]; 
}
