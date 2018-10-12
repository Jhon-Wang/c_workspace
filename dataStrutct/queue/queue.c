#include "queue.h"
#include <malloc.h>
#include <stdio.h>

Queue initQueue(){
    Queue *queue = (Queue *) malloc (sizeof(Queue));
    Node *head = (Node *) malloc(sizeof(Node));
    head->data = 0 ; 
    head->next = NULL;

    queue->head = head;
    queue->head = head;
    queue->size = 0;
    return *queue;
}

/**
 * 添加节点
 * 数据增长
 */ 
int enQueue(Queue *queue,int value){
    Node *head = queue->head;
    Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }

    Node *newNode = (Node *) malloc (sizeof(Node));
    newNode->next = NULL;
    newNode->data = value;
    p->next =  newNode;
    p = NULL;
    queue->tail = newNode;
    queue->size ++;
    
}

int deQueue(Queue *queue){
    if(queue->size == 0){
        printf("ERROR");
        return -1;
    }
    Node *head = queue->head;
    Node *p = head->next;
    if(p->next != NULL){
        head->next = p->next;
    }
    int value = p->data;
    free(p);
    p = NULL;
    head = NULL;

    queue->size--;
    return value;

}

int main(){
    Queue queue = initQueue();
    enQueue(&queue,10);
    enQueue(&queue,20);
    enQueue(&queue,30);

    while(queue.size>0){
        printf("%d\n",deQueue(&queue));
    }

    getchar();

}