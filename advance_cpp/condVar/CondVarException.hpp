/**
 * @file CondVarException.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __CONDV_EXCEPTION_HPP__
#define __CONDV_EXCEPTION_HPP__

#include <exception>


class CondVarInitException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar Init Exception";
	}
};


class CondVarDestroyException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar EBUSY Exception";
	}
};


class CondVarWaitException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar Wait Exception";
	}
};


class CondVarNotifyOneException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar Notif One Exception";
	}
};

class CondVarNotifyAllException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar Notify All Exception";
	}
};


#endif  //__CONDV_EXCEPTION_HPP__