#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}coordinates;

int minActCount(coordinates * coord) {
	int minCount, selected, i;
	int possible[3] = {-1, 0, 1};
	long arriveCoord;
	int distance = coord->y - coord->x;
	int middle = distance/2;

	minCount = 0;
	arriveCoord = coord->x;
	while(1) {
		minCount++;
		selected = possible[2];
		
		if(arriveCoord + possible[2] > middle) {
			if(arriveCoord + possible[1] == middle)
				selected = possible[1];
			else
				selected = possible[0];
		}
		
		arriveCoord += selected;
		printf("%d: %d selected -> now %ld\n", minCount, selected, arriveCoord);
		possible[0] = selected - 1;
		possible[1] = selected;
		possible[2] = selected + 1;

		if(arriveCoord >= middle) {
			break;
		}
	}

	while(1) {
		minCount++;
		selected = possible[0];

		if(arriveCoord + possible[0] < coord->y) {
			selected = possible[2];
		}
		arriveCoord += selected;
		printf("%d: %d selected -> now %ld\n", minCount, selected, arriveCoord);
		possible[0] = selected - 1;
		possible[1] = selected;
		possible[2] = selected + 1;

		if(arriveCoord >= coord->y)
			break;
	}
	/*
	if(distance == 1)
		minCount = 1;
	else
		minCount += 1;*/
	
	return minCount;
}

int main(void) {
	int testCount, i;
	scanf("%d", &testCount);

	coordinates * coord = (coordinates *)malloc(sizeof(coordinates)*testCount);
	for(i = 0; i < testCount; i++)
		scanf("%d %d", &coord[i].x, &coord[i].y);

	for(i = 0; i < testCount; i++)
		printf("%d\n", minActCount(&coord[i]));

	return 0;
}