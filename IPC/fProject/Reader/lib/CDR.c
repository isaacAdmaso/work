/**
 * @file CDR.c
 * @brief contains Cdr struct and multiple  geters 
 * @version 0.1
 * @date 2018-11-18
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h> /**<-delete after debug */
#include <stdlib.h>
#include <string.h>
#include "CDR.h"

#define MAX_ID_SIZE         16          /**<-for alignment + 1 */
#define MAX_NAME_SIZE       64
#define MNC_SIZE            8           /**<-for alignment + 2 */
#define MAX_CALL_TYPE       8           /**<-for alignment + 2 */
#define DATE_SIZE           16          /**<-for alignment + 6  */
#define MAGIC               871569321
#define IS_INVALID(C)       ((NULL == (C)) || ((C)->m_magic != MAGIC))



typedef struct Cdr_t
{
    char    m_OPB[MAX_NAME_SIZE];
    char    m_IMEI[MAX_NAME_SIZE];
    char    m_IMSI[MAX_ID_SIZE];
    char    m_MSISDN[MAX_ID_SIZE];
    char    m_otherMSISDN[MAX_ID_SIZE];
    char    m_MCC[MNC_SIZE];
    char    m_CallType[MAX_CALL_TYPE];
    char    m_DATE[DATE_SIZE];
    char    m_Time[DATE_SIZE];
    size_t  m_Duration;
    size_t  m_DOWNLOAD;
    size_t  m_UPLOAD;
    char    m_otherMCC[MNC_SIZE];
    size_t  m_magic;

}Cdr_t;



/**
 * @brief Create ,and return struct CDR ptr   
 * 
 */
void* Cdr_Create()
{
    Cdr_t* cdr = NULL;

    if(!(cdr = calloc(1,sizeof(Cdr_t))))
    {
        return NULL;
    }
    cdr->m_magic = MAGIC;
    return (void*)cdr;
}

/**
 * @brief free 
 * 
 */
void Cdr_Destroy(void* _cdr)
{
    Cdr_t* cdr = (Cdr_t*)_cdr; 

    if(IS_INVALID(cdr))
    {
        return;
    }
    cdr->m_magic = 0;
    free(cdr);
}

/**
 * @brief set CDR struct fields by char identifier 
 * MCC              -I
 * otherMCC         -i
 * MSISDN           -M
 * otherMSISDN      -m
 * operator brand   -C
 * IMEI             -c
 * DATE             -D
 * CallType         -T
 * Time             -t
 * IMSI             -S
 * Duration         -d
 * DOWNLOAD         -l
 * UPLOAD           -p
 * 
 */
int Cdr_Set(void* _cdr,char _fieldToUpdate,void* _value)
{
    Cdr_t* cdr = (Cdr_t*)_cdr; 
    
    if(IS_INVALID(cdr) || !_value)
    {
        return -1;
    }
    switch (_fieldToUpdate)
    {
        case 'I':
            strcpy(cdr->m_MCC,(char*)_value);
            break;
        case 'i':
            strcpy(cdr->m_otherMCC,(char*)_value);
            break;
        case 'M':
            strcpy(cdr->m_MSISDN,(char*)_value);
            break;
        case 'm':
            strcpy(cdr->m_otherMSISDN,(char*)_value);
            break;
        case 'C':
            strcpy(cdr->m_OPB,(char*)_value);
            break;
        case 'c':
            strcpy(cdr->m_IMEI,(char*)_value);
            break;
        case 'T':
            strcpy(cdr->m_CallType,(char*)_value);
            break;
        case 'D':
            strcpy(cdr->m_DATE,(char*)_value);
            break;
        case 'S':
            strcpy(cdr->m_IMSI,(char*)_value);
            break;
        case 't':
            strcpy(cdr->m_Time,(char*)_value);
            break;
        case 'd':
            cdr->m_Duration = atoi((char*)_value);
            break;
        case 'l':
            cdr->m_DOWNLOAD = atoi((char*)_value);
            break;
        case 'p':
            cdr->m_UPLOAD = atoi((char*)_value);
            break;
    }
    return 1;
}

/**
 * @brief get CDR struct fields by char identifier 
 * IMEI             -I
 * IMSI             -i
 * MSISDN           -M
 * otherMSISDN      -m
 * MCC              -C
 * CallType         -T
 * Time             -t
 * IMSI             -S
 * DATE             -D
 * Duration         -d
 * DOWNLOAD         -l
 * UPLOAD           -p
 * otherMCC         -c
 * 
 */
int Cdr_Get(void* _cdr,char _fieldToUpdate,void** _value)
{
    Cdr_t* cdr = (Cdr_t*)_cdr; 
    
    if(IS_INVALID(cdr) || !_value)
    {
        return -1;
    }
    switch (_fieldToUpdate)
    {
        case 'I':
            *(char**)_value = cdr->m_MCC; /**op id */
            break;
        case 'i':
            *(char**)_value = cdr->m_otherMCC;/**other op id */
            break;
        case 'M':
            *(char**)_value = cdr->m_MSISDN;/**my id  */
            break;
        case 'm':
            *(char**)_value = cdr->m_otherMSISDN;/**other id */
            break;
        case 'C':
            *(char**)_value  = cdr->m_OPB;
            break;
        case 'c':
            *(char**)_value =cdr->m_IMEI;
            break;
        case 'T':
            *(char**)_value = cdr->m_CallType;
            break;
        case 't':
            *(char**)_value = cdr->m_Time;
            break;
        case 'D':
            *(char**)_value = cdr->m_DATE;
            break;
        case 'd':
            *(size_t**)_value = &(cdr->m_Duration);
            break;
        case 'l':
            *(size_t**)_value = &(cdr->m_DOWNLOAD);
            break;
        case 'p':
            *(size_t**)_value = &(cdr->m_UPLOAD);
            break;
    }
    return 1;
}


/**for debug */
void Print_Cdr(void* _cdr)
{
    Cdr_t* cdr = (Cdr_t*)_cdr;

    printf("\nT %s\n",cdr->m_CallType);
    printf("\nI %s\n",cdr->m_MCC);
    printf("\ni %s\n",cdr->m_otherMCC);
    printf("\nM %s\n",cdr->m_MSISDN);
    printf("\nm %s\n",cdr->m_otherMSISDN);
    printf("\nC %s\n",cdr->m_OPB);
    printf("\nc %s\n",cdr->m_IMEI);
    printf("\nD %s\n",cdr->m_DATE);
    printf("\nd %ld\n",cdr->m_Duration);
    printf("\nl %ld\n",cdr->m_DOWNLOAD);
    printf("\np %ld\n",cdr->m_UPLOAD);
}

size_t Cdr_Size()
{
    return sizeof(Cdr_t);
}
