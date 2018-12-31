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
    void            CreateFrom(const std::string& _com);      
public:
    App(const std::string& _com);
    ~App();
    void Run();
};


#endif //__APP_H__