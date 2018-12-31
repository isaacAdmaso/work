/**
 * @file App.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-30
 * 
 * @copyright Copyright (c) 2018
 * 
 */
/*
#include <iostream> //for cerr
#include <unistd.h>
#include <string>
#include <algorithm>  
#include <ctype.h>
#include <stdlib.h>
#include "App.h"
#include "Sfactory.h"
#include "Dfactory.h"
#include "Cfactory.h"
const char*  App::DELIM = "s:d:p:";
const char*  App::ERASE = "eaiou";
const int    App::SHIFT = 13;

const char* App::USAGE = "Usage:  [-s] [console[c],file name] [-d] [console[c],file name][-p] [Erase, Shift, Lower, Upper, Container ]   \
                            [-c Erase Shift Lower Upper ]\n";


App::App(int _iCom, char* _cCom[])
{
    CreateFrom(_iCom,_cCom);
}

App::~App()
{
    delete m_source; 
    delete m_dest; 
    delete m_proc; 
}

void App::Run()
{
    std::string temp;
    temp = m_source->GetString();
    while(temp.length())
    {
        temp = m_proc->Processor(temp);
        m_dest->PutString(temp);
        temp = m_source->GetString();
    }
}

void App::CreateSource(const char* _s)
{
    Sfactory factory;
    std::string con = "console",c = "c";
    
    if(!(con.compare(_s)) || !(c.compare(_s)))
    {
        m_source = factory.GetConsole(); 
    }
    else
    {
        m_source = factory.GetFile(_s);
    }
}

void App::CreateDest(const char* _s)
{
    Dfactory factory;
    std::string con = "console",c = "c";
    
    if(!(con.compare(_s)) || !(c.compare(_s)))
    {
        m_dest = factory.GetConsole(); 
    }
    else
    {
        m_dest = factory.GetFile(_s);
    }
}

void App::CreateProc(const char* _s, std::vector<ITx*>& _vec)
{
    Cfactory factory;
    std::string e = "e",Erase = "Erase",l = "l",Lower = "Lower"\
    ,u = "u",Upper = "Upper",Shift = "Shift",s = "s";

    if(e.compare(_s) || Erase.compare(_s))
        _vec.push_back(factory.GetErase(ERASE));
    else if(l.compare(_s) || Lower.compare(_s))
        _vec.push_back(factory.GetLower());
    else if(u.compare(_s) || Upper.compare(_s))
        _vec.push_back(factory.GetUpper());
    else if(s.compare(_s) || Shift.compare(_s))
        _vec.push_back(factory.GetShift(SHIFT));
}

void App::CreateFrom(int _iCom, char* _cCom[])
{
    int op;
	m_proc = 0;
    std::vector<ITx*> vec;
    Cfactory factory;

	while ((op = getopt(_iCom, _cCom, DELIM)) != -1)
	{
		switch (op)
		{
			case 's':
				CreateSource(optarg);
				break;
			case 'd':
				CreateDest(optarg);
				break;
            case 'p':
                CreateProc(optarg,vec);
			default:
                std::cerr <<USAGE<<std::endl;
                break;
		}
	}
    if(vec.size() == 1)
        m_proc = vec.back();
    else
        m_proc = factory.GetContainer(vec);
    
} 
*/