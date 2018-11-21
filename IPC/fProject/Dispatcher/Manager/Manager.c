/**
 * @file Manager.c
 * @author your name (you@domain.com)
 * @brief manage the input in hash map
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdlib.h>
#include <string.h>
#include "HashMapC.h"
#include "CDR.h"
#include "Sobject.h"
#include "Manager.h"
#define CAPACITY            50
#define NTHREAD             20
#define MAGIC               923758619
#define IS_INVALID(M) ((NULL == (M)) || (M)->m_magic != MAGIC)



typedef struct Ds_t
{
    HashMap*            m_hashMap;
    UpdateFunction      m_UpsertFunc;
}Ds_t;

struct Manager_t
{
    Ds_t            m_subDS;
    size_t          m_magic;
};


static void SobjSetByStr(void *_cdr,void* _sobj,char* _sobjOrder,char* _cdrOrder);
static int CdrtoSobj(void* _cdr, void* _sobj1, void* _sobj2);


/**
 * @brief create DS manager and link with "DS"s  
 * 
 */
Manager_t* Manager_Create()
{
    Manager_t* manager = NULL;

    if(!(manager = calloc(1,sizeof(Manager_t))))
    {
        return NULL;
    }
    if(!((manager->m_subDS.m_hashMap) = HashMap_Create(CAPACITY,NTHREAD,SuHashFunction,SuEqualityFunction)))
    {
        free(manager);
        return NULL;
    }
    manager->m_subDS.m_UpsertFunc = SuUpdateFunction;
    manager->m_magic = MAGIC;

    return manager;
}

/**
 * @brief destroy manager
 * TODO ask if to destroy DS too 
 */
void Manager_Destroy(Manager_t* _manager)
{
    if(IS_INVALID(_manager))
        return;
    _manager->m_magic = 0;
    /** ? */
    HashMap_Destroy(&(_manager->m_subDS.m_hashMap),Destroy_Key,Sobj_Destroy);   
    free(_manager); 
}


/**
 * @brief update instance in DS 
 * 
 */
int Manager_Upsert(Manager_t* _manager,void* _cdr)
{
    void *sobj1 = NULL,*sobj2 = NULL,*cdr = NULL;
    char *_key1,*_key2;
    int delSobj2 = 0;
    
    if(IS_INVALID(_manager))
        return 0;

    if(!(cdr = Cdr_Create()))
        return 0;

    if(!(sobj1 = Sobj_Create()) || !(sobj2 = Sobj_Create()))   
    {
        Cdr_Destroy(cdr);
        Sobj_Destroy(sobj1);
        Sobj_Destroy(sobj2);
        return 0;
    }
    

    memcpy(cdr,_cdr,Cdr_Size());

    if(-1 == (delSobj2 = CdrtoSobj(cdr,sobj1,sobj2)))
    {
        Cdr_Destroy(cdr);
        Sobj_Destroy(sobj1);
        Sobj_Destroy(sobj2);
        return 0;
    }

    if(delSobj2)
    {
        Sobj_Destroy(sobj2);
    }
    else
    {
        Sobj_Get(sobj2,'m',(void**)&_key2);
        HashMap_Upsert(_manager->m_subDS.m_hashMap,_key2,sobj2,SuUpdateFunction);
    }
    Sobj_Get(sobj1,'m',(void**)&_key1);
    HashMap_Upsert(_manager->m_subDS.m_hashMap,_key1,sobj1,SuUpdateFunction);
    
    return 1; 
}




static void SobjSetByStr(void *_cdr,void* _sobj,char* _sobjOrder,char* _cdrOrder)
{
    void *field;
    while(*_sobjOrder)
    {
        Cdr_Get(_cdr,*_cdrOrder,&field);
        Sobj_Set(_sobj,*_sobjOrder,field);
        ++_sobjOrder;
        ++_cdrOrder;
    }
}
static int CdrtoSobj(void* _cdr, void* _sobj1, void* _sobj2)
{
    void *callType, *OpBrn ,*otherOpBrn,*upAmount;
    char sobj1Update,sobj2Update;
    size_t sms = 1;

    
    SobjSetByStr(_cdr,_sobj1,"mM","MI");

    Cdr_Get(_cdr,'T',&callType);
    if(!strcmp(callType,GPRS))
    {
        SobjSetByStr(_cdr,_sobj1,"dp","lp");

        return 1;
    }
    SobjSetByStr(_cdr,_sobj2,"mM","mi");

    Cdr_Get(_cdr,'I',&OpBrn);
    Cdr_Get(_cdr,'i',&otherOpBrn);
    Cdr_Get(_cdr,'d',&upAmount);

    if(!strcmp((char*)otherOpBrn,(char*)OpBrn))
    {
        if(!strcmp(callType,MOC))
        {
            sobj1Update = 'O';
            sobj2Update = 'I';
        }
        else if(!strcmp(callType,MTC))
        {
            sobj1Update = 'I';
            sobj2Update = 'O';
        }
        else if(!strcmp(callType,SMSMO))
        {
            sobj1Update = 'U';
            sobj2Update = 'N';
            memcpy(upAmount,(const void*)&sms,sizeof(void*));
        }
        else if(!strcmp(callType,SMSMT))
        {
            sobj1Update = 'N';
            sobj2Update = 'U';
            memcpy(upAmount,(const void*)&sms,sizeof(void*));
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if(!strcmp(callType,MOC))
        {
            sobj1Update = 'o';
            sobj2Update = 'i';    
        }
        else if(!strcmp(callType,MTC))
        {
            sobj1Update = 'i';
            sobj2Update = 'o';    
        }
        else if(!strcmp(callType,SMSMO))
        {
            sobj1Update = 'u';
            sobj2Update = 'n'; 
            memcpy(upAmount,(const void*)&sms,sizeof(void*));
        }
        else if(!strcmp(callType,SMSMT))
        {
            sobj1Update = 'n';
            sobj2Update = 'u';    
            memcpy(upAmount,(const void*)&sms,sizeof(void*));
        }
        else
        {
            return -1;
        }
    }  
    Sobj_Set(_sobj1,sobj1Update,upAmount);
    Sobj_Set(_sobj2,sobj2Update,upAmount); 
    return 0;
}    
