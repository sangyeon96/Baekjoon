#include <iostream>
using namespace std;

/* int형으로 표현할 수 있는 수를 넘는다 -> long long형 */
int main() {
	int n;
	cin >> n;

	long long fibonacci[n+1];
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for(int i = 2; i < n + 1; i++) {
		fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
	}
	cout << fibonacci[n] << endl;

	return 0;
}