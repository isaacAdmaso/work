#ifndef __LOGFILE_H__
#define __LOGFILE_H__
#include <stdio.h>



FILE* LogFile_OpenLog(char* _fileName);


void LogFile_WriteLine(FILE* _filePtrW,char* _line);


void LogFile_CloseLog(FILE* _filePtrC);


#endif /*__LOGFILE_H__*/
