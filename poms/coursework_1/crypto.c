#include "crypto.h"
#include "stdbool.h"

wchar_t alphabet[37] = L"абвгдежзийклмнопрстуфхцчшщъыьэюя_.,-";
const int alphabet_size = 37;

typedef struct Pos {
    int i;
    int j;
} POS; 

void PrintMatrix(wchar_t **m, size_t size)
{ 
    printf("\n");
    for(size_t row = 0; row < size; row++)
    { 
        for(size_t col = 0; col < size; col++)
        { 
            wprintf(L"%c ", m[row][col]);
        }

        printf("\n"); 
    }
}

void RemoveDuplicates(wchar_t *str, size_t key_len)
{      
    int len = key_len;
    int index = 0;
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == i) {
            str[index++] = str[i];
        }
    }
    str[index] = L'\0';
}
 
POS GetCharPos(wchar_t c, wchar_t **matrix)
{ 
    POS pos; 
    pos.i = -1; 
    pos.j = -1; 

    for(size_t row = 0; row < 6; row++)
    { 
        for(size_t col = 0; col < 6; col++)
        {
            if(matrix[row][col] == c)
            {
                pos.i = row; 
                pos.j = col; 
            }
        }
    }

    return pos; 
}


wchar_t **CryptoMatrix(wchar_t *key, size_t key_len)
{   
    //Удаление из ключа лишних букв
    wchar_t *words_array; 
    if (key != NULL)
    {
        RemoveDuplicates(key, key_len); // удаляем 

        wprintf(L"Key fixed: %s | Len: %d\n", key, wcslen(key));

        size_t len_matrix = wcslen(key) + alphabet_size + 1;    
        words_array = (wchar_t *)malloc(sizeof(wchar_t) * len_matrix); 

        for(size_t i = 0; i < key_len; i++)
            words_array[i] = key[i]; 

        wcscat(words_array, alphabet);

        RemoveDuplicates(words_array, len_matrix);

        wprintf(L"Words: %s | Len: %d\n", words_array, wcslen(words_array), len_matrix);
    }
    else 
    { 
        size_t len_matrix = alphabet_size + 1;    
        words_array = (wchar_t *)malloc(sizeof(wchar_t) * len_matrix); 

        wcscat(words_array, alphabet);

        wprintf(L"Words: %s | Len: %d\n", words_array, wcslen(words_array), len_matrix);
    }

    wchar_t **cryptoMatrix = (wchar_t **)malloc(6*sizeof(wchar_t *)); 
    for(int i = 0; i < 6; i++)
        cryptoMatrix[i] = (wchar_t *)malloc(6*sizeof(wchar_t)); 

    size_t wordidx = 0; 
    for(size_t row = 0; row < 6; row++) 
    { 
        for(size_t col = 0; col < 6; col++)
        { 
            cryptoMatrix[row][col] = words_array[wordidx]; 
            wordidx++; 
        }
    }

    return cryptoMatrix; 
    //wprintf(L"%s\n", key_fixed);
}

