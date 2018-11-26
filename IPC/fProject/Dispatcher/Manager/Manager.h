#ifndef __MANAGER_H__
#define __MANAGER_H__
/**
 * @file Manager.h
 * @brief manage DS
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h>
#include "HashMapC.h"



typedef struct Manager_t Manager_t;


/**
 * @brief create DS manager and link with "DS"s  
 * 
 */
Manager_t* Manager_Create(size_t _capacity,size_t _nThreads);


/**
 * @brief destroy manager
 * TODO ask if to destroy DS too 
 */
void Manager_Destroy(Manager_t* _manager);


/**
 * @brief update instance in DS 
 * 
 */
int Manager_Upsert(Manager_t* _manager,void* _cdr);

/**
 * @brief for Query 
 * 
 */
int Manager_Get_One(Manager_t* _manager,const void* _key, FILE* _line);

/**
 * @brief for Query
 * 
 */
int Manager_Get_Group(Manager_t* _manager,FILE* _outFile);


/**for debug */
void Manager_Print(Manager_t* _manager);


#endif /*__MANAGER_H__*/