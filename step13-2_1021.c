#include <stdio.h>
#include <stdlib.h>
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

int pivotIndex(Deque * deq) {
    int middleIndex = deq->size / 2;
    
    return middleIndex;
}

int popIndex(Deque * deq, Data num) {
    int index = 0;
    Node * tmpNode = deq->head;
    while(tmpNode != NULL) {
        if(tmpNode->data == num)
            break;
        tmpNode = tmpNode->next;
        index++;
    }
    return index;
}

/*
void printDeque(Deque * deq) {
    Node * tmpNode = deq->head;
    printf("\nDeque Status : ");
    while(tmpNode != NULL) {
        printf("%d ", tmpNode->data);
        tmpNode = tmpNode->next;
    }
}
*/

int main(void) {
    int deqTotalSize, popCnt, popNum, popNumIndex, pivotNumIndex, i;
    int result = 0;

    scanf("%d %d", &deqTotalSize, &popCnt);
    Deque deq;
    DequeInit(&deq);
    for(i = 1; i <= deqTotalSize; i++)
        DQAddLast(&deq, i);
    
    for(i = 0; i < popCnt; i++) {
        scanf("%d", &popNum);
        pivotNumIndex = pivotIndex(&deq);
        popNumIndex = popIndex(&deq, popNum);
        if(popNumIndex <= pivotNumIndex) {
            while(popNum != (&deq)->head->data) {
                DQAddLast(&deq, (&deq)->head->data);
                DQRemoveFirst(&deq);
                result++;
            }
        }
        else if(popNumIndex > pivotNumIndex) {
            while(popNum != (&deq)->head->data) {
                DQAddFirst(&deq, (&deq)->tail->data);
                DQRemoveLast(&deq);
                result++;
            }
        }
        DQRemoveFirst(&deq); //popNum == (&deq)->head
        //printDeque(&deq);
    }
    printf("%d\n", result);

    return 0;
}