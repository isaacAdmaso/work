#ifndef __BST__
#define __BST__
#include "ADTDefs.h"
#include<stddef.h>

typedef struct Tree Tree;

typedef enum
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
} TreeTraverse;

Tree*   TreeCreate();
void    TreeDestroy(Tree* _tree);
ADTErr  TreeInsert(Tree* _tree, int _data);
int     TreeIsDataFound(const Tree* _tree, int _data);

void    TreePrint(const Tree* _tree, TreeTraverse _traverseMode);

#endif

