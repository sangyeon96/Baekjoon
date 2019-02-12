#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	1초당 반복문 수행 횟수가 1억(10^8)을 넘어가면,
	시간 제한을 초과할 가능성이 있다.
*/
int gcd(int a, int b) {
	while(b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

/* 내 생각
	두 수의 차들의 집합으로부터 최대공약수를 구하고,
	그 최대공약수의 약수들 중 나머지가 같은 것을 출력한다.
*/

/* 구글링
	A[i] = k[i] * m + j (정수 m으로 나누었을 때, 나머지 j)
	j를 없애기 위해 A[i], A[i-1]이용
	A[i] - A[i-1] = m * (k[i] - k[i-1])
	...수학 어렵다
*/

int main() {
	int N;
	cin >> N; // 2 <= N <= 100

	int num[N];
	for(int i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N); //오름차순 정렬

	int gapNum[N-1];
	for (int i = 0; i < N-1; i++)
		gapNum[i] = num[i+1] - num[i];
	
	int GCD;
	int maxGCD = 0;
	if(N == 2) {
		/*
			입력 한 수가 2개 일 때, 두 수의 차는 1개라는 것을 고려해야한다.
			고려 안했다가 gapNum[1]에 쓰레기값 들어가서 런타임에러 뜸
		*/
		maxGCD = gapNum[0];
	}
	else {
		for(int i = 0; i < N - 1; i++) {
			GCD = gcd(gapNum[i], gapNum[i+1]);
			if(maxGCD < GCD)
				maxGCD = GCD;
		}
	}

	int remainder[N];
	bool sameFlag1 = true;
	bool sameFlag2 = true;
	vector<int> result; //maxGCD의 약수들 저장하는 벡터
	/*
		제곱근 활용하면 for문 덜 돌 수 있다. 대신 배열에 저장한 후 정렬해야 한다.
		ex) 36의 약수 : 1 2 3 4 6 9 12 18 36
		1*36, 2*18, 3*12, 4*9, 6*6
	*/
	for(int i = 1; i*i <= maxGCD; i++) {
		if(maxGCD % i == 0) { 
			for(int j = 0; j < N; j++)
				remainder[j] = num[j] % i;

			for(int j = 0; j < N - 1; j++) {
				if(remainder[j] != remainder[j+1]) {
					sameFlag1 = false;
					break;
				}
			}
			if(sameFlag1)
				result.push_back(i);
			
			/*
				i로 나누어 떨어진다는 것은 약수라는 건데,
				입력한 수들의 나머지가 같은지 확인해봐야한다.
				또한, i로 나누어 떨어진다는 것은 maxGCD/i도 약수라는 건데,
				maxGCD/i도 입력한 수들의 나머지가 같은지 확인해봐야한다.
				(이것 때문에 디깅을 많이 했다..)
				이걸 제대로 안할 시,
				반례:
				4
				250
				1000
				100000
				25000
				정답:
				2 3 5 6 10 15 25 30 50 75 125 150 375 750
				오답:
				2 3 5 6 10 15 25 30 50 60 75 100 120 125 150 200 250 300 375 500 600 750 1000 1500 3000
			*/
			if(i * i != maxGCD) { //25의 약수일 경우, 1 5 25가 저장되도록(not 1 5 5 25)
				for(int j = 0; j < N; j++)
				remainder[j] = num[j] % (maxGCD / i);

				for(int j = 0; j < N - 1; j++) {
					if(remainder[j] != remainder[j+1]) {
						sameFlag2 = false;
						break;
					}
				}
				if(sameFlag2)
					result.push_back(maxGCD/i);
			}
			
			//초기화
			sameFlag1 = true;
			sameFlag2 = true;
		}
	}

	sort(result.begin(), result.end());
	int size = result.size();
	for(int i = 0; i < size; i++)
		if(i != 0) //1 제외
			cout << result[i] << " ";

	result.clear();
	return 0;
}