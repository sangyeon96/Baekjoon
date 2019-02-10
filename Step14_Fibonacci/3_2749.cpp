#include <iostream>
using namespace std;

/* 피사노 주기
주기의 길이가 P면,
N번째 피보나치 수를 M으로 나눈 나머지는
N%P번째 피보나치 수를 M으로 나눈 나머지와 같다.

M=10^k일 때, k>2라면, 주기는 항상 15*10^(k-1)이다.

이 문제에서
M = 10^6 = 1000000
P = 15 * 10^5 = 1500000

이 문제는 피사노 주기를 이용하면 풀리지만,
행렬 곱셈을 이용하면, 더 빨리 풀 수 있다 -> O(log2n)

11444번도 풀어보기(피사노 주기로 풀 수 없음)
*/

int main() {
	unsigned long long n;
	cin >> n;
	
	int M = 1000000; //나누는 수
	int P = 1500000; //주기

	//주기(P)에 따라 나머지가 반복되므로 n을 P로 나눈 나머지로 둔다.
	n %= P;
	//1000000으로 나눈 수를 저장할꺼기 때문에 int형이어도 된다.
	int fibonacci[n+1];
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for(int i = 2; i < n + 1; i++)
		fibonacci[i] = (fibonacci[i-2] + fibonacci[i-1]) % M;

	cout << fibonacci[n] << endl;
	return 0;
}
/*
	처음에 unsigned long long fibonacci[n % P]으로 두고 했다가 틀렸었다.
	예제 입력 1000의 경우에도 228875가 아닌 397771이 나온 걸 보니
	unsigned long long형으로 표현할 수 없나보다.
*/