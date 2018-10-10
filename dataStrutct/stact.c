#include <malloc.h>
#include "node.h"
#include "stact.h"


Stact initStact(){
    Stact *stact = (Stact *)malloc(sizeof(Stact));
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;

    stact->head = head;
    stact->size = 0;
    return *stact;
}

/**
 * 出栈操作
 */ 
int pop(Stact *stact){
    if(stact->size == 0){
        printf("为空");
        return -1;
    }

    Node *p = stact->head;
    p = p->next;
    int value = p->data;
    stact->head = p->next;
    free(p);
    p = NULL;
    stact->size --;

    return value;
}

/**
 * 入栈操作
 */ 
int push(Stact *stact,int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(stact->head->next != NULL){
        newNode->next = stact->head->next;
    }
    stact->head->next = newNode;

    stact->size ++;
    
}

int main(){



}

