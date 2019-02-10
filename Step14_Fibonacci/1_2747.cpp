#include <iostream>
using namespace std;

/* for문이 재귀함수보다 빠르다 */
int main() {
	int n;
	cin >> n;

	int fibonacci[n+1];
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for(int i = 2; i < n + 1; i++) {
		fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
	}
	cout << fibonacci[n] << endl;

	return 0;
}