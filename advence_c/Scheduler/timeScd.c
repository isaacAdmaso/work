#include "timeScd.h"
#include <stdio.h>




int Time_Comp(ScdTime _aTaskT,ScdTime _bTaskT)
{
	if (_bTaskT.tv_sec > _aTaskT.tv_sec)
		return 1;
    if (_bTaskT.tv_sec < _aTaskT.tv_sec)
		return 0;
	return ((_bTaskT.tv_nsec - _aTaskT.tv_nsec) > 0);
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

ScdTime Time_Get_Start()
{
	ScdTime ref;

    clock_gettime(CLOCK_REALTIME,&ref);

    return ref;
}

ScdTime Time_Get_End()
{
    return Time_Get_Start();
}

ScdTime Time_Subt(ScdTime time2,ScdTime time1)
{
    ScdTime result;

        	/* TIME1 <= TIME2 */
    if ((time1.tv_sec < time2.tv_sec) ||
       ((time1.tv_sec == time2.tv_sec) &&
        (time1.tv_nsec <= time2.tv_nsec)))
    {
        result.tv_sec = result.tv_nsec = 0 ;
    }
            /* TIME1 > TIME2 */
    else
    {
        result.tv_sec = time1.tv_sec - time2.tv_sec ;
        if (time1.tv_nsec < time2.tv_nsec)
        {
            result.tv_nsec = time1.tv_nsec + 1000000000L - time2.tv_nsec ;
            result.tv_sec-- ;				/* Borrow a second. */
        }
        else
        {
            result.tv_nsec = time1.tv_nsec - time2.tv_nsec ;
        }
    }
    return result;
}
/*
*/


