#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b) { //최대공약수
	while(b != 0) {
		long long int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long int lcm(long long int a, long long int b) { //최소공배수
	return a * b / gcd(a, b);
}

int main() {
	long long int num1, num2;
	cin >> num1 >> num2;
	cout << lcm(num1, num2) << endl;

	return 0;
}