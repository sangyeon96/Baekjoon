#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_LEN 1000
#define QUEUE_LEN 1000

typedef int Data;

typedef struct _arrayStack {
    Data stackArr[STACK_LEN];
    int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * s) {
    s->topIndex = -1;
}

int SIsEmpty(Stack * s) {
    if(s->topIndex == -1)
        return 1;
    else
        return 0;
}

void SPush(Stack * s, Data data) {
    s->stackArr[++s->topIndex] = data;
}

Data SPop(Stack * s) {
    if(SIsEmpty(s)) {
        printf("Stack Memory Error!");
        exit(-1);
    }
    return s->stackArr[s->topIndex--];
}

typedef struct _queue {
    int frontIndex;
    int rearIndex;
    Data queArr[QUEUE_LEN];
}Queue;

void QueueInit(Queue * q) {
    q->frontIndex = 0;
    q->rearIndex = 0;
}

int QIsEmpty(Queue * q) {
    if(q->frontIndex == q->rearIndex)
        return 1;
    else
        return 0;
}

void Enqueue(Queue * q, Data data) {
    q->queArr[q->rearIndex++] = data;
}

Data Dequeue(Queue * q) {
    if(QIsEmpty(q)) {
        printf("Queue Memory Error!");
        exit(-1);
    }
    return q->queArr[q->frontIndex++];
}

typedef int LData;

typedef struct _node {
    LData data;
    struct _node * next;
}Node;

typedef struct _linkedList {
    Node * head;
    Node * cur;
    Node * before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List * list) {
    list->head = (Node *)malloc(sizeof(Node));
    list->head->next = NULL;
    list->comp = NULL;
    list->numOfData = 0;
}

void LInsert(List * list, LData data) {
    if(list->comp == NULL) {
        Node * newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = list->head->next;
        list->head->next = newNode;

        (list->numOfData)++;
    }
    else {
        Node * newNode = (Node *)malloc(sizeof(Node));
        Node * pred = list->head;
        newNode->data = data;

        while(pred->next != NULL && list->comp(data, pred->next->data) != 0)
            pred = pred->next;
        
        newNode->next = pred->next;
        pred->next = newNode;

        (list->numOfData)++;
    }
}

int LFirst(List * list, LData * data) {
    if(list->head->next == NULL)
        return 0;
    
    list->before = list->head;
    list->cur = list->head->next;

    *data = list->cur->data;
    return 1;
}

int LNext(List * list, LData * data) {
    if(list->cur->next == NULL)
        return 0;
    
    list->before = list->cur;
    list->cur = list->cur->next;

    *data = list->cur->data;
    return 1;
}

typedef struct _graph {
    int vertexCount;
    int edgeCount;
    List * adjList; //Edge Info
    int * visitInfo;
}Graph;

void SetSortRule(List * list, int (*comp)(LData d1, LData d2)) {
    list->comp = comp;
}

int WhoIsPrecede(int data1, int data2) {
    if(data1 < data2)
        return 0;
    else
        return 1;
}

void GraphInit(Graph * g, int vertexCount) {
    int i;

    g->adjList = (List *)malloc(sizeof(List) * (vertexCount + 1));
    g->vertexCount = vertexCount + 1;
    g->edgeCount = 0;
    g->visitInfo = (int *)malloc(sizeof(int) * (g->vertexCount + 1));
    memset(g->visitInfo, 0, sizeof(int) * (g->vertexCount + 1));

    //initialize adjList
    for(i = 0; i <= vertexCount; i++) {
        ListInit(&(g->adjList[i]));
        SetSortRule(&(g->adjList[i]), WhoIsPrecede);
    }
}

void AddEdge(Graph * g, int fromV, int toV) {
    LInsert(&(g->adjList[fromV]), toV);
    LInsert(&(g->adjList[toV]), fromV);
    g->edgeCount += 1;
}

void GraphDestroy(Graph * g) {
    if(g->adjList != NULL)
        free(g->adjList);
    if(g->visitInfo != NULL)
        free(g->visitInfo);
}

int VisitVertex(Graph * g, int visitV) {
    if(g->visitInfo[visitV] == 0) {
        g->visitInfo[visitV] = 1;
        printf("%d ", visitV);
        return 1;
    }
    return 0;
}

void DFS(Graph * g, int startV) {
    Stack stack;
    int visitV = startV;
    int nextV;

    StackInit(&stack);
    VisitVertex(g, visitV);
    SPush(&stack, visitV);

    while(LFirst(&(g->adjList[visitV]), &nextV) == 1) {
        int visitFlag = 0;

        if(VisitVertex(g, nextV) == 1) {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = 1;
        }
        else {
            while(LNext(&(g->adjList[visitV]), &nextV) == 1) {
                if(VisitVertex(g, nextV) == 1) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = 1;
                    break;
                }
            }
        }

        if(visitFlag == 0) {
            if(SIsEmpty(&stack) == 1)
                break; //returned to the start vertex
            else
                visitV = SPop(&stack);
        }
    }
    memset(g->visitInfo, 0, sizeof(int) * g->vertexCount);
}

void BFS(Graph * g, int startV) {
    Queue queue;
    int visitV = startV;
    int nextV;

    QueueInit(&queue);
    
    VisitVertex(g, visitV);

    while(LFirst(&(g->adjList[visitV]), &nextV) == 1) {
        if(VisitVertex(g, nextV) == 1)
            Enqueue(&queue, nextV);

        while(LNext(&(g->adjList[visitV]), &nextV) == 1) {
            if(VisitVertex(g, nextV) == 1)
                Enqueue(&queue, nextV);
        }

        if(QIsEmpty(&queue) == 1)
            break;
        else
            visitV = Dequeue(&queue);
    }
    memset(g->visitInfo, 0, sizeof(int) * g->vertexCount);
}

int main(void) {
	int vertexCount, edgeCount, startVertex, src, dest, i;
	scanf("%d %d %d", &vertexCount, &edgeCount, &startVertex);
    
    Graph graph;
    GraphInit(&graph, vertexCount);

	for(i = 0; i < edgeCount; i++) {
		scanf("%d %d", &src, &dest);
        AddEdge(&graph, src, dest);
	}

    DFS(&graph, startVertex);
    printf("\n");
    BFS(&graph, startVertex);

    GraphDestroy(&graph);

	return 0;
}