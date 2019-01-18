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
#include <stdlib.h>     /* atoi */
#include "App.h"
#include "Sfactory.h"
#include "Dfactory.h"
#include "Cfactory.h"

void App::CreateProcH(Cfactory& factory,std::string _s,std::vector<ITx*>& _proc, int *_e,int *_f)
{
    switch(_s[0])
    {
        case 'e':
        case 'E':
            *_e = 1;
            break;
        case 'l':
        case 'L':
            _proc.push_back(factory.GetLower());
            break;
        case 'u':
        case 'U':
            _proc.push_back(factory.GetUpper());
            break;
        case 's':
        case 'S':
            *_f = 1;
            break;
        default:
            break;
    }
}

void App::CreateProc(std::vector<std::string>& _com, iter_t curr)
{
    Cfactory factory;
    std::vector<ITx*> vProc;
    iter_t end = _com.end();
    int Eflag = 0,Sflag = 0;

    for(;curr != end; ++curr)
    {
        if(Eflag)
        {
            vProc.push_back(factory.GetErase(*curr));
            Eflag = 0;
        }
        if(Sflag)
        {
            vProc.push_back(factory.GetShift(atoi((*curr).c_str())));
            Sflag = 0;
        }
        CreateProcH(factory,*curr,vProc,&Eflag,&Sflag);
    }
    
    m_proc = (1 == vProc.size())? vProc.back(): factory.GetContainer(vProc);
}

void App::CreateSource(std::string& _com)
{
    Sfactory sF;

    if(!(_com.compare("c")) || !(_com.compare("console")))
    {
        m_source = sF.GetConsole();
    }else
    {
        m_source = sF.GetFile(_com); 
    }

}

void App::CreateDest(std::string& _com)
{
    Dfactory dF;

    if(!(_com.compare("c")) || !(_com.compare("console")))
    {
        m_dest = dF.GetConsole();
    }
    else if(!(_com.compare("vector")))
    {
        m_dest = dF.GetContainer();
    }
    else
    {
        m_dest = dF.GetFile(_com); 
    }

}

App::App(std::vector<std::string>& _com)
{

    iter_t curr = _com.begin();

    m_proc = NULL;
    CreateSource(*curr++);//<--((*curr)++) <-(*curr);curr++;
    CreateDest(*curr++);
    if(curr != _com.end())
        CreateProc(_com,curr);
    
}

Idest* App::Run()
{
    if(m_source)
    {
        std::string temp = m_source->GetString();
        while(temp.length())
        {
            if(m_proc)
                temp = m_proc->Processor(temp);
            m_dest->PutString(temp);
            temp = m_source->GetString();
        }
    }
    return m_dest;
}






















































/*
#include <iostream> //for cerr
#include <unistd.h>
#include <string>
#include <algorithm>  
#include <ctype.h>
#include <stdlib.h>
#include "App.h"
const char*  App::DELIM = "s:d:p:";

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