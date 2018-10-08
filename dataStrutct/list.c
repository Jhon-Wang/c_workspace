#include "list.h"
#include <stdio.h>
#include <malloc.h>

//初始化

List initList(){
    List *list = (List *)malloc(sizeof(List));
    Node *head = (Node *)malloc(sizeof(Node));
    
    head->next = NULL;
    head->data = 0;
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
    newNode->data = value;
    newNode->next = NULL;

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
        deleteNode(list,0);
    }
}


int destoryList(List *list){
    Node *head = list->head;
    Node *p ;
    if(head==NULL){
        return 0;
    }
    while(head){
        p = head->next;
        free(head);
        head = p;
    }
    list->head = NULL;
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

int showValues(List *list){
    if(list->head == NULL){
        printf("List Has Destory!\n");
        return -1;
    }

    if(list->size == 0 ){
        printf("is Empty!\n");
    }
    Node *p = list->head;
    while(p->next != NULL){
        p = p->next;
        printf("%d\n",p->data);
    }
    printf("OUTPUT END!\n");
}

int main(int argc, char const *argv[])
{

    List list = initList();
    addNode(&list,10);
    addNode(&list,20);
    insertNode(&list,0,30);
    deleteNode(&list,0);
    clearList(&list);
    showValues(&list);
    destoryList(&list);
    showValues(&list);
    getchar();
    return 0;
}





