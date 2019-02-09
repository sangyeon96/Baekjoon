#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 1000000

typedef struct arrayQueue {
	int frontIndex;
	int rearIndex;
	int data[QUEUESIZE];
}Queue;

void init_queue(Queue * q) {
	q->frontIndex = 0;
	q->rearIndex = 0;
}

int isEmpty(Queue * q) {
	if(q->frontIndex == q->rearIndex)
		return 1;
	else
		return 0;
}

void enqueue(Queue * q, int num) {
	q->data[q->rearIndex++] = num;
}

int dequeue(Queue * q) {
	if(!isEmpty(q))
		return q->data[q->frontIndex++];
	else //Queue Memory Error
		return -1;
}

int queueSize(Queue * q) {
	int size = q->rearIndex - q->frontIndex;
	return size;
}

int main(void) {
	int n, m, i;
	int size;

	Queue * queue = (Queue *)malloc(sizeof(Queue));
	init_queue(queue);

	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		enqueue(queue, i+1);

	printf("<");
	while(!isEmpty(queue)) {
		size = queueSize(queue);
		for(i = 0; i < m - 1; i++) 
			enqueue(queue, dequeue(queue));
		if(size == 1)
			printf("%d>\n", dequeue(queue));
		else
			printf("%d, ", dequeue(queue));
	}
	free(queue);
	return 0;
}