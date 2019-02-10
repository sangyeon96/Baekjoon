#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int floor;
	int room;
}apartment;

int calculateNumberOfResidents(apartment * apart) {
	int data[apart->floor + 1][apart->room + 1];
	int i, j, k;

	//initialize
	for(i = 0; i <= apart->floor; i++)
		for(j = 1; j <= apart->room; j++)
			data[i][j] = 0;

	//calculate
	for(i = 0; i <= apart->floor; i++) {
		for(j = 1; j <= apart->room; j++) {
			if(i == 0)
				data[i][j] = j;
			else {
				for(k = 1; k <= j; k++) {
					data[i][j] += data[i-1][k];
				}
			}
		}
	}

	/*
	for(i = 0; i <= apart->floor; i++) {
		printf("floor %d : ", i);
		for(j = 1; j <= apart->room; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	*/
	

	return data[apart->floor][apart->room];
}

int main(void) {
	int testCaseNum, i;
	scanf("%d", &testCaseNum);

	apartment * apart = (apartment *)malloc(sizeof(apartment) * testCaseNum);

	for(i = 0; i < testCaseNum; i++) {
		scanf("%d", &apart[i].floor); //층
		scanf("%d", &apart[i].room); //호
	}

	for(i = 0; i < testCaseNum; i++) {
		printf("%d\n", calculateNumberOfResidents(&apart[i]));
	}

	return 0;
}