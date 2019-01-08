#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

typedef struct arrayStack {
	char data[MAX];
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

void push(Stack *s, char paren) {
	s->data[++s->topIndex] = paren;
}

char pop(Stack *s) {
	if(!isEmpty(s))
		return s->data[s->topIndex--];
	else //Stack Memory Error
		return 'e';
}

int parenMatch(char * ex) {
	int length, i;
	length = strlen(ex);
	Stack *checkParen = (Stack *)malloc(sizeof(Stack));
	init_stack(checkParen);
	for(i = 0; i < length; i++) {
		if(ex[i] == '(') {
			push(checkParen, ex[i]);
		}
		else if(ex[i] == ')') {
			if(isEmpty(checkParen))
				return 0;
			else
				pop(checkParen);
		}
		else {
			printf("Wrong Input\n");
		}
	}
	if(isEmpty(checkParen)) {
		free(checkParen);
		return 1;
	}
	else {
		free(checkParen);
		return 0;
	}
}

int main(void) {
	int testCount, i;
	char expression[MAX];

	scanf("%d", &testCount);
	for(i = 0; i < testCount; i++) {
		scanf("%s", expression);

		if(parenMatch(expression)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}