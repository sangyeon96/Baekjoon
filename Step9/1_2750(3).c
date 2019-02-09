#include <stdio.h>
#include <stdlib.h>

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
    int size, tmp, i, j;
    scanf("%d", &size);
    int array[size];
    for(i = 0; i < size; i++)
        scanf("%d", &array[i]);

    //퀵정렬 라이브러리 이용
    qsort(array, size, sizeof(int), cmpfunc);

    for(i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}