/**
 * @file token.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <vector>
#include <string>
#include <ctype.h>
#include <bits/stdc++.h> 
#include "token.h"

using namespace std;



vector<std::string>& Token::Tok(vector<std::string>& vec,string& word){
    stringstream stringStream(word);
    string temp,line;
    size_t prev, pos;

    while(getline(stringStream, line,' ')) 
    {
        prev = 0;
        while ((pos = line.find_first_of(delimiter, prev)) != string::npos)
        {
            if (pos > prev)
            {
                temp = line.substr(prev, pos-prev);
                vec.push_back(temp);
            }
            if (!isspace(line[pos])){
                temp = line[pos];
                vec.push_back(temp);
            }
            prev = pos+1;
        }
        if (prev < line.length()){
            temp = line.substr(prev, string::npos);
            if (!isspace(temp[0]))
                vec.push_back(temp);
        }
    }
    return vec;
}


//template <typename ForwardIterator, typename UnaryPredicate>
    //ForwardIterator remove_if (ForwardIterator first, ForwardIterator last,UnaryPredicate pred)
    //{
    //ForwardIterator result = first;
    //while (first!=last) {
    //    if (!pred(*first)) {
    //    *result = move(*first);
    //    ++result;
    //    }
    //    ++first;
    //}
    //return result;
    //}

/*
    size_t found = 0,lastTok = 0;
    m_line = pLine.second;
    string buff;


    stringstream check1(m_line.c_str());


    while(getline(check1, m_line, ' ')) 
    {
        int len = m_line.length();
        for (int i=0; i< len; ++i){
            found = delimiter.find(m_line[i]);
            if(found != string::npos)   {
                temp.first = pLine.first;
                temp.second = m_line.substr(lastTok,i - lastTok);
                m_vec.push_back(temp); 
                lastTok = i;
            }
        }
    } 
vector<string> Token::Tok(string& _line)
{
    regex re(Token::delimiter);
    
    return vector<string>(sregex_token_iterator(_line.begin(), _line.end(), re, -1),sregex_token_iterator());
}
*/