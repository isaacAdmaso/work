/**
 * @file Sobject.c
 * @brief contains  Sobj struct and multiple  geters 
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdlib.h>
#include <stdio.h> /**<-delete after debug */
#include <string.h>
#include "Sobject.h"

#define MAGIC               8123564234
#define IS_INVALID(O)       ((NULL == (O)) || ((O)->m_magic != MAGIC))
#define MAX_ID_SIZE         16          /**<-for alignment + 1 */
#define MAX_OPID_SIZE       64
#define ID                  6

typedef struct OpUse_t
{
    size_t m_InDuration;
    size_t m_OutDuration;
    size_t m_InSMS;
    size_t m_OutSMS;
}OpUse_t;

typedef struct Sobj_t
{
    char        m_OpId[MAX_OPID_SIZE];
    OpUse_t     m_MyOp;
    OpUse_t     m_OtherOp;
    char        m_MSISDN[MAX_ID_SIZE];
    size_t      m_Download;
    size_t      m_Upload;
    size_t      m_magic;
}Sobj_t;

/**
 * @brief Create ,and return struct subscriber ptr   
 * 
 */
void* Sobj_Create()
{
    Sobj_t* subscriber = NULL;

    if(!(subscriber = calloc(1,sizeof(Sobj_t))))
    {
        return NULL;
    }
    subscriber->m_magic = MAGIC;
    return (void*)subscriber;
}

/**
 * @brief free 
 * 
 */
void Sobj_Destroy(void* _sobj)
{
    Sobj_t* subscriber = (Sobj_t*)_sobj; 

    if(IS_INVALID(subscriber))
    {
        return;
    }
    subscriber->m_magic = 0;
    free(subscriber);
}

/**
 * @brief set subscriber struct fields by char identifier 
 * IMSI                                     -M
 * MSISDN                                   -m
 * Outgoing calls duration my operator      -O
 * Incoming calls duration my operator      -I
 * Outgoing calls duration other operator   -o
 * Incoming calls duration other operator   -i
 * Outgoing SMS  my operator                -U
 * Incoming SMS  my operator                -N
 * Outgoing SMS  other operator             -u
 * Incoming SMS  other operator             -n
 * DOWNLOAD                                 -d
 * UPLOAD           -                       -p
 *  return 1 on success -1 else
 */
int Sobj_Set(void* _sobj,char _fieldToUpdate,void* _value)
{
    Sobj_t* subscriber = (Sobj_t*)_sobj; 
    
    if(IS_INVALID(subscriber) || !_value)
    {
        return -1;
    }
    switch (_fieldToUpdate)
    {
        case 'M':
            strcpy(subscriber->m_OpId,(char*)_value);/**op id */
            break;
        case 'm':
            strcpy(subscriber->m_MSISDN,(char*)_value);/**my id  */
            break;
        case 'O':
            subscriber->m_MyOp.m_OutDuration += *(size_t*)_value;
            break;
        case 'I':
            subscriber->m_MyOp.m_InDuration +=  *(size_t*)_value;
            break;
        case 'o':
            subscriber->m_OtherOp.m_OutDuration += *(size_t*)_value;
            break;
        case 'i':
            subscriber->m_OtherOp.m_InDuration += *(size_t*)_value;
            break;
        case 'U':
            subscriber->m_MyOp.m_OutSMS += *(size_t*)_value;
            break;
        case 'N':
            subscriber->m_MyOp.m_InSMS += *(size_t*)_value;
            break;
        case 'u':
            subscriber->m_OtherOp.m_OutSMS += *(size_t*)_value;
            break;
        case 'n':
            subscriber->m_OtherOp.m_InSMS += *(size_t*)_value;
            break;
        case 'd':
            subscriber->m_Download += *(size_t*)_value;
            break;
        case 'p':
            subscriber->m_Upload += *(size_t*)_value;
            break;
    }
    return 1;
}
/**
 * @brief get Sobj struct fields by char identifier 
 * IMSI                                              -M
 * Outgoing calls duration my operator               -O
 * Incoming calls duration my operator               -I
 * Outgoing calls duration other operator            -o
 * Incoming calls duration other operator            -i
 * Outgoing SMS  my operator                         -U
 * Incoming SMS  my operator                         -N
 * Outgoing SMS  other operator                      -u
 * Incoming SMS  other operator                      -n
 * DOWNLOAD                                          -l
 * UPLOAD           -                                -p
 * return 1 on success -1 else
 */
