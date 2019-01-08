#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 10000

typedef struct arrayQueue {
	int frontIndex;
	int rearIndex;
	int document[QUEUESIZE];
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
	q->document[q->rearIndex++] = num;
}

int dequeue(Queue * q) {
	if(!isEmpty(q))
		return q->document[q->frontIndex++];
	else //Queue Memory Error
		return -1;
}

int main(void) {
	int testCount, docCount, docIndex, prio;
	int printIndex, printCount;
	int temp, i, j;

	scanf("%d", &testCount);
	for(i = 0; i < testCount; i++) {
		Queue * queue = (Queue *)malloc(sizeof(Queue));
		init_queue(queue);
		printCount = 0;
		scanf("%d %d", &docCount, &docIndex);
		for(j = 0; j < docCount; j++) {
			scanf("%d", &prio);
			enqueue(queue, prio);
		}

		while(!isEmpty(queue)) {
			printIndex = queue->frontIndex;
			for(j = queue->frontIndex + 1; j < queue->rearIndex; j++) {
				if(queue->document[j] > queue->document[printIndex]) {
					printIndex = j;
				}
			}

			for(j = queue->frontIndex; j < printIndex; j++) {
				if(docIndex == j)
					docIndex = queue->rearIndex;
				enqueue(queue, dequeue(queue));
			}

			printCount++;
			if(printIndex == docIndex)
				break;
		}
		free(queue);
		printf("%d\n", printCount);
	}

	return 0;
}