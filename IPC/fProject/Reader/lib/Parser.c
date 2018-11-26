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
#include <stdio.h>
#include <string.h>

#define FORMATETKN       "|"


void* Parser1(char* _lineCDR)
{
    void* cdr = NULL;
    char *field;
    int i = 0;
    size_t formatLength;
    char inputOrder[] = STR_CDR_ORDER;
    const char s[2] = FORMATETKN;

    if(!(cdr = Cdr_Create()))
        return NULL;
    
    formatLength = strlen(STR_CDR_ORDER);
    field = strtok(_lineCDR, s);
    for(i = 0; i < formatLength;++i) 
    {
        Cdr_Set(cdr,inputOrder[i],field);
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