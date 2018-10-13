#ifndef __TIME_H__
#define __TIME_H__

#include <stddef.h>
#include <time.h>

typedef struct timespec ScdTime;

int Time_Comp(ScdTime _aTaskT,ScdTime _bTaskT);

ScdTime Time_Convert(double _seconds);

ScdTime Time_Add(ScdTime _time,ScdTime _timeToADD);

double Time_To_Dbl(ScdTime _time);

void Time_Tsleep(ScdTime _time);


#endif /**__TIME_H__ */