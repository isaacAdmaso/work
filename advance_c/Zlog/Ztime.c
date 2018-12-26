#include "Ztime.h"
#include <string.h>
#include <stdio.h>


void GeTime(char* _timeStr)
{
    struct timeval tv;
    time_t nowtime;
    struct tm *nowtm;
    char buf[64];

    gettimeofday(&tv, NULL);
    nowtime = tv.tv_sec;
    nowtm = localtime(&nowtime);
    strftime(buf, sizeof buf, "%Y-%m-%d %H:%M:%S", nowtm);
    sprintf(_timeStr, "%s.%.3ld", buf, tv.tv_usec/1000);
}
