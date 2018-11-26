/**
 * @file query.h
 * @brief Query Manager
 * @version 0.1
 * @date 2018-11-24
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __QUERY_H__
#define __QUERY_H__

typedef struct Query_t Query_t;

/**
 * @brief create query manager and attach  Ds manager 
 * 
 */
Query_t* Query_Create(void* _manager);


/**
 * @brief free allocated memory
 * 
 */
void* Query_Destroy(Query_t* _query);


/**
 * @brief 
 * 
 */
int Query_Get_Subscriber(Query_t* _query,char* _msisdn,char* fileName);


/**
 * @brief  get all
 * 
 */
int Query_GetAll_Subscriber(Query_t* _query,char* fileName);





#endif /*__QUERY_H__*/