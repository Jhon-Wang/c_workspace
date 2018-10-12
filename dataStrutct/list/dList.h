#ifndef _DLIST_H_
#define _DLIST_H_

typedef struct dNode{
    int data;
    struct dNode *pre;
    struct dNode *next;
} DNode;

typedef struct dList{
    int size;
    DNode *head;
} DList;


#endif