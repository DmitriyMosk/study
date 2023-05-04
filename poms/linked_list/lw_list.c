#include "stdio.h"
#include "stdlib.h"
#include "time.h" 
#include "string.h"

#include "lib/types.h" 
#include "lib/node.h"

int main()
{ 
    srand(time(NULL)); 

    size_t counts; 
    printf("Elements count: "); scanf("%li", &counts); 

    int *items = (int*)malloc(sizeof(int) * counts); 
    
    printf("input: "); 
    for(size_t i = 0; i < counts; i++)
    {
        items[i] = rand() % (10 + 1); 
        printf("%i ", items[i]); 
    }; 
    printf("\n");

    
    node *prev_node = NULL, *firstnode = NULL, *inode = NULL;  // Я сделал проверку на NULL в функциях *Push 
    for (size_t i = 0; i < counts / 2 + 1; i++)
    { 
        inode = NodePush(prev_node); 

        if(firstnode == NULL) 
            firstnode = inode; 

        prev_node = inode; 
    }
    inode->right = firstnode; // связываем конец и начало
    inode = firstnode; // Присваиваем стартовую точку 
    // Конец генерации центральных нод
    printf("Node links: "); 

    node *links; 
    links = firstnode; 
    for (size_t i = 0; i < counts / 2 + 2; i++)
    { 
        if (i != counts / 2 + 1)
            printf("%p -> ", links);
        else 
            printf("%p", links);

        links = NextNode(links); 
    }
    printf("\n"); // Демонстрация кольцевого центрального списка
    printf("Start Node: %p\n", inode);

    int pos = 1; // down 
    u_node *cur_unode = NULL; 
    u_node *prev_unode = NULL; 
    for(size_t i = 0; i < counts; i++)
    {   
        if(pos == 1)
        { 
            cur_unode = UNodePush(prev_unode, inode, 'd', items[i]); 
            printf("%p\n", inode);  
        }

        if (pos == 2) 
        { 
            cur_unode = UNodePush(prev_unode, inode, 'u', items[i]);  
            printf("%p\n", inode->up); 
        }

        inode = NextNode(inode); 

        printf("%p|%p\n", inode,prev_unode);

        prev_unode = cur_unode; 

        if (memcmp(inode, firstnode, sizeof(node))==0) // переходим вверх, если оказываемся в начале
        { 
            pos = 2; 
            inode = firstnode; // Возвращаемся в начало.
            prev_unode = NULL; 
        }
    }
    inode = NULL; // Устанавливаем в позицию старт

    printf("=======[Act: <console command>]=======\n");
    printf("Right: <r>\n");
    printf("Left: <l>\n"); 
    printf("Up: <u>\n"); 
    printf("Down: <d>\n"); 
    printf("Exit: <e>\n");
    printf("Pop: <p>\n");
    printf("Return to start: <g>\n");
    printf("=======================================\n");
 
    u_node *current_u_node = NULL; 
    char command;

    int node_number = 0; 
    do { 
        scanf("%c[^\n]", &command); 

        switch (command)
        {
            case 'r':
                if ( current_u_node == NULL ) // Мы находимся на главной ноде
                {
                    if(inode == NULL) 
                        inode = firstnode; 
                    else 
                    {
                        inode = inode->right; 
                        if(memcmp(inode, firstnode, sizeof(node)) == 0) 
                        {
                            printf("---Loopback---\n");
                        }
                    }
                    printf("{Rigth}\n"); 

                }
                else // Переместились в одно из( верх или низ )
                { 
                    if (current_u_node->right != NULL)
                    { 
                        current_u_node = current_u_node->right; 
                        printf("{Rigth} value: %i\n", current_u_node->data); 
                    }
                    else
                    {
                        printf("{Right} is empty. "); 
                        printf("Insert <g> to go back\n"); 
                    }
                }
                printf("Node #%p| ", inode);
                break;
            case 'u':
                 printf("Node #%p| ", inode);
                if ( inode != NULL && inode->up != NULL && current_u_node == NULL )
                { 
                    current_u_node = inode->up; 
                    printf("{Up} value: %i\n",current_u_node->data);
                }
                else 
                { 
                    printf("Up is empty.\n");
                }
                break;
            case 'd':
                 printf("Node #%p| ", inode);
                if ( inode != NULL && inode->down != NULL && current_u_node == NULL )
                { 
                    current_u_node = inode->down; 
                    printf("{down} value: %i\n",current_u_node->data);
                }
                else 
                { 
                    printf("Down is empty.\n");
                }
                break;
            case 'e':
                printf("..");
                break;
            case 'p':
                /* code */
                break;
            case 'g':
                inode = firstnode; 
                current_u_node = NULL;
                printf("Return to start\n"); 
                printf("Node #%p| ", inode);
                break;
            case 'h':
                printf("=======[Act: <console command>]=======\n");
                printf("Right: <r>\n");
                printf("Left: <l>\n"); 
                printf("Up: <u>\n"); 
                printf("Down: <d>\n"); 
                printf("Exit: <e>\n");
                printf("Pop: <p>\n");
                printf("Return to start: <g>\n");
                printf("=======================================\n");
                break;
            case '\n':  // no comments
                break; 
            default:
                printf("Unkonw command <%c>\nWrite <h> (help) in console\n"); 
                break;
        }
    } while(command != 'e');
    return 0; 
}