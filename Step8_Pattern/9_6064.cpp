#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while(b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int testCnt;
	cin >> testCnt;

	int M, N; //최대
	int x, y;
	int i, j;
	int lcmNum;
	int gap;
	int count;
	for(i = 0; i < testCnt; i++) {
		cin >> M >> N >> x >> y;

		/*
			<M:N>에서 M, N의 최소공배수 번째 해를 넘어간다는 것은,
			<x:y>가 유효하지 않은 표현이므로 -1 출력
		*/
		lcmNum = lcm(M, N);
		if(M > N) {
			gap = M - N;

			j = y; //y기준으로
			count = y;
			while(1) {
				if(count >= lcmNum) {
					cout << "-1" << endl;
					break;
				}
				else if(x == j) { //x == y
					cout << count << endl;
					break;
				}
				else {
					j -= gap;
					if(j <= 0) {
						j = (j + gap) + N;
					}
					count += N;
				}
			}
		}
		else if(M < N) {
			gap = N - M;

			j = x; //x기준으로
			count = x;
			while(1) {
				if(count >= lcmNum) {
					cout << "-1" << endl;
					break;
				}
				else if(y == j) { //x == y
					cout << count << endl;
					break;
				}
				else {
					j -= gap;
					if(j <= 0) {
						j = (j + gap) + M;
					}
					count += M;
				}
			}
		}
		else { //M == N
			gap = 0;
			if(x == y)
				cout << x << endl;
			else
				cout << "-1" << endl;
		}
	}
	return 0;
}