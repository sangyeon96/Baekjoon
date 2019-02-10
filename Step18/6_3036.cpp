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
int main() {
	int ringCnt;
	cin >> ringCnt; // 3 <= ringCnt <= 100

	int radius[ringCnt]; 
	for(int i = 0; i < ringCnt; i++)
		cin >> radius[i]; // 1 <= radius[i] <= 1000

	for(int i = 1; i < ringCnt; i++) {
		int GCD = gcd(radius[0], radius[i]);
		cout << radius[0]/GCD << "/" << radius[i]/GCD << endl;
	}
	
	return 0;
}