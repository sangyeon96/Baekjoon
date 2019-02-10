#include <stdio.h>
#include <stdlib.h>
#define MAXORDERSIZE 6
#define STACKSIZE 10000

typedef struct arrayStack {
	int data[STACKSIZE];
	int topIndex;
}Stack;

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
	s->data[++s->topIndex] = num;
}

int pop(Stack *s) {
	if(!isEmpty(s)) {
		return s->data[s->topIndex--];
	}
	else //Stack Memory Error
		return -1;
}

int main(void) {
	int count, num, i;
	char order[MAXORDERSIZE];

	Stack * stack = (Stack *)malloc(sizeof(Stack));
	init_stack(stack);

	scanf("%d", &count);
	for(i = 0; i < count; i++) {
		scanf("%s", order);
		if(order[3] == 'h') { //push
			scanf("%d", &num);
			push(stack, num);
		}
		else if(order[0] == 'p') { //pop
			printf("%d\n", pop(stack));
		}
		else if(order[0] == 's') { //size
			printf("%d\n", stack->topIndex+1);
		}
		else if(order[0] == 'e') { //empty
			printf("%d\n", isEmpty(stack));
		}
		else if(order[0] == 't') { //top
			if(!isEmpty(stack))
				printf("%d\n", stack->data[stack->topIndex]);
			else
				printf("%d\n", stack->topIndex);
		}
		else {
			printf("Wrong Order Type\n");
		}
	}
	free(stack);
	return 0;
}