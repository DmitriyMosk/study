#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#include "wchar.h"

#include "malloc.h"
//////////////////// 

void CryptoIO(wchar_t *buffer, wchar_t *key, char flag, size_t buff_len, size_t key_len);
bool CryptCompare(wchar_t *src, wchar_t *dest); 