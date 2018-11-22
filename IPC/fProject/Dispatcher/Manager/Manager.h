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

#define MAX_OP_BRAND_SIZE   64

typedef struct Manager_t Manager_t;


/**
 * @brief create DS manager and link with "DS"s  
 * 
 */
Manager_t* Manager_Create();


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


/**for debug */
void Manager_Print(Manager_t* _manager);


#endif /*__MANAGER_H__*/