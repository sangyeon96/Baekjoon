#include <iostream>
using namespace std;

int list_size = 46;
int *list = new int[list_size];

int fibonacci(int n) {
	if(n == 0 || n == 1) {
		if(list[n] == -1)
			list[n] = n;
		return list[n];
	}
	else {
		if(list[n-2] != -1 && list[n-1] != -1)
			return list[n-2] + list[n-1];
		else {
			list[n-2] = fibonacci(n-2);
			list[n-1] = fibonacci(n-1);
			return list[n-2] + list[n-1];
		}
	}
}

int main() {
	int n;
	
	cin >> n;
	for(int i = 0; i < list_size; i++) {
		list[i] = -1;
	}
	cout << fibonacci(n) << endl;

	delete[] list;
	return 0;
}