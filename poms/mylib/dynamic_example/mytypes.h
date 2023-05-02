#ifndef MYTYPES_LIB
    #define MYTYPES_LIB 
    #include "stdio.h"

    struct Route 
    { 
        int start; 
        int end; 
        int number_route; 
    };

    struct Routes 
    { 
        struct Route *r; 
        size_t r_counts; 
    };
#endif