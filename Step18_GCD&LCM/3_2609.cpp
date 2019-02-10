#include <iostream>
using namespace std;

int gcd(int a, int b) { //최대공약수
	while(b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int lcm(int a, int b) { //최소공배수
	return a * b / gcd(a, b);
}

int main() {
	int num1, num2;
	cin >> num1 >> num2;

	cout << gcd(num1, num2) << endl;
	cout << lcm(num1, num2) << endl;

	return 0;
}