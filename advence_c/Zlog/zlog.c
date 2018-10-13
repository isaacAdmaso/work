#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include "logger.h"

#define DEC 10

 zlog_t zlog = {0};



void Zlog_Init(char* _configFile)
{
    char _logName[MAX_WORD_SIZE];
    int _errorLevel;

    Config_GetParametrs(_configFile,_logName,&_errorLevel);
    zlog.m_log_f_Ptr = LogFile_OpenLog(_logName);
    zlog.m_level = _errorLevel;
}
static void EnumToStr(int _level,char* _strEnum)
{
    char* enum_string_short[] = {"T","D","I","W","E","C","S","F","N"};
    strcpy(_strEnum,enum_string_short[_level]);
}

void Zlog_Print(char* _sourceFileName, int _lineNum,const char* _func, char* _freeStr, ErrorLevels _level, char* _module)
{
    char line[MAX_LINE_SIZE];
    char time_part[MAX_WORD_SIZE] ,leve_str[MAX_WORD_SIZE] ;
    
    GeTime(time_part);
    EnumToStr(_level,leve_str);

    sprintf(line, "%s %d %u %s %s %s@%s %d %s\n", time_part, getpid(),(unsigned int)pthread_self(),leve_str,_module,_func,_sourceFileName,_lineNum,_freeStr);
    LogFile_WriteLine(zlog.m_log_f_Ptr,line);
}

void Zlog_Destroy()
{
    LogFile_CloseLog(zlog.m_log_f_Ptr);

}

