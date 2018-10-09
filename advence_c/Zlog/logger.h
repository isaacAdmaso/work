#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <stdio.h>
#include "zlogStruct.h"



extern zlog;

#define ZLOG(MODULE,LEVEL,MSG) \
			do{if(zlog.m_level <= LEVEL) \
				Zlog_Print(__SOURCE_FILE__,__LINE__,__func__,MSG ,LEVEL ,MODULE);}while(0)


typedef enum ErrorLevels
{
    	LOG_TRACE,			/*Trace message usually very detailed*/ 
    	LOG_DEBUG,			/*A message useful for debugging*/
    	LOG_INFO,			/*Informative message*/
    	LOG_WARNING,		/*Warning*/
    	LOG_ERROR,			/*An error occurred*/ 
	    LOG_CRITICAL,		/*Critical error*/
    	LOG_SEVERE,		    /*Server error requiring immediate intervention*/
    	LOG_FATAL,			/*Fatal error signaling an emergency*/
    	LOG_NONE			/*Used only in configuration file*/
} ErrorLevels;



void zlog_Init(char* _configFile);

    /*logfile write*/
void Zlog_Print(char* _sourceFileName, int _lineNum, char* _func, char* _freeStr, ErrorLevels _level, char* _module);

    /*logfile close*/
void Logger_Destroy();

#endif __LOGGER_H__

/*do{ if(!(e)) return __LINE__;} while(0)*/