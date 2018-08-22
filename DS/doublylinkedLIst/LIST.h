#ifndef __LIST_H__
#define __LIST_H__
#include "ADTDefs.h"
#include<stddef.h>

typedef struct List_t List_t;

List_t* ListCreate();
void   ListDestroy(List_t *_list);

ADTErr ListPushHead(List_t *_list, int  _item);
ADTErr ListPushTail(List_t *_list, int  _item);
ADTErr ListPopHead(List_t *_list, int *_item);
ADTErr ListPopTail(List_t *_list, int *_item);
size_t ListCountItems(List_t *_list);
int    ListIsEmpty(const List_t *_list);

void   ListPrint(const List_t *_list);


#endif

