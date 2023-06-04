#ifndef CRYPTO_LIB_H 
#define CRYPTO_LIB_H 

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#include "string.h"

#include "malloc.h"
//////////////////// 

void CryptoIO(char *text, size_t text_len, char *key, size_t key_len);
bool CryptCompare(size_t text_len); 

#endif 