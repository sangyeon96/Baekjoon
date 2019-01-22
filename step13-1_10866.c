#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAXORDERSIZE 11

typedef int Data;

typedef struct _node {
    Data data;
    struct _node * next;
    struct _node * prev;
}Node;

typedef struct _deque {
    Node * head;
    Node * tail;
    int size;
}Deque;

void DequeInit(Deque * deq) {
    deq->head = NULL;
    deq->tail = NULL;
    deq->size = 0;
}

int DQIsEmpty(Deque * deq) {
    if(deq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque * deq, Data data) { //머리에 data 저장
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = deq->head;

    if(DQIsEmpty(deq))
        deq->tail = newNode;
    else
        deq->head->prev = newNode;

    newNode->prev = NULL;
    deq->head = newNode;
    deq->size++;
}

void DQAddLast(Deque * deq, Data data) { //꼬리에 data 저장
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = deq->tail;

    if(DQIsEmpty(deq))
        deq->head = newNode;
    else
        deq->tail->next = newNode;

    newNode->next = NULL;
    deq->tail = newNode;
    deq->size++;
}

Data DQRemoveFirst(Deque * deq) {
    Node * rnode = deq->head;
    Data rdata;
    if(DQIsEmpty(deq))
        return -1;

    rdata = deq->head->data;

    deq->head = deq->head->next;
    free(rnode);

    if(deq->head == NULL)
        deq->tail = NULL;
    else
        deq->head->prev = NULL;
    
    deq->size--;
    return rdata;
}

Data DQRemoveLast(Deque * deq) {
    Node * rnode = deq->tail;
    Data rdata;
    if(DQIsEmpty(deq))
        return -1;

    rdata = deq->tail->data;

    deq->tail = deq->tail->prev;
    free(rnode);

    if(deq->tail == NULL)
        deq->head = NULL;
    else
        deq->tail->next = NULL;

    deq->size--;
    return rdata;
}

Data DQGetFirst(Deque * deq) {
    if(DQIsEmpty(deq))
        return -1;
    else
        return deq->head->data;
}

Data DQGetLast(Deque * deq) {
    if(DQIsEmpty(deq))
        return -1;
    else
        return deq->tail->data;
}

Data DQGetSize(Deque * deq) {
    return deq->size;
}

int main(void) {
    int orderCnt, data, i; 
    char order[MAXORDERSIZE];
    scanf("%d", &orderCnt);

    Deque deq;
    DequeInit(&deq);
    for(i = 0; i < orderCnt; i++) {
		scanf("%s", order);
        if(order[5] == 'f') { //push_front
            scanf("%d", &data);
            DQAddFirst(&deq, data);
        }
        else if(order[5] == 'b') { //push_back
            scanf("%d", &data);
            DQAddLast(&deq, data);
        }
        else if(order[4] == 'f') //pop_front
            printf("%d\n", DQRemoveFirst(&deq));
        else if(order[4] == 'b') //pop_back
            printf("%d\n", DQRemoveLast(&deq));
        else if(order[0] == 's') //size
            printf("%d\n", DQGetSize(&deq));
        else if(order[0] == 'e') //empty
            printf("%d\n", DQIsEmpty(&deq));
        else if(order[0] == 'f') //front
            printf("%d\n", DQGetFirst(&deq));
        else if(order[0] == 'b')
            printf("%d\n", DQGetLast(&deq));
        else {
            printf("Wrong Type of Order\n");
            exit(-1);
        }
        memset(&order, 0, sizeof(order));
    }

    return 0;
}