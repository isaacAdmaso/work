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
#include <vector>
#include <string>
#include "ITx.h"


class App
{
private:
    Isource*        m_source;
    Idest*          m_dest;
    ITx*            m_proc;
    void            CreateFrom(int _iCom, char* _cCom[]); 
    void            CreateSource(const char* _s);     
    void            CreateProc(const char* _s,std::vector<ITx*>& _vec);     
    void            CreateDest(const char* _s);  
    static const char*  DELIM;  
    static const char*  ERASE; 
    static const int    SHIFT; 
    static const char*  USAGE;

public:
    App(int _iCom, char* _cCom[]);
    ~App();
    void Run();
};


#endif //__APP_H__