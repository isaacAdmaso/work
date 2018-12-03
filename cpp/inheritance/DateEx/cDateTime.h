/**
 * @file cDateTime.h
 * @brief 
 * @version 0.1
 * @date 2018-12-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __DATEANDTIME_H__
#define __DATEANDTIME_H__
#include "cTime.h"
#include "cDate.h"

class cDateTime_t:public cTime_t,public cDate_t
{
private:
public:
    cDateTime_t(){}
    ~cDateTime_t(){}
};

inline ostream&  operator << (ostream& _os,const cDateTime_t _w)
{
    cout<<"from base Time: " << _w.getTime() << "from base Time: "<<_w.getDate()<< endl;
    return _os;
}



#endif /*__DATEANDTIME_H__*/