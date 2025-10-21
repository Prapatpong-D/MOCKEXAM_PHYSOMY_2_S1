#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct DataNode{
    char *data;
    struct DataNode *next;
}DataNode;

typedef struct SinglyLinkedList{
    int count;
    DataNode* head;
}SinglyLinkedList;

DataNode *createDataNode(char *data){
    DataNode *newNode = (DataNode*)malloc(sizeof(DataNode));
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}

SinglyLinkedList* createSinglyLinkedList(){
    SinglyLinkedList *list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    list->count = 0;
    list->head = NULL;
    return list;
}

void traverse(SinglyLinkedList *list){
    if (list->head == NULL)
    {
        printf("This is an empty list.");
    }else 
    {
        DataNode *pointer = list->head;
        while (pointer->next != NULL)
        {
            printf("%s",pointer->data);
            if(pointer->next != NULL)
            {
                printf(" -> ");
            }
            pointer = pointer->next;
        }printf("%s",pointer->data);
    }
}

void insert_last(SinglyLinkedList *list, char *data){
    DataNode *pNew = createDataNode(data);
    if (list->count == 0)
    {
        list->head = pNew;
    }else 
    {
        DataNode *pointer = list->head;
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }pointer->next = pNew;
        
    }
    list->count+=1;
}

void insert_front(SinglyLinkedList *list, char *data){
    DataNode *pNew = createDataNode(data);
    if (list->head == NULL)
    {
        list->head = pNew;
    }else
    {
        DataNode *temp = list->head;
        list->head = pNew;
        pNew->next = temp; 
    }
    list->count +=1;
}

void delete(SinglyLinkedList *list, char *data){
    if (list->head == NULL)
    {
        printf("Cannot delete, %s does not exist.\n",data);
        return;
    }

    struct DataNode *current = list->head;
    struct DataNode *previous = NULL;

    while (current != NULL && strcmp(current->data,data) != 0)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Cannot delete, %s does not exist.\n",data);
        return;
    }
    if (previous == NULL)
    {   
        list->head = current->next;
    }else {
        previous->next = current->next;
    }
    free(current->data);
    free(current);
    list->count-=1;
}
/*------------------------------------------------------- This is Main จ้า----------------------------------------------------------------*/
int main()
{
    SinglyLinkedList *list = createSinglyLinkedList();
    int n;
    char condition;
    char data[100]; // Assuming a maximum string length of 99 characters
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %c: %[^\n]s", &condition, data); // Read condition and string data

        if (condition == 'F')
        {
            insert_front(list, data);
        }
        else if (condition == 'L')
        {
            insert_last(list, data);
        }
        else if (condition == 'D')
        {
            delete(list, data);
        }
        else
        {
            printf("Invalid Condition!\n");
        }
    }

    traverse(list);
    // Remember to free allocated memory for each node's data
    DataNode *current = list->head;
    while (current != NULL)
    {
        free(current->data);
        DataNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
    return 0;
}