#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include "logger.h"
#include "config.h"

#define DEC 10


zlog_t zlog = {0};


void zlog_Init(char* _configFile)
{
    char _logName[MAX_WORD_SIZE];
    int _errorLevel;

    Config_GetParametrs(_configFile,_logName,&_errorLevel);
    zlog.m_log_f_Ptr = LogFile_OpenLog(_logName);
    zlog.m_level = _errorLevel;
}

void Zlog_Print(char* _sourceFileName, int _lineNum, char* _func, char* _freeStr, ErrorLevels _level, char* _module)
{
    char line[MAX_LINE_SIZE];
    char time_part[MAX_WORD_SIZE],prossesId[MAX_WORD_SIZE] ;
    time_t now = time (NULL);


    strftime (time_part, 32, "%Y-%m-%dT%H:%M:%S", localtime (&now));
    itoa(getpid(),prossesId,DEC);


    snprintf(line, sizeof(line), "%s: %s: %s", time_part, prossesId, cmd_argv[1]);

}

