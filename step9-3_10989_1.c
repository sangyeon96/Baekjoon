#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

int main(void) {
	int numCnt, tmpNum, i, j;
	int number[MAX] = {0, };

	scanf("%d", &numCnt);
	//카운팅 정렬 이용
	for(i = 0; i < numCnt; i++) {
		scanf("%d", &tmpNum);
		number[tmpNum]++;
	}

	for(i = 1; i < MAX; i++) {
		if(number[i] == 0)
			continue;
		else {
			for(j = 1; j <= number[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
	
	return 0;
}