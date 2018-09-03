#ifndef __ADTDefs_H__
#define __ADTDefs_H__

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
    ERR_NOT_FOUND,
    ERR_ALREADY_EXISTS,
    ERR_WRONG_INDEX

} ADTErr;

#endif
