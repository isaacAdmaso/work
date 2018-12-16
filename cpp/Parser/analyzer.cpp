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
char Analyzer::Key_words[][16] = {"if", "else", "for" , "while", "class", "private", "public", "protected", "main", "const", "virtual"};
char Analyzer::Operators[][8] = {"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>"};

void Analyzer::Analyze(vector<pair <int ,string> >& _tok)
{
    pair <int ,string> temp;
    int len = _tok.size();
    int PrTypes = sizeof(Predefined_Types)/sizeof(char*);
    int Kwords = sizeof(Key_words)/sizeof(char*);
    int Op = sizeof(Operators)/sizeof(char*);
    int max = ( PrTypes < Kwords ) ? ((Kwords < Op) ? Op : Kwords):((PrTypes < Op) ? Op : PrTypes);
    for(int i = 0; i < len; ++i)
    {
        temp = _tok[i];
        for(int j = 0; j < max; ++j)
        {
            if( (j < PrTypes) && (!temp.second.compare(Predefined_Types[j])))
            {
                cout << "line #"<<temp.first<<endl<<"Predefined_Type: "<<temp.second<<endl;
            }else if((j < Kwords)&&(!temp.second.compare(Key_words[j])))
            {
                cout << "line #"<<temp.first<<endl<<"Key_word: "<<temp.second<<endl;
            }else if((j < Op)&&(!temp.second.compare(Operators[j])))
            {
                cout << "line #"<<temp.first<<endl<<"Operator: "<<temp.second<<endl;
            }
        }
    }
}


