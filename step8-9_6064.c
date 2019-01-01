#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int M;
	int N;
	int x;
	int y;
}information;

int calculateYear(information * info) {
	int maxValue, minValue, gap, start, remainder, max, result, i, j;

	if(info->x == info->y)
		result = info->x;
	else {
		if(info->M > info->N) { //M > N
			maxValue = info->M;
			minValue = info->N;
			gap = maxValue - minValue;

			//calculate Xstart(start)
			if(info->y <= gap)
				start = minValue + info->y;
			else
				start = info->y - gap;
			//printf("x start: %d\n", start);

			//calculate Xmax(max)
			remainder = info->y % gap;
			if(remainder == 0)
				remainder = gap;
			//printf("remainder: %d\n", remainder);

			if(minValue <= gap) {
				max = gap + remainder;
				gap = maxValue - gap;
				//printf("gap: %d\n", gap);

				i = 1;
				j = start;
				result = -1;
				while(1) {
					if(j == info->x) {
						result = i * minValue + info->y;
						break;
					}
					if(j == max) {
						break;
					}
					i++;
					j += gap;
					if(j > max)
						j -= maxValue;
				}
			}
			else  { //minValue > gap
				max = maxValue - gap + remainder;

				i = 1;
				j = start;
				result = -1;
				while(1) {
					if(j == info->x) {
						result = i * minValue + info->y;
						break;
					}
					i++;
					j -= gap;
					if(j <= 0)
						j = max;
					if(j == start)
						break;
				}
			}
			//printf("x max: %d\n", max);
		}
		else if(info->M < info->N) { //M < N
			maxValue = info->N;
			minValue = info->M;
			gap = maxValue - minValue;

			//calculate Ystart(start)
			if(info->x <= gap)
				start = minValue + info->x;
			else
				start = info->x - gap;
			//printf("y start: %d\n", start);

			//calculate Ymax(max)
			remainder = info->x % gap;
			if(remainder == 0)
				remainder = gap;
			//printf("remainder: %d\n", remainder);
			
			if(minValue <= gap) {
				max = gap + remainder;
				gap = maxValue - gap;

				i = 1;
				j = start;
				result = -1;
				while(1) {
					if(j == info->y) {
						result = i * minValue + info->x;
						break;
					}
					if(j == max)
						break;
					i++;
					j += gap;
					if(j > max)
						j -= maxValue;
				}
			}
			else { //minValue > gap
				max = maxValue - gap + remainder;

				i = 1;
				j = start;
				result = -1;
				while(1) {
					if(j == info->y) {
						result = i * minValue + info->x;
						break;
					}
					i++;
					j -= gap;
					if(j <= 0)
						j = max;
					if(j == start)
						break;
				}
			}
			//printf("y max: %d\n", max);
		}
		else //M == N && x != y
			result = -1;
	}

	return result;
}

int main(void) {
	int testCount, i;
	scanf("%d", &testCount);

	information * info = (information *)malloc(sizeof(information)*testCount);
	for(i = 0; i < testCount; i++) {
		scanf("%d %d %d %d", &info[i].M, &info[i].N, &info[i].x, &info[i].y);
	}

	for(i = 0; i < testCount; i++) {
		printf("%d\n", calculateYear(&info[i]));
	}

	return 0;
}