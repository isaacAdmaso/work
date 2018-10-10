#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include "logger.h"
#include "config.h"

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
/*
static void GetTime(char*_time)
{
    struct timeval tmnow;
    struct tm *curTime;
    char usec_buf[3];
    time_t now;


    gettimeofday(&tmnow, NULL);
    curTime = localtime (&now);
    snprintf(usec_buf,3,"%d",(int)tmnow.tv_usec);
    sprintf(_time, "%d-%d-%d\t%d:%d:%d.%s",curTime->tm_year + 1900, curTime->tm_mon + 1,\
                 curTime->tm_mday, curTime->tm_hour, curTime->tm_min, curTime->tm_sec,usec_buf);

}
*/

void Zlog_Print(char* _sourceFileName, int _lineNum,const char* _func, char* _freeStr, ErrorLevels _level, char* _module)
{
    char line[MAX_LINE_SIZE];
    char time_part[MAX_WORD_SIZE] ,leve_str[MAX_WORD_SIZE] ;
    time_t now;
    struct tm * curTime;

    time(&now);
    curTime = localtime (&now);
    sprintf(time_part, "%d-%d-%d\t%2d:%2d:%2d ",curTime->tm_year + 1900, curTime->tm_mon + 1,\
                 curTime->tm_mday, curTime->tm_hour, curTime->tm_min, curTime->tm_sec);
/*    
    GetTime(time_part);
*/
    EnumToStr(_level,leve_str);

    sprintf(line, "%s %d %u %s %s %s@%s %d %s\n", time_part, getpid(),(unsigned int)pthread_self(),leve_str,_module,_func,_sourceFileName,_lineNum,_freeStr);
    LogFile_WriteLine(zlog.m_log_f_Ptr,line);
}

void Zlog_Destroy()
{
    LogFile_CloseLog(zlog.m_log_f_Ptr);

}

