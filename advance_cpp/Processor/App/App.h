/**
 * @brief 
 * 
 */
#ifndef __APP_H__
#define __APP_H__
//sources
#include "Isource.h"

//Destination
#include "Idest.h"

//Process
#include <string>
#include "ITx.h"


class App
{
private:
    Isource*        m_source;
    Idest*          m_dest;
    ITx*            m_proc;
    void            CreateFrom(const char* _com[]);      
public:
    App(const char* _com[]);
    ~App();
    void Run();
};


#endif //__APP_H__