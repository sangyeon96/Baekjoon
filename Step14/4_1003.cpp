#include <iostream>
using namespace std;

typedef struct _fibonacci {
	int zeroPrintCnt;
	int onePrintCnt;
}Fibonacci;

/*
	n이 40보다 작거나 같으므로 int형으로 표현할 수 있으며,
	재귀함수보다 빠른 for문으로 풀면 될 것 같다.
*/
int main() {
	int testCnt;
	cin >> testCnt;

	int maxSize = 41;
	Fibonacci *fibonacci = new Fibonacci[maxSize];
	for(int i = 0; i < maxSize; i++) {
		if(i == 0) {
			fibonacci[0].zeroPrintCnt = 1;
			fibonacci[0].onePrintCnt = 0;
		}
		else if(i == 1) {
			fibonacci[1].zeroPrintCnt = 0;
			fibonacci[1].onePrintCnt = 1;
		}
		else {
			fibonacci[i].zeroPrintCnt = fibonacci[i-1].zeroPrintCnt + fibonacci[i-2].zeroPrintCnt;
			fibonacci[i].onePrintCnt = fibonacci[i-1].onePrintCnt + fibonacci[i-2].onePrintCnt;
		}
	}

	for(int i = 0; i < testCnt; i++) {
		int n;
		cin >> n;

		cout << fibonacci[n].zeroPrintCnt << " " << fibonacci[n].onePrintCnt << endl;
	}

	delete[] fibonacci;
	return 0;
}