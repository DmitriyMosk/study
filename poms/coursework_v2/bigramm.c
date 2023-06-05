#include "lib/crypto.h"
#include "locale.h"

int main(int argc, char *argv[]) 
{  
    setlocale(LC_ALL, "Rus"); 

    FILE *input_text = NULL, *input_key = NULL; 

    if (argv[1] != NULL) 
    { 
        input_text = fopen(argv[1], "r");
    }

    if(argv[2] != NULL) {
        input_key = fopen(argv[2], "r"); 
    } 

    if ( (argv[1] != NULL && !input_text) || (argv[2] != NULL && !input_key ) ) 
    { 
        printf("\nНевозможно открыть файлы.\n");
        exit(0); 
    }
    
    if ( argv[1] == NULL && argv[2] == NULL ) 
    {
        printf("Ничего не делать.\n");
        exit(0); 
    }

    char *key_buff = NULL; 
    char *text_buff = NULL;    

    size_t key_len = 0;  
    size_t text_len = 0; 

    // Считываем размер текста
    for (char c = getc(input_text); c != EOF; c = getc(input_text)) 
        text_len++; 
    fseek (input_text, 0, SEEK_SET);

    text_buff = (char *) malloc(sizeof(char) * (text_len + 1)); // Выделяем памяти для текста  

    char ch = fgetc( input_text );
    for( size_t i=0; (i < text_len ) && ( feof( input_text ) == 0 ); i++ )
    {
        text_buff[i] = (char)ch; 
        ch = fgetc(input_text);
    }

    text_buff[text_len] = L'\0';    
    
    size_t index = 0; 
    while(text_buff[index] != '\0')
    { 
        if(text_buff[index] == ' ') 
        { 
            text_buff[index] = '_'; 
        } 

        index++;
    }
    printf("=============[Входные данные]============\n");
    printf("Исходный текст: \n%s\nДлина исходного текста: %d\n", text_buff, strlen(text_buff));

    if(argv[2] != NULL) 
    {
        for (char c = getc(input_key); c != EOF; c = getc(input_key)) 
            key_len++; 
        fseek (input_key, 0, SEEK_SET); 

        key_buff = (char *) malloc(sizeof(char) * (key_len + 1)); // Выделяем памяти для ключа   

        char ch = fgetc( input_key );
        for( size_t i=0; (i < key_len ) && ( feof( input_key ) == 0 ); i++ )
        {
            key_buff[i] = (char)ch; 
            ch = fgetc(input_key);
        } 

        key_buff[key_len] = '\0'; 

        printf("Ключ: %s\nДлина ключа: %d\n", key_buff, key_len); 
        printf("=============[Входные данные]============\n\n");
        CryptoIO(text_buff, text_len, key_buff, key_len); 

        if (CryptCompare(text_len))
        { 
            printf("Шифрование и дешифрование успешно.\n");  
        }
        else 
        { 
            printf("Шифрование и дешифрование не успешно.\n");
        }
    } 
    else 
    {       
        CryptoIO(text_buff, text_len, NULL, 0);

        if (CryptCompare(text_len))
        { 
            printf("Шифрование и дешифрование успешно.\n");  
        }
        else 
        { 
            printf("Шифрование и дешифрование не успешно.\n");
        }
    }

    fclose(input_text); 
    fclose(input_key); 

    return 0;
}