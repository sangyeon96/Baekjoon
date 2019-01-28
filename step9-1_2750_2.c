#include <stdio.h>

int main(void) {
    int size, tmp, i, j;
    scanf("%d", &size);
    int array[size];
    for(i = 0; i < size; i++)
        scanf("%d", &array[i]);

    //거품정렬 사용
    for(i = size - 1; i >= 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }

    for(i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}