#ifndef _D_NODE_
#define _D_NODE_

typedef struct dNode{
    int data;
    struct dNode *pre;
    struct dNode *next;
} DNode;

#endif // !_D_NODE_