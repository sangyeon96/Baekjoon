#include <stdio.h>

int main(void) {
    int size, tmp, i, j;
    scanf("%d", &size);
    int array[size];
    for(i = 0; i < size; i++)
        scanf("%d", &array[i]);

    //선택정렬 사용
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++) {
            if(array[i] > array[j]) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    for(i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}