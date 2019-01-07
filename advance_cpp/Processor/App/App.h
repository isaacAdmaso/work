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
#include "Cfactory.h"


class App
{
public:
    App(std::vector<std::string>& _com);
    void Run();

private:
    typedef std::vector<std::string>::iterator iter_t;

private:
    Isource*        m_source;
    Idest*          m_dest;
    ITx*            m_proc;

private:
    void CreateDest(std::string& _com);
    void CreateSource(std::string& _com);
    void CreateProc(std::vector<std::string>& _com,iter_t curr);
    void CreateProcH(Cfactory& factory,std::string _s,std::vector<ITx*>& _proc,int* _e,int* _f);
};



#endif //__APP_H__

/*
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
    static const char*  USAGE;

public:
    App(int _iCom, char* _cCom[]);
    ~App();
    void Run();
};
*/