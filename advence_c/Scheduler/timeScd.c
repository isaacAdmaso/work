#include "timeScd.h"
#include <stdio.h>



int Time_Comp(ScdTime _aTaskT,ScdTime _bTaskT)
{
	if (_bTaskT->tv_sec > _aTaskT->tv_sec)
		return 1;
    if (_bTaskT->tv_sec < _aTaskT->tv_sec)
		return 0;
	return ((_bTaskT->tv_nsec - _aTaskT->tv_nsec) > 0);
}

ScdTime Time_Convert(double _seconds)
{
	ScdTime  rtTime ;

    if (_seconds < 0)
	{					
        rtTime.tv_sec = 0 ;  rtTime.tv_nsec = 0 ;
    } 
	else
	{						/* Valid time. */
        rtTime.tv_sec = (time_t) _seconds ;
        rtTime.tv_nsec = (long) ((_seconds - (double) rtTime.tv_sec) * 1000000000.0) ;
    }

    return rtTime ;
}

ScdTime Time_Add(ScdTime _time,ScdTime _timeToADD)
{
    ScdTime  rtTime ;

/* Add the two times together. */

    rtTime.tv_sec = _time.tv_sec + _timeToADD.tv_sec ;
    rtTime.tv_nsec = _time.tv_nsec + _timeToADD.tv_nsec ;
    if (rtTime.tv_nsec >= 1000000000L) {		/* Carry? */
        rtTime.tv_sec++ ;  rtTime.tv_nsec = rtTime.tv_nsec - 1000000000L ;
    }

    return rtTime ;

}

double Time_To_Dbl(ScdTime _time)
{
    return ((double) _time.tv_sec + (_time.tv_nsec / 1000000000.0));
}

void Time_Tsleep(ScdTime _time)
{
	ScdTime ref;

	nanosleep(&_time,&ref);
}


