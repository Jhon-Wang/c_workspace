#include "list.h"
#include <malloc.h>

//初始化

List initList(){
    List *list = (List *)malloc(sizeof(List));
    Node *head = (Node *)malloc(sizeof(Node));
    
    list->head = head;
    list->size = 0;

    return *list;
}

/**
 * 在尾部添加节点
 */ 
int addNode(List *list,int value){
    Node *head = list->head;
    Node *p = head;

    while(p->next != NULL){
        p = p->next;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));

    p->next = newNode;
    list->size ++;
}

/**
 * 插入节点
 */ 
int insertNode(List *list,int index,int value){
    Node *p = list->head;
    for(int i = 0 ; i < index-1;i++){
        p = p->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = p->next;
    p->next = newNode;
    list->size ++;
}

/**
 * 删除节点
 */ 
int deleteNode(List *list,int index){
    Node *p = list->head;
    for(int i = 0 ; i < index-1;i++){
        p = p->next;
    }
    Node *current = p->next;
    p->next = current->next;
    list->size --;
    int value = current->data;
    free(current);
    return value;
}

/**
 * 清除列表
 */ 
int clearList(List *list){
    while(list->size > 0){
        deleteNode(&list,0);
    }
}


int destoryList(List *list){
    clearList(&list);
    free(list->head);
}

int findValueIndex(List *list,int value){
    int count = 0 ;
    Node *p = list->head;
    if(list->size == 0){
        return -1;
    }
    
    while(p->next != NULL){
        if(p->data == value){
            return count;
        }
        p = p->next;
        count ++;
    }
}

int updateValue(List *list,int index,int value){
    Node *p = list->head;
    for(int i = 0 ; i < index;i++){
        p = p->next;
    }
    p->data = value;
}




