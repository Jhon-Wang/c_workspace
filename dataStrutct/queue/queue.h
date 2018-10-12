#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "../node.h"

typedef struct queue{
    Node *head;
    Node *tail;
    int size;
} Queue;

#endif // !_queue_H_
