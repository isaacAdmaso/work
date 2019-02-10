/**
 * @file Thread.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __THREADEXCEPTION_HPP__
#define __THREADEXCEPTION_HPP__

#include <exception>


class PthreadAttrException: public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Pthread Attr Exception";
	}
}; 

class PthreadCreateException: public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Pthread Create Exception";
	}
}; 

class PthreadJoinException: public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Pthread Join Exception";
	}
};

class PthreadDetachException: public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Pthread Detach Exception";
	}
};

#endif //__THREADEXCEPTION_HPP__