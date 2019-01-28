#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

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
    	return 1;
    if(num1 > num2)
    	return -1;

    return 0; //num1 == num2
}

int main(void) {
	char numbers[MAX]; //입력받은 수 문자열
	int digit; //자릿수
	int i;

	scanf("%s", numbers);
	digit = strlen(numbers);
	int num[digit]; //일의자리수 배열

	for(i = 0; i < digit; i++)
		num[i] = numbers[i] - '0'; //char형 int형 변환

	qsort(num, digit, sizeof(int), cmpfunc);

	for(i = 0; i < digit; i++) {
		printf("%d", num[i]);
	}
	printf("\n");

	return 0;
}