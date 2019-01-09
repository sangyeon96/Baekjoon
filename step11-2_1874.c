#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACKSIZE 100000
#define OPERSIZE 200001

typedef struct arrayStack {
	int data[STACKSIZE];
	int topIndex;
}Stack;

char operation[OPERSIZE];
int operIndex = 0;

void init_stack(Stack *s) {
	s->topIndex = -1;
}

int isEmpty(Stack *s) {
	if(s->topIndex == -1)
		return 1;
	else
		return 0;
}

void push(Stack *s, int num) {
	operation[operIndex++] = '+';
	s->data[++s->topIndex] = num;
}

int pop(Stack *s) {
	if(!isEmpty(s)) {
		operation[operIndex++] = '-';
		return s->data[s->topIndex--];
	}
	else //Stack Memory Error
		return -1;
}

char * Operate() {
	Stack * stack = (Stack *)malloc(sizeof(Stack));

	for(i = 0; i < arraySize; i++) {
		if(array[pushStatusIndex] < popArray[i]) {
			for(j = array[pushStatusIndex]; j <= popArray[i]; j++)
				push(stack, j);
			popNum = pop(stack);
			pushStatusIndex = popNum - 1;
		}
		else if(array[pushStatusIndex] > popArray[i]) {
			popNum = pop(stack);
			if(popNum == popArray[i]) {
				pushStatusIndex = popNum;
			}
			else {
				return "NO";
			}
		}
	}

	free(stack);
	return opertion;
}

int main(void) {
	int arraySize, pushStatusIndex, popNum, i, j;

	
	init_stack(stack);
	pushStatusIndex = 0;

	scanf("%d", &arraySize);
	int array[arraySize];
	for(i = 0; i < arraySize; i++)
		array[i] = i+1;
	int popArray[arraySize];
	for(i = 0; i < arraySize; i++)
		scanf("%d", popArray[i]);

	
	return 0;
}