/**
 * @file Container.h
 * @brief 
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include <typeinfo>
#include <algorithm>    // std::find_if
#include <list>
#include <vector>
#include "predicate.h"

using namespace std;
template<class T,class Container>
//template<typename T,template <typename, typename = std::allocator<T*> > class Container>

class Container_t
{

    typedef typename Container::iterator	iter_t;

private:
    Container      myContainer;
    Container_t(Container_t& _c){}
    Container_t& operator = (const Container_t _c);
    T helper(size_t _idx)    {
        if(_idx >= myContainer.size())
            return *(myContainer.begin());
        if(typeid(myContainer) == typeid(vector<T*>)){
            return *(myContainer[_idx]);
        }else {
            iter_t it = myContainer.begin();
            while(it != myContainer.end()){if(_idx == 0) return **it; --_idx; ++it;}
            return *(myContainer.begin());
        }
    }

public:
    Container_t(){}
    ~Container_t(){}

    bool isEmpty()const{return myContainer.empty();}
    size_t nItems()const{return myContainer.size();}
    void    insertNew(T& _item){return myContainer.push_back(&_item);}
    T       firstItem()const {return *(myContainer.front());}
    T       lastItem()const {return  *(myContainer.back());}
    T*      findItem(const T& _item)
    {
        iter_t it = find_if (myContainer.begin(), myContainer.end(),  predicate<T>(_item));
        if(it == myContainer.end())
            return *(--it);
        return *it;
    }
    T*      eraseItem(const T _item)
    {
        iter_t it2,it1 = find_if (myContainer.begin(), myContainer.end(), predicate<T>(_item));
        if(it1 == myContainer.end())
            return *(--it1);
        it2 = myContainer.erase(it1);
        return *it2;
    }
    void    eraseAll(){myContainer.erase(myContainer.begin(), myContainer.end());}
    T       operator [] (size_t _idx){return helper(_idx);}

};


  





#endif //__CONTAINER_H__