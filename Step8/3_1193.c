#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int i, j, index, count, n;
	float result;
	bool isCount = false;

	scanf("%d", &n);

	i = 1;
	count = 0;
	while(1) {
		index = 1;
		if(i % 2 == 0) { //even number
			for(j = i; j >= 1; j--) {
				count++;
				result = (float)index / j;

				if(n == count) {
					printf("%d/%d", index, j);
					isCount = true;
					break;
				}

				index++;
			}
		}
		else { //odd number
			for(j = i; j >= 1; j--) {
				count++;
				result = (float)j / index;

				if(n == count) {
					printf("%d/%d", j, index);
					isCount = true;
					break;
				}

				index++;
			}
		}
		if(isCount)
			break;
		i++;
	}

	//printf("%f", result);

	return 0;
}