wchar_t *CryptoIO(wchar_t *buffer, wchar_t *key, char flag, size_t buff_len, size_t key_len)
{ 
    if (buffer == NULL)
    { 
        printf("Memory error: buffer is null");
        exit(0);
    }
    wchar_t *result = (wchar_t *)malloc(sizeof(wchar_t) * buff_len); 
    wchar_t **matrix = CryptoMatrix(key, key_len);

    if(flag == 'e') 
    {   
        printf("Crypto Matrix: ---\n");
        PrintMatrix(matrix, 6); 

        for(size_t CryptoID = 0; CryptoID < buff_len - 1; CryptoID += 2)
        { 
            wchar_t gr1, gr2; 

            gr1 = buffer[CryptoID]; 
            gr2 = buffer[CryptoID+1]; 

            wprintf(L"%c %c\n", gr1, gr2);

            POS p_gr1, p_gr2;

            p_gr1 = GetCharPos(gr1, matrix); 
            p_gr2 = GetCharPos(gr2, matrix); 

            if (p_gr1.i == -1 && p_gr1.j == -1) 
            { 
                wprintf(L"Символ %c не определён\n", gr1); 
            }
            else 
            if (p_gr2.i == -1 && p_gr2.j == -1) 
            { 
                wprintf(L"Символ %c не определён\n", gr2); 
            } 
            else 
            if ( p_gr1.j == p_gr2.j ) 
            { 
                gr1 = (p_gr1.i == 5) ? matrix[0][p_gr1.j] : matrix[p_gr1.i+1][p_gr1.j]; 
                gr2 = (p_gr2.i == 5) ? matrix[0][p_gr2.j] : matrix[p_gr2.i+1][p_gr2.j];
            }
            else if ( p_gr1.i == p_gr2.i )
            { 
                gr1 = (p_gr1.j == 5) ? matrix[p_gr1.i][0] : matrix[p_gr1.i][p_gr1.j+1]; 
                gr2 = (p_gr2.j == 5) ? matrix[p_gr2.i][0] : matrix[p_gr2.i][p_gr2.j+1];
            }
            else 
            {
                gr1 = (p_gr1.i == 5) ? matrix[0][p_gr1.j] : matrix[p_gr1.i + 1][p_gr1.j]; 
                gr2 = (p_gr2.i == 0) ? matrix[5][p_gr2.j] : matrix[p_gr2.i - 1][p_gr2.j];
            }

            result[CryptoID] = gr1; 
            result[CryptoID + 1] = gr2; 

            //wprintf(L"d: %s\n", result); 
        }
    } 

    if(flag == 'd')
    { 
        printf("Crypto Matrix: ---\n");
        PrintMatrix(matrix, 6); 

        wprintf(L"%s | len: %d\n", buffer, wcslen(buffer)); 
        for(size_t CryptoID = 0; CryptoID < buff_len - 1; CryptoID += 2)
        { 
            wchar_t gr1, gr2; 

            gr1 = buffer[CryptoID]; 
            gr2 = buffer[CryptoID+1]; 

            POS p_gr1, p_gr2;

            p_gr1 = GetCharPos(gr1, matrix); 
            p_gr2 = GetCharPos(gr2, matrix); 

            if (p_gr1.i == -1 && p_gr1.j == -1) 
            { 
                wprintf(L"Символ %c не определён\n", gr1); 
            }
            else 
            if (p_gr2.i == -1 && p_gr2.j == -1) 
            { 
                wprintf(L"Символ %c не определён\n", gr2); 
            } 
            else 
            if ( p_gr1.j == p_gr2.j ) 
            { 
                gr1 = (p_gr1.i == 0) ? matrix[5][p_gr1.j] : matrix[p_gr1.i-1][p_gr1.j]; 
                gr2 = (p_gr2.i == 0) ? matrix[5][p_gr2.j] : matrix[p_gr2.i-1][p_gr2.j];
            }
            else if ( p_gr1.i == p_gr2.i )
            { 
                gr1 = (p_gr1.j == 0) ? matrix[p_gr1.i][5] : matrix[p_gr1.i][p_gr1.j-1]; 
                gr2 = (p_gr2.j == 0) ? matrix[p_gr2.i][5] : matrix[p_gr2.i][p_gr2.j-1];
            }
            else 
            {
                gr1 = (p_gr1.i == 0) ? matrix[5][p_gr1.j] : matrix[p_gr1.i - 1][p_gr1.j]; 
                gr2 = (p_gr2.i == 5) ? matrix[0][p_gr2.j] : matrix[p_gr2.i + 1][p_gr2.j];
            }
    
            result[CryptoID] = gr1; 
            result[CryptoID + 1] = gr2;

            //wprintf(L"d: %s\n", result); 
        }
    }

    if (buff_len % 2 != 0)
    { 
        result[buff_len-1] = buffer[buff_len-1];
    }

    for(size_t i = 0; i < 6; i++)
    { 
        free(matrix[i]);
    }
    free(matrix); 

    return result;
}

bool CryptCompare(wchar_t *src, wchar_t *dest) 
{ 
    return wcscmp(src, dest) == 1;     
}