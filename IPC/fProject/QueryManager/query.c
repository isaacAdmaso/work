/**
 * @file query.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-11-23
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include "query.h"
#include "Manager.h"

#define MAGIC               19876314321
#define IS_INVALID(Q)       ((NULL == (Q)) || ((Q)->m_magic != MAGIC))




struct Query_t 
{
    Manager_t* m_Manager;
    size_t     m_magic;
};

/**
 * @brief create query manager and attach  Ds manager 
 * 
 */
Query_t* Query_Create(void* _manager)
{
    Query_t* query = NULL;
    Manager_t* manager = (Manager_t*) _manager;


    if(!manager)
    {
        return NULL;
    }
    if(!(query = calloc(1,sizeof(Query_t))))
    {
        return NULL;
    }
    query->m_Manager = manager;
    query->m_magic = MAGIC;
    return query;
}
/**
 * @brief free allocated memory
 * 
 */
void* Query_Destroy(Query_t* _query)
{
    Manager_t* rtManager;

    if(IS_INVALID(_query))
    {
        return _query;
    }
    
    _query->m_magic = 0;
    rtManager = _query->m_Manager;
    free(_query);
    return rtManager;
}

static void GeTime(char* _timeStr);


/**
 * @brief get subscriber
 * 
 */
int Query_Get_Subscriber(Query_t* _query,char* _msisdn,char* fileName)
{
    FILE *outFp;
    char buf[64];


    if(IS_INVALID(_query))
    {
        return 0;
    }
    if(!(outFp = fopen(fileName,"w")))
    {
        return 0;
    }
    GeTime(buf);
    fprintf(outFp,"%s",buf);

    return Manager_Get_One(_query->m_Manager,_msisdn,outFp);
}

/**
 * @brief  get all
 * 
 */
int Query_GetAll_Subscriber(Query_t* _query,char* fileName)
{
    FILE *outFp;
    char buf[64];

    if(IS_INVALID(_query))
    {
        return 0;
    }
    if(!(outFp = fopen(fileName,"w")))
    {
        return 0;
    }
    GeTime(buf);
    fprintf(outFp,"%s",buf);
    return Manager_Get_Group(_query->m_Manager,outFp);
}



void GeTime(char* _timeStr)
{
    struct timeval tv;
    time_t nowtime;
    struct tm *nowtm;
    char buf[64];

    gettimeofday(&tv, NULL);
    nowtime = tv.tv_sec;
    nowtm = localtime(&nowtime);
    strftime(buf, sizeof buf, "%Y-%m-%d \n%H:%M:%S\n", nowtm);
    sprintf(_timeStr, "%s", buf);
}