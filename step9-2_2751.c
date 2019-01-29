#include <stdio.h>
#define MAX 1000000

void merge(int data[], int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = low;
	int p;

    int sortedNum[MAX];
    while(i <= mid && j <= high) {
    	/*
    	앞부분의 인덱스와 뒷부분의 인덱스를 비교해서 
    	앞부분의 값이 작으면 앞부분 데이터를 넣고,
    	뒷부분의 값이 작으면 뒷부분 데이터를 넣는다.
    	*/
        if(data[i] <= data[j])
        	sortedNum[k++] = data[i++];
        else
        	sortedNum[k++] = data[j++];
    }

    //남아있는 값들 복사
    while(i <= mid)
    	sortedNum[k++] = data[i++];

    while(j <= high)
    	sortedNum[k++] = data[j++];

    //다시 number배열에 넣는다.
    for(p = low; p <= high; p++)
    	data[p] = sortedNum[p];
}

void mergeSort(int data[], int low, int high) {
	int mid;

    if(low < high) { //하나로 쪼개질 때까지 Divide
        mid = (low + high) / 2;
        mergeSort(data, low , mid); //앞부분
        mergeSort(data, mid + 1, high); //뒷부분
        merge(data, low, mid, high);
    }
}

int main() {
	int numCnt, i;
	int number[MAX];

	scanf("%d", &numCnt);
	for(i = 0; i < numCnt; i++)
		scanf("%d", &number[i]);

     mergeSort(number, 0, numCnt - 1);
     
     for(i = 0; i < numCnt; i++)
         printf("%d\n", number[i]);

  	return 0;
}
    
    
