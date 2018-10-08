#ifndef _DLIST_H_
#define _DLIST_H_

typedef struct dNode{
    int data;
    struct DNode *pre;
    struct DNode *next;
} DNode;

typedef struct dList{
    int size;
    DNode *head;
} DList;


#endif