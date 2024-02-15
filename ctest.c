#include <stdio.h> 
#include <string.h>
#define N_ARRAY 255

char storage[N_ARRAY]; int idx_lenta; int state; 
char cache_input[80];
//Turing 
    void MT_Init() 
    {   
        printf("Generating storage.. size %i \n", N_ARRAY);

        for ( int i = 0; i < N_ARRAY; i++ ) storage[i] = '#';

        printf("\n[OK]\n");
    }
    void MT_Right() 
    {
        idx_lenta++;
    }
    void MT_Left() 
    {
        idx_lenta--;
    }
    char MT_CurData() 
    { 
        return storage[idx_lenta];
    }
    void MT_WriteWord() 
    { 
        idx_lenta = 5; // Пусть так будет
        gets(cache_input);
        
        printf("Input Len: %i\n",strlen(cache_input));
        for(int i = 0; i < strlen(cache_input); i++) 
        { 
            storage[idx_lenta] = cache_input[i]; 
            MT_Right(); 
        }

        MT_Left();

        for (int i = 0; i<N_ARRAY; i++) 
        {
            if ( idx_lenta == i )
            {
                printf("[%c]",storage[i], idx_lenta);
            }
            else 
            { 
                printf("%c",storage[i]);
            }
            
        }
        printf("\n");
    }
    void MT_ReWrite(char val)
    {
        storage[idx_lenta] = val;
    }
    void MT_HandlerW1() 
    {   
        state = 1; 

        while ( state != 0 ) 
        {
            switch (state)
            {
                case 1:
                    switch ( MT_CurData() )
                    {
                        case '#':
                            MT_ReWrite('1'); state = 1;
                            MT_Right(); 
                            break;
                        case '0':
                            MT_ReWrite('0'); state = 2; 
                            MT_Left();
                            break;
                        case '1':
                            MT_ReWrite('1'); state = 2;
                            MT_Left();
                            break;
                        default:
                            break;
                    }
                    break;
                case 2:
                    switch ( MT_CurData() )
                    {
                        case '#':
                            MT_ReWrite('#'); state = 3;
                            MT_Right(); 
                            break;
                        case '0':
                            MT_ReWrite('0'); state = 2; 
                            MT_Left();
                            break;
                        case '1':
                            MT_ReWrite('1'); state = 2; 
                            MT_Left();
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:
                    switch ( MT_CurData() )
                    {
                        case '#':
                            MT_ReWrite('1'); state = 0;
                            break;
                        case '0':
                            MT_ReWrite('0'); state = 4; 
                            MT_Left();
                            break;
                        case '1':
                            MT_ReWrite('1'); state = 3; 
                            MT_Left();
                            break;
                        default:
                            break;
                    }
                    break;
                case 4:
                    switch ( MT_CurData() )
                    {
                        case '#':
                            MT_ReWrite('0');  state = 0;
                            break;
                        case '0':
                            MT_ReWrite('0'); state = 4;
                            MT_Right();
                            break;
                        case '1':
                            MT_ReWrite('0'); state = 4;
                            MT_Right();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    void MT_HandlerW3() 
    {
        state = 1; 

        while ( state != 0 ) 
        {
            switch (state)
            {
                case 1:
                    switch ( MT_CurData() )
                    {
                        case '0':
                            MT_ReWrite('0'); state = 1;
                            MT_Left(); 
                            break;
                        case '1':
                            MT_ReWrite('1'); state = 1; 
                            MT_Left();
                            break;
                        case '#':
                            MT_ReWrite('#'); state = 2;
                            MT_Right();
                            break;
                        default:
                            break;
                    }
                    break;
                case 2:
                    switch ( MT_CurData() )
                    {
                        case '0':
                            MT_ReWrite('0'); state = 3;
                            MT_Right(); 
                            break;
                        case '1':
                            MT_ReWrite('1'); state = 3; 
                            MT_Right();
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:
                    switch ( MT_CurData() )
                    {
                        case '0':
                            MT_ReWrite('0'); state = 4;
                            MT_Right();
                            break;
                        case '1':
                            MT_ReWrite('1'); state = 4; 
                            MT_Right();
                            break;
                        case '#':
                            MT_ReWrite('#'); state = 0; 
                            break;
                        default:
                            break;
                    }
                    break;
                case 4:
                    switch ( MT_CurData() )
                    {
                        case '0':
                            MT_ReWrite('0');  state = 5;
                            MT_Right();
                            break;
                        case '1':
                            MT_ReWrite('1'); state = 5;
                            MT_Right();
                            break;
                        case '#':
                            MT_ReWrite('#'); state = 0;
                            break;
                        default:
                            break;
                    }
                    break;
                case 5:
                    switch ( MT_CurData() )
                    {
                        case '0':
                            MT_ReWrite('#');  state = 5;
                            MT_Right();
                            break;
                        case '1':
                            MT_ReWrite('#'); state = 5;
                            MT_Right();
                            break;
                        case '#':
                            MT_ReWrite('#'); state = 0;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    
    void MT_HandlerW2() 
    { 
        state = 1; 

        while ( state != 0 ) 
        {
            switch (state)
            {
                case 1:
                    switch ( MT_CurData() )
                    {
                        case '#':
                            MT_ReWrite('#'); state = 0;
                            break;
                        case '1':
                            MT_ReWrite('#'); state = 2; 
                            MT_Left();
                            break;
                        default:
                            break;
                    }
                    break;
                case 2:
                    switch ( MT_CurData() )
                    {
                        case '#':
                            MT_ReWrite('1'); state = 0;
                            break;
                        case '1':
                            MT_ReWrite('#'); state = 3; 
                            MT_Left();
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:
                    switch ( MT_CurData() )
                    {
                        case '#':
                            MT_ReWrite('1'); state = 2;
                            MT_Left();
                            break;
                        case '1':
                            MT_ReWrite('#'); state = 1; 
                            MT_Left();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
    } 
// 
int main() 
{
    MT_Init();
    MT_WriteWord(); 
    MT_HandlerW3();

    printf("\nOutput: \n");
    for (int i = 0; i<N_ARRAY; i++) 
    {
        if ( idx_lenta == i )
        {
            printf("[%c]",storage[i], idx_lenta);
        }
        else 
        { 
            printf("%c",storage[i]);
        }
        
    }

    return 0;
}