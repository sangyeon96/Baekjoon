#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b) {
	while(b != 0) {
		long long int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main() {
	long long int num1, num2;
	cin >> num1 >> num2;

	long long int gcdResult = gcd(num1, num2);
	for(int i = 0; i < gcdResult; i++) {
		cout << "1";
	}

	return 0;
}