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
#include <string>
#include "App.h"
#include "Sfactory.h"
#include "Dfactory.h"
#include "Cfactory.h"


App::App(const std::string& _com)
{
    CreateFrom(_com);
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

void App::CreateFrom(const std::string& _com)
{
    
} 