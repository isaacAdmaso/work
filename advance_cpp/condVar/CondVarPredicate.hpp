/**
 * @file CondVarPredicate.hpp
 * @author your name (you@domain.com)
 * @brief predicate for pthread conditional variable
 * @version 0.1
 * @date 2019-02-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __CONDVAR_PREDICATE_HPP__
#define __CONDVAR_PREDICATE_HPP__

template <typename Predicate>
void CondVar::Wait(Predicate p)
{
	while (!p())
	{
		if (pthread_cond_wait(&m_condVar, m_mutex.Get()))
		{
			throw CondVarWaitException();
		}
	}
}

#endif  //__CONDVAR_PREDICATE_HPP__