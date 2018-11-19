/**
 * @file Parser.c
 * @brief  parsing line to struct cdr
 * @version 0.1
 * @date 2018-11-19
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "CDR.h"
#include "Parser.h"
#include <string.h>

#define STR_CDR_ORDER    "IiMmCTDdlpc"
#define FORMATETKN       "|"
#define FORMATESZ        12


void* Parser1(char* _lineCDR)
{
    void* cdr = NULL;
    char *field;
    int i = 0;
    char inputOrder[FORMATESZ] = STR_CDR_ORDER;
    const char s[2] = FORMATETKN;

    if(!(cdr = Cdr_Create()))
        return NULL;
    
    field = strtok(_lineCDR, s);
    while( field != NULL ) 
    {
        Cdr_Set(cdr,inputOrder[i],field);
        ++i;
        field = strtok(NULL, s);
    }
    return cdr;
}
/*
int main()
{
    char line[256] = "23423|21345|235|1234|1235|1253|2135|1234|2134|789|3673";
    void* cdr;

    cdr = Parser1(line);
    Print_Cdr(cdr);



    return 0;
}
*/