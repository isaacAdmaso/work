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
    ERR_WRONG_INDEX,
    /* BST  Errors */
    ERR_ALREADY_EXISTS,
	ERR_NOT_EXISTS
} ADTErr;

#endif
