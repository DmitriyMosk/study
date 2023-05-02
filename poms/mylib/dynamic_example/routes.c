#include "routes.h"
#include "stdlib.h"
#include "malloc.h"

void RoutePrint(struct Route *r)
{
    printf("start->end: (%i %i) number: %i\n", r->start, r->end, r->number_route);
}

void RoutesPrint(struct Routes *rs) 
{ 
    printf("\n");
    for(size_t i = 0; i < rs->r_counts; i++)
    { 
        RoutePrint(&(rs->r[i]));
    }
    printf("\n");
}

void RoutesFree(struct Routes *rs) 
{ 
    rs->r = NULL; 
    free(rs->r);
    free(rs);
}