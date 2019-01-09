#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 31

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

void push(Stack *s, char bracket) {
	s->data[++s->topIndex] = bracket;
}

char pop(Stack *s) {
	if(!isEmpty(s))
		return s->data[s->topIndex--];
	else //Stack Memory Error
		return 'e';
}

int pairMatch(char * exp) {
	int length, i;
	char bracket;
	int result = 0;

	length = strlen(exp);
	Stack *checkPair = (Stack *)malloc(sizeof(Stack));
	init_stack(checkPair);

	for(i = 0; i < length; i++) {
		if(exp[i] == '(' || exp[i] == '[') {
			push(checkPair, exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == ']') {
			if(isEmpty(checkPair))
				return 0;
			else {
				bracket = pop(checkPair);
				if(bracket == '(') {
					if(exp[i] != ')')
						return 0;
				}
				else if(bracket == '[') {
					if(exp[i] != ']')
						return 0;
				}
			}
		}
		else
			printf("Wrong Input\n");
	}
	if(isEmpty(checkPair)) {
		free(checkPair);
		return 1;
	}
	else {
		free(checkPair);
		return 0;
	}
}

int calculate(char * exp) {
	int length, i;
	char prevBracket = 'z';
	char operation;
	int result = 0;

	Stack * opStack = (Stack *)malloc(sizeof(Stack));
	int numArray[MAX];
	int numArrayIndex = 0;
	init_stack(opStack);

	length = strlen(exp);
	for(i = 0; i < length; i++) {
		if(exp[i] == '(' || exp[i] == '[') {
			if(exp[i] == '(') {
				if(prevBracket == '(' || prevBracket == '[')
					push(opStack, '*');
				else if(prevBracket == ')') {
					push(opStack, '+');
					numArray[numArrayIndex] = 2;
					numArrayIndex++;
				}
				else if(prevBracket == ']') {
					push(opStack, '+');
				}
				else { //first
					numArray[numArrayIndex] = 2;
					numArrayIndex++;
				}
			}
			else if(exp[i] == '[') {
				if(prevBracket == '(' || prevBracket == '[')
					push(opStack, '*');
				else if(prevBracket == ')') {
					push(opStack, '+');
					numArray[numArrayIndex] = 3;
					numArrayIndex++;
				}
				else if(prevBracket == ']') {
					push(opStack, '+');
				}
				else { //first
					numArray[numArrayIndex] = 3;
					numArrayIndex++;
				}	
			}
		}
		else if(exp[i] == ')' || exp[i] == ']') {
			if(exp[i] == ')') {
				if(prevBracket == '(') {
					numArray[numArrayIndex] = 2;
					numArrayIndex++;
				}
				else if(prevBracket == '[') {
					//impossible
				}
				else if(prevBracket == ')') {
				}
				else if(prevBracket == ']') {
				}
			}
			else if(exp[i] == ']') {
				if(prevBracket == '(') {
					//impossible
				}
				else if(prevBracket == '[') {
					numArray[numArrayIndex] = 3;
					numArrayIndex++;
				}
				else if(prevBracket == ')') {
				}
				else if(prevBracket == ']') {
				}
			}
		}
		else
			printf("Wrong Input\n");

		prevBracket = exp[i];
	}

	for(i = numArrayIndex - 1; i > 0; i--) {
		operation = pop(opStack);
		if(operation == '*')
			printf("%d %c %d ", numArray[i], operation, numArray[i-1]);
		else if(operation == '+') {
			printf(" %c ", operation);
		}
	}
	printf("\n");
	
	return 1;
}

int main(void) {
	int flag;
	char expression[MAX];

	scanf("%s", expression);
	flag = pairMatch(expression);
	if(flag)
		printf("%d\n", calculate(expression));
	else
		printf("%d\n", flag);

	return 0;
}