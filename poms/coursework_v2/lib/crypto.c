#include "crypto.h"

char alphabet[] = "абвгдежзийклмнопрстуфхцчшщъыьэюя_.,-"; 
const int alphabet_size = 37;

typedef struct Pos {
    int i;
    int j;
} POS; 

void PrintMatrix(char **m, size_t size)
{ 
    printf("\n");
    for(size_t row = 0; row < size; row++)
    { 
        for(size_t col = 0; col < size; col++)
        { 
            printf("%c ", m[row][col]);
        }

        printf("\n"); 
    }
}

void RemoveDuplicates(char *str, size_t key_len)
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
 
POS GetCharPos(char c, char **matrix)
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


char **CryptoMatrix(char *key, size_t key_len)
{   
    //Удаление из ключа лишних букв
    char *words_array; 
    if (key != NULL)
    {
        RemoveDuplicates(key, key_len); // удаляем 

        printf("Key fixed: %s | Len: %d\n", key, strlen(key));

        size_t len_matrix = strlen(key) + alphabet_size + 1;    
        words_array = (char *)malloc(sizeof(char) * len_matrix); 

        for(size_t i = 0; i < key_len; i++)
            words_array[i] = key[i]; 

        strcat(words_array, alphabet);

        RemoveDuplicates(words_array, len_matrix);

        printf("Words: %s | Len: %d\n", words_array, strlen(words_array));
    }
    else 
    { 
        size_t len_matrix = alphabet_size + 1;    
        words_array = (char *)malloc(sizeof(char) * len_matrix); 

        for(size_t i = 0; i < alphabet_size; i++) 
        { 
            words_array[i] = alphabet[i]; 
        }

        words_array[alphabet_size] = '\0';
        
        printf("Words: %s | Len: %d\n", words_array, strlen(words_array));
    }

    char **cryptoMatrix = (char **)malloc(6*sizeof(char *)); 
    for(int i = 0; i < 6; i++)
        cryptoMatrix[i] = (char *)malloc(6*sizeof(char)); 

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
}

void CryptoIO(char *text, size_t text_len, char *key, size_t key_len)
{ 
    char *result_e = (char *)malloc(sizeof(char) * text_len); 
    char *result_d = (char *)malloc(sizeof(char) * text_len); 
    char **matrix = CryptoMatrix(key, key_len);
    
    printf("Crypto Matrix: ---\n");
    PrintMatrix(matrix, 6); 

    for(size_t CryptoID = 0; CryptoID < text_len - 1; CryptoID += 2)
    { 
        char gr1, gr2; 

        gr1 = text[CryptoID]; 
        gr2 = text[CryptoID+1]; 

        POS p_gr1, p_gr2;

        p_gr1 = GetCharPos(gr1, matrix); 
        p_gr2 = GetCharPos(gr2, matrix); 

        if(gr1 != '\n' && gr2 != '\n')
        { 
            if (p_gr1.i == -1 && p_gr1.j == -1) 
            { 
                printf("Символ %c не определён\n", gr1); 
            }
            else 
            if (p_gr2.i == -1 && p_gr2.j == -1)  
            { 
                printf("Символ %c не определён\n", gr2); 
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
            else // Случай с квадратом или прямоугольником 
            {
                gr1 = matrix[p_gr1.i][p_gr2.j];  
                gr2 = matrix[p_gr2.i][p_gr1.j]; 
            }
        }

        result_e[CryptoID] = gr1; 
        result_e[CryptoID + 1] = gr2; 
    }

    if (text_len % 2 != 0)
    { 
        result_e[text_len-1] = text[text_len-1];
    } 

    for(size_t CryptoID = 0; CryptoID < text_len - 1; CryptoID += 2)
    { 
        char gr1, gr2; 

        gr1 = result_e[CryptoID]; 
        gr2 = result_e[CryptoID+1]; 

        POS p_gr1, p_gr2;

        p_gr1 = GetCharPos(gr1, matrix); 
        p_gr2 = GetCharPos(gr2, matrix); 

        if(gr1 != '\n' && gr2 != '\n')
        { 
            if (p_gr1.i == -1 && p_gr1.j == -1)  
            { 
                printf("Символ %c не определён\n", gr1); 
            }
            else 
            if (p_gr2.i == -1 && p_gr2.j == -1)   
            { 
                printf("Символ %c не определён\n", gr2); 
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
            else // случай с квадратом или прямоугольником
            {
                gr1 = matrix[p_gr1.i][p_gr2.j];  
                gr2 = matrix[p_gr2.i][p_gr1.j]; 
            }
        }
    
        result_d[CryptoID] = gr1; 
        result_d[CryptoID + 1] = gr2;
    }

    if (text_len % 2 != 0)
    { 
        result_d[text_len-1] = result_e[text_len-1];
    }

    for(size_t i = 0; i < text_len; i++) 
    { 
        if(result_d[i] == '_')
        { 
            result_d[i] = ' '; 
        }
    }

    

    for(size_t i = 0; i < 6; i++)
    { 
        free(matrix[i]);
    }
    free(matrix); 

    FILE *encode_result = fopen("out/encode.txt", "w");  
    FILE *decode_result = fopen("out/decode.txt", "w"); 

    if(!encode_result || !decode_result)
    { 
        printf("Ошибка открытия файла\n"); 
        exit(1); 
    }
    printf("Результат шифрования: ");
    for(size_t i = 0; i < text_len; i++)
    {
        printf("%c", result_e[i]);
        fputc(result_e[i], encode_result);
    }
    printf("\n"); 

    printf("Результат дешифрования: ");
    for(size_t i = 0; i < text_len; i++)
    {
        printf("%c", result_d[i]);
        fputc(result_d[i], decode_result);
    }
    printf("\n");

    fclose(encode_result);
    fclose(decode_result);
    
    free(result_e);
    free(result_d); 
}

bool CryptCompare(size_t text_len) 
{ 
    FILE *source = fopen("input/text.txt", "r");  
    FILE *dest = fopen("out/decode.txt", "r"); 

    bool Compare = true; 

    for(size_t i = 0; i < text_len; i++) 
    { 
        if (fgetc(source) != fgetc(dest)) 
            Compare = false;  
    }

    fclose(source); 
    fclose(dest); 

    return Compare;     
}