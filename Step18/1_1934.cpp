#include <iostream>
using namespace std;

int gcd(int a, int b) { //최대공약수: greatest common divisor
	/*
		유클리드 호제법 이용
		나누어 떨어질 때까지(b == 0일 때까지) 나머지를 구하는 과정을 반복
		나누어 떨어질 때 나누는 수가 최대공약수
	*/
	while(b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int lcm(int a, int b) { //최소공배수: least common multiple
	return a * b / gcd(a, b);
}

int main() {
	int testCnt;
	cin >> testCnt;

	for(int i = 0; i < testCnt; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		cout << lcm(num1, num2) << endl;
	}

	return 0;
}