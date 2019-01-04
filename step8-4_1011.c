#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x;
	int y;
}coordinates;

int minActCount(coordinates * coord) {
	int minCount, standard;
	int distance = coord->y - coord->x;
	//printf("distance: %d\n", distance);

	int n = sqrt(distance);
	
	if(distance != pow(n, 2))
		n += 1;

	standard = pow(n, 2);
	//printf("standard: %d\n", standard);
	if(distance < standard - n + 1)
		minCount = n + (n - 1) - 1;
	else
		minCount = n + (n - 1);

	if(distance == 1 || distance == 2)
		minCount = distance;

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