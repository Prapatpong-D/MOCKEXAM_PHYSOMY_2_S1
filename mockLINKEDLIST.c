#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode{
    int data;
    struct DataNode* next;
} DataNode;

typedef struct SinglyLinkedList {
  unsigned int count;
  DataNode* head;
} SinglyLinkedList; 

DataNode *createDataNode(int data);
SinglyLinkedList *createSinglyLinkedList();

DataNode* createDataNode(int data) {
  DataNode* newNode = (DataNode*)malloc(sizeof(DataNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    list->count = 0;
    list->head = NULL;
    return list;
}

void traverse(SinglyLinkedList* list){
    if (list->count == 0){
        printf("This is emp");
        return;
    }else{
        DataNode* pointer = list->head;
        while (pointer != NULL){
            printf("%d ",pointer->data);
            pointer = pointer->next;
        }
    }
}

void insert_last(SinglyLinkedList* list, int data){
    DataNode* pNew = createDataNode(data);
    if (list->count == 0){
        list->head = pNew;
    } else {
    DataNode* pointer = list->head;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    pointer->next = pNew;
    }
    list->count+=1;
}

void insert_index(SinglyLinkedList* list,int index,int data){
    DataNode* pNew = createDataNode(data);
    if (list->count = 0 || index <= 0){
        pNew->next = list->head;
        list->head = pNew;
        list->count +=1;
    }else {
        DataNode* pointer = list->head;
        int i =0;
    while (pointer->next != NULL && i < index-1){
        pointer = pointer->next;
        i+=1;
    }
    pNew->next = pointer->next;
    pointer->next = pNew;
    list->count+=1;
    }
}

int main(){
    int nn;
    if (scanf("%d",&nn) != 1) return 0;
    SinglyLinkedList* list = createSinglyLinkedList();
    for (int i = 0; i < nn; i++) {
        int v;
        scanf("%d", &v);
        insert_last(list, v);
    }
    int pos, data;
    scanf("%d", &pos);
    scanf("%d", &data);
    insert_index(list, pos, data);
    traverse(list);
    return 0;
}