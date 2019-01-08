#include <stdio.h>
#include <stdlib.h>
#define MAXORDERSIZE 6
#define QUEUESIZE 100000

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

int main(void) {
	int count, num, queueSize, i;
	char order[MAXORDERSIZE];

	Queue * queue = (Queue *)malloc(sizeof(Queue));

	scanf("%d", &count);
	for(i = 0; i < count; i++) {
		scanf("%s", order);

		if(order[3] == 'h') { //push
			scanf("%d", &num);
			enqueue(queue, num);
		}
		else if(order[0] == 'p') { //pop
			printf("%d\n", dequeue(queue));
		}
		else if(order[0] == 's') { //size
			queueSize = queue->rearIndex - queue->frontIndex;
			printf("%d\n", queueSize);
		}
		else if(order[0] == 'e') { //empty
			printf("%d\n", isEmpty(queue));
		}
		else if(order[0] == 'f') { //front
			if(!isEmpty(queue)) {
				printf("%d\n", queue->data[queue->frontIndex]);
			}
			else {
				printf("-1\n");
			}
		}
		else if(order[0] == 'b') { //back
			if(!isEmpty(queue)) {
				printf("%d\n", queue->data[queue->rearIndex-1]);
			}
			else {
				printf("-1\n");
			}
		}
		else {
			printf("Wrong Order Type\n");
		}
	}
	free(queue);
	return 0;
}