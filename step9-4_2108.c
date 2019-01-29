#include <stdio.h>
#include <stdlib.h>
#define MAXABS 4000 * 2 + 1

int cmpfunc(const void * a, const void *b) {
    /*
    오름차순 비교 함수면,
    첫번째 변수가 두번째 변수보다 클 때 1
    첫번째 변수가 두번째 변수보다 작을 때 -1
    같을 때 0 반환하도록
    내림차순 비교 함수면 1, -1 반대
    */
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 < num2)
        return -1;
    if(num1 > num2)
        return 1;

    return 0; //num1 == num2
}

int main(void) {
	int numCnt, tmpNum, i, j;
	int maxCnt, maxCntIndex, maxSameCnt;

	float arithmeticMean = 0; //산술평균
	int median; //중앙값
	int mode; //최빈값
	int range; //범위(최댓값 - 최솟값)

	scanf("%d", &numCnt); //numCnt는 홀수
	int number[numCnt];
	int sameNumCnt[MAXABS] = {0, };
	for(i = 0; i < numCnt; i++) {
		scanf("%d", &tmpNum);
		number[i] = tmpNum;
		arithmeticMean += tmpNum;
		sameNumCnt[tmpNum+4000]++;
	}

	//퀵정렬 라이브러리 이용-오름차순
    qsort(number, numCnt, sizeof(int), cmpfunc);

    arithmeticMean = arithmeticMean / numCnt;
    printf("%.0f\n", arithmeticMean);
    median = number[numCnt/2];
    printf("%d\n", median);
    
    maxCnt = 0;
    for(i = 0; i < MAXABS; i++) {
    	/*
    	-4000 ~ 4000(인덱스 0 ~ MAXABS - 1)까지 각 숫자가 몇 개 있는지
    	sameNumCnt배열에 담겨있다.
    	*/
    	if(sameNumCnt[i] == 0) //입력 안한 숫자
    		continue;
    	else {
    		if(sameNumCnt[i] > maxCnt) {
    			maxCnt = sameNumCnt[i]; //최빈값은 빈도수가 몇인지
    			mode = i - 4000;
    		}
    	} 
    }
    if(maxCnt == 1) { //모든 숫자가 한 번씩만 입력되었으면
    	if(numCnt == 1) //하나만 입력 되었으면,
    		printf("%d\n", number[0]);
    	else //두 개 이상 입력되었으면,
    		printf("%d\n", number[1]);
    }
    else {
    	maxSameCnt = 0;
    	int maxNumber[MAXABS];
	    for(i = 0; i < MAXABS; i++) {
	    	if(sameNumCnt[i] == maxCnt) { //최빈값과 빈도수가 같은 게 몇 개인지
	    		maxNumber[maxSameCnt++] = i - 4000;
	    	}
	    }
	    if(maxSameCnt == 1)
	    	printf("%d\n", mode);
	    else { //최빈값이 여러 개 있으면
	    	mode = maxNumber[1]; //최빈값 중 두번째로 작은 값
	    	printf("%d\n", mode);
	    }
    }
    range = number[numCnt-1] - number[0]; //최대값 - 최소값
    printf("%d\n", range);

	return 0;
}