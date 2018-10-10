#ifndef _LIST_H_
#define _LIST_H_
#include "node.h"

typedef struct list{
    int size;
    struct node *head;
} List;

#endif