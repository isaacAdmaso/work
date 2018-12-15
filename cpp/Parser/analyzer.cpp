/**
 * @file analyzer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <ctype.h>
#include "analyzer.h"
#include <vector>


char Analyzer::Predefined_Types[][8] = {"char", "short", "int", "long", "float", "double", "void"};


void Analyzer::Analyze(vector<pair <int ,string> >& _tok)
{
    pair <int ,string> temp;
    int len = _tok.size();
    int PrTypes = sizeof(Predefined_Types)/sizeof(char*);
    for(int i = 0; i < len; ++i)
    {
        temp = _tok[i];
        for(int j = 0; j < PrTypes; ++j)
        {
            if(temp.second ==  Predefined_Types[j])
                cout << "line #"<<temp.first<<" "<<temp.second<<endl;
        }
    }
}


