#ifndef _LIST_H_
#define _LIST_H_

typedef struct node{
    
    int data;
    struct node *next;
      
} Node;

typedef struct list{
    int size;
    struct node *head;
} List;

#endif