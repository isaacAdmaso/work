#ifndef __TIME_H__
#define __TIME_H__

#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 500
#endif /* __STDC_VERSION__ */

#include <stddef.h>
#include <time.h>

typedef struct timespec ScdTime;

int Time_Comp(ScdTime _aTaskT,ScdTime _bTaskT);

ScdTime Time_Convert(double _seconds);

ScdTime Time_Get_Start();

ScdTime Time_Get_End();

ScdTime Time_Add(ScdTime _time,ScdTime _timeToADD);

double Time_To_Dbl(ScdTime _time);

void Time_Tsleep(ScdTime _time);

ScdTime Time_Subt(ScdTime time2,ScdTime time1);


#endif /**__TIME_H__ */