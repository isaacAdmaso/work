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
    char* enum_string_long[] = {"LOG_TRACE\n","LOG_DEBUG\n","LOG_INFO\n","LOG_WARNING\n","LOG_ERROR\n","LOG_CRITICAL\n","LOG_SEVERE\n","LOG_FATAL\n","LOG_NONE\n"};
    char* enum_string_short[] = {"T\n","D\n","I\n","W\n","E\n","C\n","S\n","F\n","N\n"};
    
    for(i = 0;i < ENUM_SIZE;++i)
    {
        if (!strcmp(enum_string_long[i],_enumStr) || !strcmp(enum_string_short[i],_enumStr))
            break;
    }
    return i;
}
static void GetLastWord(FILE* _conFp,char* word)
{
    char line[MAX_LINE_SIZE];
    char* wrdP;

    assert(_conFp != NULL);
    fgets(line,sizeof(line),_conFp);
    wrdP = strtok(line," =");
    wrdP = strtok(NULL," =");
    strcpy(word ,wrdP);
}
/**
 * @brief 
 * 
 */
void Config_GetParametrs(char* _configName, char* _logName, int* _errorLevel)
{
    FILE* conFp = OpenConfig(_configName);
    char level[MAX_WORD_SIZE];

    assert(conFp != NULL);
    GetLastWord(conFp,level);
    *_errorLevel = StrToEnum(level);
    GetLastWord(conFp,_logName);
    CloseConfig(conFp);
}