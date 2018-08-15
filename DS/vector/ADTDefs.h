#ifndef ADTDefs_H
#define ADTDefs_H
#include<stddef.h>
#include "vector.h"
typedef enum
{
    /* General ADT Errors */
    ERR_OK = 0,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX
    /* Stack  Errors */
} ADTErr;

#endif
