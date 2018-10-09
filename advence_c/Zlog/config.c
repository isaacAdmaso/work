#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define ENUM_SIZE  9


static FILE* OpenConfig(char*_configFileN)
{
    FILE* conFp = NULL;
    
    conFp = fopen(_configFileN,"r");
    assert(conFp != NULL);
    return conFp;
}
static void CloseConfig(FILE* _configFile)
{
    assert(_configFile != NULL);
    fclose(_configFile);
}
static int StrToEnum(char* _enumStr)
{
    int i;
    char* enum_string_long[] = {"LOG_TRACE","LOG_DEBUG","LOG_INFO","LOG_WARNING","LOG_ERROR","LOG_CRITICAL","LOG_SEVERE","LOG_FATAL","LOG_NONE"};
    char* enum_string_short[] = {"T","D","I","W","E","C","S","F","N"};
    
    for(i = 0;i < ENUM_SIZE;++i)
    {
        if (!strcmp(enum_string_long[i],_enumStr) || !strcmp(enum_string_long[i],_enumStr))
            break;
    }
    return i;
}
static void GetLastWord(FILE* _conFp,char* word)
{
    char line[MAX_LINE_SIZE];

    assert(_conFp != NULL);
    fgets(line,sizeof(line),_conFp);
    strtok(line,"=");
    strcpy(word ,strtok(line,"="));
}
/**
 * @brief 
 * 
 */
void Config_GetParametrs(char* _configName, char* _logName, int* _errorLevel)
{
    int i;
    FILE* conFp = OpenConfig(_configName);
    char level[MAX_WORD_SIZE];

    GetLastWord(conFp,level);
    *_errorLevel = StrToEnum(level);
    GetLastWord(conFp,_logName);
    CloseConfig(conFp);
}