#ifndef __TIME_H__
#define __TIME_H__

#include <stddef.h>
#include "time.h"

typedef  timespec ScdTime;

int Time_Comp(ScdTime,ScdTime);

ScdTime Time_convert(double _time);

ScdTime Time_Add(ScdTime _time);

void Time_Tsleep(ScdTime _time);


#endif /**__TIME_H__ */