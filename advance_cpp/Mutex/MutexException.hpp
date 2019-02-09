/**
 * @file MutexException.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __MUTEX_EXCEPTION_HPP__
#define __MUTEX_EXCEPTION_HPP__

#include <exception>


class MutexInitException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "Mutex Init Exception";
	}
};


class MutexDestroyException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "Mutex EBUSY Exception";
	}
};

class MutexLockException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "Mutex Lock Exception";
	}
};

class MutexUnlockException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "Mutex unlock Exception";
	}
};


#endif //__MUTEX_EXCEPTION_HPP__