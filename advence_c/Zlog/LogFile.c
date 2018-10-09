#include "logFile.h"
#include <stdio.h>
#include <assert.h>



FILE* LogFile_OpenLog(char* _fileName)
{
    FILE* logFilePtr = NULL;

    logFilePtr = fopen(_fileName,"w");
    assert(logFilePtr);
    return logFilePtr;
}


void LogFile_WriteLine(File* _filePtrW,char* _line)
{
    fprintf(_filePtrW,"%s",_line);    
}


void LogFile_CloseLog(File* _filePtrC)
{
    fclose(_filePtrC);
}