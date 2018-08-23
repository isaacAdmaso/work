struct Node
{
    int     m_data;
    Node*   m_left;
    Node*   m_right;
};

struct Tree
{
    Node*   m_root;
};

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
