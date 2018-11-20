/**
 * @file CDR.h
 * @brief  define structer for Reader and Aggregator classes 
 * @version 0.1
 * @date 2018-11-18
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CDR_H__
#define __CDR_H__
#include <stddef.h>



/**
 * @brief Create ,and return struct CDR ptr   
 * 
 */
void* Cdr_Create();

/**
 * @brief free 
 * 
 */
void Cdr_Destroy(void* _cdr);

/**
 * @brief set CDR struct fields by char identifier 
 * IMEI             -I
 * IMSI             -i
 * MSISDN           -M
 * otherMSISDN      -m
 * MCC              -C
 * CallType         -T
 * DATE             -D
 * Duration         -d
 * DOWNLOAD         -l
 * UPLOAD           -p
 * otherMCC         -c
 * 
 * return 1 on success -1 else
 */
int Cdr_Set(void* _cdr,char _fieldToUpdate,void* _value);

/**
 * @brief get CDR struct fields by char identifier 
 * IMEI             -I
 * IMSI             -i
 * MSISDN           -M
 * otherMSISDN      -m
 * MCC              -C
 * CallType         -T
 * DATE             -D
 * Duration         -d
 * DOWNLOAD         -l
 * UPLOAD           -p
 * otherMCC         -c
 * 
 * return 1 on success -1 else
 */
int Cdr_Get(void* _cdr,char _fieldToUpdate,void** _value);

/**for debug */
void Print_Cdr(void* _cdr);

size_t Cdr_Size();


#endif /*__CDR_H__*/


