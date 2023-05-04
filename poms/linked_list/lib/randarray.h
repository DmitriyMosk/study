#ifndef RANDARR_LIB
#define RANDARR_LIB

#include "types.h"

    IArray *IArrayCreate(size_t len);
    void IArrayRandomize(IArray *arr, Range range); 
    Range _Range(); 

#endif 



