#ifndef BINARY_LIB
    #define BINARY_LIB 
    #include "mytypes.h"

    void BinarySave(FILE *thread, struct Routes *info); 
    FILE *BinaryCreate(char path[]); 
#endif