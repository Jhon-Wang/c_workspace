#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
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
        printf("empty\n");
        return -1;
    }
    Node *head = stact->head;
    Node *p = head;
    p = p->next;
    int value = p->data;
    head->next = p->next;
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

bool isEmpty(Stact *stact){
    if(stact->size == 0)
        return true;
    return false;
}

int main(){
    Stact stact = initStact();
    push(&stact,10);
    push(&stact,20);
    push(&stact,30);

    while(stact.size >0){
        int value = pop(&stact);
        printf("%d\n",value);
    }

    getchar();


}