int Sobj_Get(void* _sobj,char _fieldToUpdate,void** _value)
{
    Sobj_t* subscriber = (Sobj_t*)_sobj; 
    
    if(IS_INVALID(subscriber) || !_value)
    {
        return -1;
    }
    switch (_fieldToUpdate)
    {
        case 'M':
            *(char**)_value = subscriber->m_OpId;/**op id */
            break;
        case 'm':
            *(char**)_value = subscriber->m_MSISDN;/**my id  */
            break;
        case 'O':
            *(size_t*)_value = subscriber->m_MyOp.m_OutDuration;
            break;
        case 'I':
            *(size_t*)_value = subscriber->m_MyOp.m_InDuration;
            break;
        case 'o':
            *(size_t*)_value = subscriber->m_OtherOp.m_OutDuration;
            break;
        case 'i':
            *(size_t*)_value = subscriber->m_OtherOp.m_InDuration;
            break;
        case 'U':
            *(size_t*)_value = subscriber->m_MyOp.m_OutSMS;
            break;
        case 'N':
            *(size_t*)_value = subscriber->m_MyOp.m_InSMS;
            break;
        case 'u':
            *(size_t*)_value = subscriber->m_OtherOp.m_OutSMS;
            break;
        case 'n':
            *(size_t*)_value = subscriber->m_OtherOp.m_InSMS;
            break;
        case 'd':
            *(size_t*)_value = subscriber->m_Download;
            break;
        case 'p':
            *(size_t*)_value = subscriber->m_Upload;
            break;
    }
    return 1;
}



/**
 * @brief Hash function for DS 
 * 
 */
size_t SuHashFunction(const void* _key)
{
    char key[ID];
    size_t idx = 0;

    strncpy(key,(char*)_key,ID);
    key[ID-1] = '\0';
    idx = atoi(_key);
    
    return idx;
}

/**
 * @brief EqualityFunction for Hash
 * 
 */
int SuEqualityFunction(void* _firstKey, void* _secondKey)
{
    return (strcmp((const char*)_firstKey,(const char*)_secondKey)) ? 0:1;
}

/**
 * @brief for upsert 
 * 
 */
void* SuUpdateFunction(void *_firstItem, void *_secondItem)
{
    Sobj_t *sub1 = (Sobj_t*)_firstItem,*sub2 = (Sobj_t*)_secondItem; 
    
    if(IS_INVALID(sub1) || IS_INVALID(sub2))
    {
        return NULL;
    }    
    sub1->m_MyOp.m_OutDuration      +=  sub2->m_MyOp.m_OutDuration;  
    sub1->m_MyOp.m_InDuration       +=  sub2->m_MyOp.m_InDuration;  
    sub1->m_MyOp.m_OutSMS           +=  sub2->m_MyOp.m_OutSMS;       
    sub1->m_MyOp.m_InSMS            +=  sub2->m_MyOp.m_InSMS;       
    sub1->m_OtherOp.m_OutDuration   +=  sub2->m_OtherOp.m_OutDuration;
    sub1->m_OtherOp.m_InDuration    +=  sub2->m_OtherOp.m_InDuration;
    sub1->m_OtherOp.m_OutSMS        +=  sub2->m_OtherOp.m_OutSMS;
    sub1->m_OtherOp.m_InSMS         +=  sub2->m_OtherOp.m_InSMS;    
    sub1->m_Download                +=  sub2->m_Download;            
    sub1->m_Upload                  +=  sub2->m_Upload;

    return (void*)_firstItem;
}

/**for debug */
void Print_Sobj(void* _sobj)
{
    Sobj_t* subscriber = (Sobj_t*)_sobj;

    printf("\n%s\n",  subscriber->m_OpId);
    printf("\n%ld\n", subscriber->m_MyOp.m_OutDuration);
    printf("\n%ld\n", subscriber->m_MyOp.m_InDuration);
    printf("\n%ld\n", subscriber->m_MyOp.m_OutSMS);
    printf("\n%ld\n", subscriber->m_MyOp.m_InSMS);
    printf("\n%ld\n", subscriber->m_OtherOp.m_OutDuration);
    printf("\n%ld\n", subscriber->m_OtherOp.m_InDuration);
    printf("\n%ld\n", subscriber->m_OtherOp.m_OutSMS);
    printf("\n%ld\n", subscriber->m_OtherOp.m_InSMS);
    printf("\n%ld\n", subscriber->m_Download);
    printf("\n%ld\n", subscriber->m_Upload);
}

void Destroy_Key(void* _key)
{
    return;
}
