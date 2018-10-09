#ifndef __LOGFILE_H__
#define __LOGFILE_H__
#include <stdio.h>



FILE* LogFile_OpenLog(char* _fileName);


void LogFile_WriteLine(File* _filePtrW);


void LogFile_CloseLog(File* _filePtrC);


#endif __LOGFILE_H__
