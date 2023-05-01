//#include "mylib/fbinary/fbinary.h" // my static lib
//Shared Lib

#include "stdio.h"
#include "stdlib.h"

typedef struct Route
{
    int end; 
    int start; 
    int number_route; 
} _Route;

typedef struct Routes
{ 
    _Route *r;
    size_t r_counts; 
} _Routes; 

FILE *BinaryCreate(char path[]) 
{ 
    FILE *thread = fopen(path, "wb"); 
    
    if (thread == NULL)
    { 
        printf("Sorry, file not opened.\n");
        exit(0); 
    }
    else 
        printf("File opened!\n"); 

    return thread;  
} 

void BinarySave(FILE *thread, _Routes *info)
{ 
    int bytes = sizeof(info); 

    char *c; 

    c = (char *)info; 
    for(size_t i = 0; i < info->r_counts; i++)
    {
        fwrite(&(info->r[i]), sizeof(info->r[i]), 1, thread); 
    }
}

_Route BinaryRead(FILE *thread)
{ 

}
//Shared libend 

#define OutFile "outfiles/Spravka.dat"

void RoutePrint(_Route *r)
{
    printf("start->end: (%i %i) number: %i\n", r->start, r->end, r->number_route);
}

void RoutesPrint(_Routes *rs) 
{ 
    printf("\n");
    for(size_t i = 0; i < rs->r_counts; i++)
    { 
        RoutePrint(&(rs->r[i]));
    }
    printf("\n");
}

void RoutesFree(_Routes *rs) 
{ 
    rs->r = NULL; 
    free(rs->r);
    free(rs);
}

void Handl();

int main() 
{
    FILE *thread = BinaryCreate(OutFile); 
    // thread определён. 
    size_t r_count; 
    printf("Master generation file Spravka.dat\n"); 
    printf("Insert your routes count: "); scanf("%li", &r_count);

    _Routes *r = (_Routes*)malloc(sizeof(_Routes)); 
    r->r_counts = r_count; 
    r->r = (_Route*)malloc(sizeof(_Route) * r_count); 

    for(size_t i = 0; i < r_count; i++)
    { 
        r->r[i].number_route = i; 
        r->r[i].start = rand() % ( 5 - 0 + 1 ); 
        r->r[i].end = rand() % ( 9 - 6 + 1 ) + 6; 
    }

    RoutesPrint(r);

    printf("Start saving.. \n"); 
    printf("Bytes: %i", sizeof(r));

    BinarySave(thread, r); 

    printf("Okey..\n"); 

    fclose(thread);
    RoutesFree(r); 

    Handl(r_count); 

    return 0;
}

void Handl(size_t count) 
{ 
    FILE *thread = fopen(OutFile, "rb"); 

    int number; 
    printf("Insert number route: "); scanf("%i", &number);

    _Routes *rs = (_Routes*)malloc(sizeof(_Routes)); 
    rs->r_counts = count; 
    rs->r = (_Route*)malloc(sizeof(_Route) * count); 

    int index = 0; 
    _Route finded; 
    int notfinded = 1; 
    while(!feof(thread))
    { 
        fread(&(rs->r[index]), sizeof(rs->r[index]), 1, thread); 
        if(rs->r[index].number_route == number)
        {
            finded.start=rs->r[index].start; 
            finded.end=rs->r[index].end; 
            finded.number_route=rs->r[index].number_route; 

            notfinded = 0; 
        }
    }

    if(notfinded == 1)
    { 
        printf("This number route not does not exist");
    }
    else
    { 
        printf("Search result: "); 
        RoutePrint(&finded);
    }

    //Bin
}