#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define P_MAXSIZE 100000
#define TRUE 1
#define FALSE 0

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

Data DQGetSize(Deque * deq) {
    return deq->size;
}

void printDeque(Deque * deq) {
    Node * tmpNode = deq->head;
    printf("[");
    while(tmpNode != NULL) {
        if(tmpNode == deq->tail)
            printf("%d", tmpNode->data);
        else
            printf("%d,", tmpNode->data);
        tmpNode = tmpNode->next;
    }
    printf("]\n");
}

void printReverseDeque(Deque * deq) {
    Node * tmpNode = deq->tail;
    printf("[");
    while(tmpNode != NULL) {
        if(tmpNode == deq->head)
            printf("%d", tmpNode->data);
        else
            printf("%d,", tmpNode->data);
        tmpNode = tmpNode->prev;
    }
    printf("]\n");
}

int main(void) {
    int testcaseCount, deqSize, deqData, p_length;
    int i, j;
    char p[P_MAXSIZE];
    char ch;
    int errorFlag = 0;
    int RCount = 0;

    scanf("%d", &testcaseCount);
    for(i = 0; i < testcaseCount; i++) {
        scanf("%s", p);

        Deque deq;
        DequeInit(&deq);

        scanf("%d", &deqSize);
        getchar(); //remove enter
        getchar(); //remove [

        for(j = 0; j < deqSize; j++) {
            scanf("%d", &deqData);
            DQAddLast(&deq, deqData);
            if(j != deqSize - 1) {
                getchar(); //remove ,
            }
        }
        getchar(); //remove ]

        p_length = strlen(p);
        for(j = 0; j < p_length; j++) {
            ch = p[j];
            if(ch == 'R')
                RCount++;
            else if(ch == 'D') {
                if(DQIsEmpty(&deq))
                    errorFlag = 1;
                else {
                    if(RCount % 2 != 0)
                        DQRemoveLast(&deq);
                    else //RCount % 2 == 0
                        DQRemoveFirst(&deq);
                }
            }
            else {
                printf("Wrong Type of P\n");
                exit(-1);
            }
        }

        if(errorFlag)
            printf("error\n");
        else if(RCount % 2 != 0)
            printReverseDeque(&deq);
        else
            printDeque(&deq);

        errorFlag = 0;
        RCount = 0;
    }
    return 0;
}