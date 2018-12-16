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
#include <string>
#include "analyzer.h"
#include <vector>


const string Analyzer::TokenString = "{}<>[]()+-";
char const Analyzer::Predefined_Types[][8] = {"char", "short", "int", "long", "float", "double", "void"};
char const Analyzer::Key_words[][16] = {"if", "else", "for" , "while", "class", "private", "public", "protected", "main", "const", "virtual"};
char const Analyzer::Operators[][8] = {"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>"};
int  Analyzer::PrTypes = sizeof(Predefined_Types)/sizeof(void*);
int  Analyzer::Kwords = sizeof(Key_words)/sizeof(void*);
int  Analyzer::Op = sizeof(Operators)/sizeof(void*);
int  Analyzer::firstTok = 1;
int  Analyzer::typeFlag = 0;
int  Analyzer::ifFlag = 0;
int  Analyzer::parenCount[4] = {0};
int  Analyzer::plus_minusCounter[2] = {0};

void Analyzer::Analyze(vector<pair <int ,string> >& _tok)
{
    pair <int ,string> temp;
    int len = _tok.size();
    iter_t itr;
    
    for(int i = 0; i < len; ++i)
    {
        temp = _tok[i];
        if(firstTok){
            if(temp.second.compare("main"))
                cout<<"//line "<<temp.first<<":error, illegal - declaration before 'main'"<<endl;
            firstTok = 0;
        }else if(temp.second.find_first_of(TokenString) != string::npos){
            if(typeFlag){
                cout<<"//line "<<temp.first<<":error, illegal variable name:"<<temp.second<<endl;
                typeFlag = 0;
            }
            switch (temp.second[0]){
                case '{':
                    ++parenCount[0]; 
                    plus_minusCounter[0] = 0;
                    plus_minusCounter[1] = 0; 
                    break;
                case '}':
                    --parenCount[0];
                    plus_minusCounter[0] = 0;
                    plus_minusCounter[1] = 0; 
                    if(parenCount[0] < 0){
                        cout<<"//line "<<temp.first<<" error, “}” without “{“"<<endl;
                        parenCount[0] = 0;
                    }
                    break;
                case '(':
                    plus_minusCounter[0] = 0;
                    plus_minusCounter[1] = 0; 
                    ++parenCount[1]; 
                    break;
                case ')':
                    plus_minusCounter[0] = 0;
                    plus_minusCounter[1] = 0; 
                    --parenCount[1]; 
                    if(parenCount[1] < 0){
                        cout<<"//line "<<temp.first<<" error, “)” without “(“"<<endl;
                        parenCount[1] = 0;
                    }
                    break;
                case '[':
                    plus_minusCounter[0] = 0;
                    plus_minusCounter[1] = 0; 
                    ++parenCount[2]; 
                    break;
                case ']':
                    --parenCount[2];
                    plus_minusCounter[0] = 0;
                    plus_minusCounter[1] = 0; 
                    if(parenCount[2] < 0){
                        cout<<"//line "<<temp.first<<" error, “]” without “[“"<<endl;
                        parenCount[2] = 0;
                    }
                    break;
                case '<':
                    plus_minusCounter[0] = 0;
                    plus_minusCounter[1] = 0; 
                    ++parenCount[3]; 
                    break;
                case '>':
                    plus_minusCounter[0] = 0;
                    plus_minusCounter[1] = 0; 
                    --parenCount[3];
                    if(parenCount[3] < 0){
                        cout<<"//line "<<temp.first<<" error, “>” without “<“"<<endl;
                        parenCount[3] = 0;
                    }
                    break;
                case '+':
                     plus_minusCounter[1] = 0;
                    ++plus_minusCounter[0];
                    if( 2 < plus_minusCounter[0]){
                        cout<<"//line "<<temp.first<<" error, no operator +++ or ---"<<endl;
                        plus_minusCounter[0] = 0;
                    }
                    break;
                case '-':
                     plus_minusCounter[0] = 0;
                    ++plus_minusCounter[1];
                    if( 2 < plus_minusCounter[1]){
                        cout<<"//line "<<temp.first<<" error, no operator +++ or ---"<<endl;
                        plus_minusCounter[1] = 0;
                    }
                default:
                    break;
            }
        }else if( (itr = cTypes.find(temp.second)) !=  cTypes.end()){
            if(typeFlag){
                cout<<"//line "<<temp.first<<":error multiple type declaration"<<endl;
                typeFlag = 0;
            }else{
                typeFlag = 1;
            }
            plus_minusCounter[0] = 0;
            plus_minusCounter[1] = 0; 
        }else if( (itr = cKeys.find(temp.second)) != cKeys.end()){
            if(typeFlag){
                cout<<"//line "<<temp.first<<":error, illegal variable name:"<<temp.second<<endl;
                typeFlag = 0;
            }
            if(temp.second.compare("if")){
                ++ifFlag;
            }else if(temp.second.compare("else")){
                --ifFlag;
                if(ifFlag < 0){
                    cout << "//line "<<temp.first<<"“else” without “if”"<<endl;
                    ifFlag = 0;
                }
            }
            plus_minusCounter[0] = 0;
            plus_minusCounter[1] = 0; 
        }else if((itr = cOper.find(temp.second)) != cOper.end()){
            if(typeFlag){
                cout<<"//line "<<temp.first<<":error, illegal variable name:"<<temp.second<<endl;
                typeFlag = 0;
            }
            plus_minusCounter[0] = 0;
            plus_minusCounter[1] = 0; 
        }else{
            plus_minusCounter[0] = 0;
            plus_minusCounter[1] = 0; 
            if(!typeFlag){
                cout<<"//line "<<temp.first<<":error,"<<temp.second<< " :is not declared"<<endl;
                typeFlag = 0;
            }else if(isalpha(temp.second[0]) || (temp.second[0] == '_') ){
                if((m_tCont.find(temp.second)) != m_tCont.end())
                    cout<<"//line "<<temp.first<<":error,"<<temp.second<< " :is not declared"<<endl;
                m_tCont.insert(temp.second);
            }else{
                cout<<"//line "<<temp.first<<":error,illegal variable name"<<endl;
            }
        }
    }
}





