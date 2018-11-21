/**
 * @file Sobject.h
 * @brief subscriber class
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __SOBJECT_H__
#define __SOBJECT_H__


/**
 * @brief Create ,and return struct sub ptr   
 * 
 */
void* Sobj_Create();

/**
 * @brief free 
 * 
 */
void Sobj_Destroy(void* _sobj);

/**
 * @brief set CDR struct fields by char identifier 
 * IMSI                                     -M
 * Outgoing calls duration my operator      -O
 * Incoming calls duration my operator      -I
 * Outgoing calls duration other operator   -o
 * Incoming calls duration other operator   -i
 * Outgoing SMS  my operator                -U
 * Incoming SMS  my operator                -N
 * Outgoing SMS  other operator             -u
 * Incoming SMS  other operator             -n
 * DOWNLOAD                                 -l
 * UPLOAD           -                       -p
 *
 *  return 1 on success -1 else
 */
int Sobj_Set(void* _sobj,char _fieldToUpdate,void* _value);

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
int Sobj_Get(void* _sobj,char _fieldToUpdate,void** _value);

/**
 * @brief Hash function for DS 
 * 
 */
size_t SuHashFunction(const void* _key);

/**
 * @brief EqualityFunction for Hash
 * 
 */
int SuEqualityFunction(void* _firstKey, void* _secondKey);

/**
 * @brief for upsert 
 * 
 */
void* SuUpdateFunction(void *_firstItem, void *_secondItem);


/**for debug */
int Print_Sobj(const void* _key,void* _sobj,void* _contex);

void Destroy_Key(void* _key);





#endif /*__SOBJECT_H__*/