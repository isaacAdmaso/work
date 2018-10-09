#ifndef __ZLOG_H__
#define __ZLOG_H__

#include "string.h"
#include <time.h>
#include "write.h"



typedef struct configData
{
    char m_level[16];
    char m_fileTo[256];
}configData;
  

/*
char* log_level_full[]= {"LOG_TRACE","LOG_DEBUG","LOG_INFO","LOG_WARNING","LOG_ERROR","LOG_CRITICAL","LOG_SEVERE","LOG_FATAL","LOG_NONE"};
char* log_level_short[]= {"T","D","I","W","E","C","S","F","N"};

char* Write(char* _module,char* _level, char* _str)
{
    char msg [512];
    time_t timeN;

    timeN = time(NULL);
    
    

}

#define ZLOG(FNAME,LEVEL,STR) Write(FNAME,LEVEL,STR)
*/

void Zlog_Init(char* _fileName);
void Zlog_Destroy(void);


#endif /*__ZLOG_H__*/
