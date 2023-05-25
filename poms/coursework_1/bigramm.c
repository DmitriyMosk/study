#include "conio.h"
#include "locale.h" // For russian language

#include "crypto.h"

#define ENCODE_FILE "files/encode.txt" 
#define DECODE_FILE "files/decode.txt"
#define KEY_FILE "files/key.txt"

int main() 
{ 
    setlocale(LC_ALL, "Rus");
    wchar_t *buffer = NULL, *key = NULL;
    
    FILE *decode = fopen(DECODE_FILE, "r"); // Расшиврованная информация
    FILE *encode = fopen(ENCODE_FILE, "r"); // Зашифрованная информация 
    FILE *keyfil = fopen(KEY_FILE, "r");    // ключ
    
    if(!decode || !encode)
    {
        printf("IO Fopen error: file not exists");
        return 0; 
    }

    size_t decode_size = 0; 

    for (wchar_t c = getwc(decode); c != WEOF; c = getwc(decode)) 
        decode_size++; 

    fseek (decode,0,SEEK_SET);

    size_t key_size = 0;

    for (wchar_t c = getwc(keyfil); c != WEOF; c = getwc(keyfil)) 
        key_size++; 

    fseek (keyfil,0,SEEK_SET);

    buffer = (wchar_t *)malloc(sizeof(wchar_t) * (decode_size + 1)); 
    key = (wchar_t *)malloc(sizeof(wchar_t) * (key_size + 1)); 


    wchar_t ch = fgetwc( decode );
    for( size_t i=0; (i < decode_size ) && ( feof( decode ) == 0 ); i++ )
    {
        buffer[i] = (wchar_t)ch; 
        ch = fgetwc(decode);
    }
    
    buffer[decode_size] = L'\0';

    wprintf(L"%ls | len: %d\n", buffer, decode_size);

    char act;
    printf("Вы хотите использовать кодовое слово?[y(безопасно)/n]\n"); scanf("%c[^\n]", &act); 
    
    if(act == 'y')
    {
        for(size_t i = 0; i < key_size; i++)
            key[i] = L'\0'; 
        
        wchar_t ch = fgetwc( keyfil );
        for( size_t i=0; (i <= key_size) && ( feof( keyfil ) == 0 ); i++ )
        {
            if ( i != 38 )
            {
                key[i] = (wchar_t)ch; 
                ch = fgetwc(keyfil);
            }
            else 
                key[i] = L'\0';

        }

        wprintf(L"Key: %ls | len: %d\n",key, key_size);

        CryptoIO(buffer, key, 'e', decode_size, key_size);
    }
    if(act == 'n') 
    {
        CryptoIO(buffer, NULL, 'e', decode_size, key_size);
    }

    fclose(decode); 
    fclose(encode); 
    fclose(keyfil);

    free(buffer); 
    free(key);
    //CryptoIO(buffer, key, 'e'); 
    return 0; 
}