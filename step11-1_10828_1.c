#include <stdio.h>
#include <stdlib.h>
#define MAXORDERSIZE 6
#define STACKSIZE 10000

int main(void) {
	int count, num, pushCount, empty, i;
	char order[MAXORDERSIZE];

	int * stack = (int *)malloc(sizeof(int) * STACKSIZE);

	//initialize
	for(i = 0; i < STACKSIZE; i++) {
		*(stack+i) = 0;
	}

	pushCount = 0;
	scanf("%d", &count);
	for(i = 0; i < count; i++) {
		scanf("%s", order);
		if(order[3] == 'h') { //push
			scanf("%d", &num);

			*(stack+pushCount) = num;
			pushCount++;
		}
		else if(order[0] == 'p') { //pop
			if(pushCount > 0) {
				printf("%d\n", *(stack+pushCount-1));
				*(stack+pushCount-1) = 0;
				pushCount--;
			}
			else
				printf("-1\n");
		}
		else if(order[0] == 's') { //size
			printf("%d\n", pushCount);
		}
		else if(order[0] == 'e') { //empty
			empty = (pushCount > 0)? 0 : 1;
			printf("%d\n", empty);
		}
		else if(order[0] == 't') { //top
			if(pushCount > 0)
				printf("%d\n", *(stack+pushCount-1));
			else
				printf("-1\n");
		}
		else {
			printf("Wrong Order Type\n");
		}

		/* print stack
		for(i = 0; i < pushCount; i++)
			printf("%d ", *(stack+i));*/
	}

	return 0;
}