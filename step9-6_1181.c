#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX 51

typedef struct _node {
	char word[MAX];
	int wordLength;
	struct _node * next;
	struct _node * prev;
}Node;

typedef struct _queue {
	Node * head;
	Node * tail;
	int size;
}Queue;

void QueueInit(Queue * q) {
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}

int IsEmpty(Queue * q) {
	if(q->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void enqueue(Queue * q, char * word, int wordLength) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	int enqueued = 0;
	int notEnqueued = 1;
	int same = 1;
	int i;

	memset(newNode->word, 0, MAX);
	newNode->wordLength = wordLength;
	strncpy(newNode->word, word, wordLength);

	if(IsEmpty(q)) {
		newNode->prev = NULL;
		newNode->next = NULL;
		q->head = newNode;
		q->tail = newNode;
	}
	else {
		Node * tmpNode = q->head;
		while(tmpNode != NULL) {
			if(tmpNode->wordLength > newNode->wordLength) {
				if(tmpNode->prev == NULL) { //머리에 넣기
					newNode->prev = NULL;
					newNode->next = tmpNode;
					tmpNode->prev = newNode;
					q->head = newNode;
					notEnqueued = 0;
					break;
				}
				else { //tmpNode의 앞에 넣기
					newNode->prev = tmpNode->prev;
					tmpNode->prev->next = newNode;
					tmpNode->prev = newNode;
					newNode->next = tmpNode;
					notEnqueued = 0;
					break;
				}
			}
			else if(tmpNode->wordLength == newNode->wordLength) {
				//사전 순
				for(i = 0; i < wordLength; i++) {
					if(tmpNode->word[i] != newNode->word[i]) {
						same = 0;
						int tmpNodeASCII = tmpNode->word[i];
						int newNodeASCII = newNode->word[i];
						if(tmpNodeASCII > newNodeASCII) {
							//tmpNode의 앞에 넣기
							newNode->prev = tmpNode->prev;
							tmpNode->prev->next = newNode;
							tmpNode->prev = newNode;
							newNode->next = tmpNode;
							enqueued = 1;
							break;
						}
						else {
							//tmpNodeASCII보다 newNodeASCII가 작으면 tmpNode->next로 넘어가야하므로 break;
							break;
						}
					}
				}
				if(same) {
					//같은 단어가 여러 번 입력된 경우 한 번씩만 출력
					notEnqueued = 0;
					q->size--;
					break;
				}
				else if(enqueued){
					notEnqueued = 0;
					break;
				}
				else {
					tmpNode = tmpNode->next;
				}
			}
			else {
				tmpNode = tmpNode->next;
			}
		}
		if(notEnqueued) {
			//꼬리에 넣기
			newNode->prev = q->tail;
			q->tail->next = newNode;
			newNode->next = NULL;
			q->tail = newNode;
		}
	}
	q->size++;
}

void dequeue(Queue * q) {
	if(IsEmpty(q)) { //Queue Memory Error
		printf("Queue Memory Error\n");
		exit(-1);
	}

	Node * rnode = q->head;
	char rword[MAX];
	strncpy(rword, rnode->word, MAX);
	int rwordLength = rnode->wordLength;
	int i;

	q->head = q->head->next;
	free(rnode);

	if(q->head == NULL)
		q->tail = NULL;
	else
		q->head->prev = NULL;

	q->size--;
	printf("%s\n", rword);
}

void printQueue(Queue * q) {
	Node * tmpNode = q->head;
	while(tmpNode != NULL) {
		printf("%s\n", tmpNode->word);
		tmpNode = tmpNode->next;
	}
}

int main(void) {
	int wordCount, wordLength, i;
	char word[MAX];
	Queue queue;
	QueueInit(&queue);
	scanf("%d", &wordCount);
	for(i = 0; i < wordCount; i++) {
		scanf("%s", word);
		wordLength = strlen(word);
		word[wordLength] = '\0';
		enqueue(&queue, word, wordLength);
		//printQueue(&queue);
		memset(word, 0, MAX);
	}
	//Runtime Error는 enqueue에서 뜨는듯
	//while(!IsEmpty(&queue))
	//	dequeue(&queue);
	printQueue(&queue);

	return 0;
}