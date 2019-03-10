#include <iostream>
using namespace std;
#define MAXSIZE 1000000

int main() {
	int N;
	cin >> N; // N개의 시험장(1 <= N <= 1,000,000)

	int A[N]; //i번 시험장에 있는 응시자의 수(1 <= A[i] <= 1,000,000)
	for(int i = 0; i < N; i++)
		cin >> A[i];

	int B, C;
	cin >> B >> C; // 1 <= B, C <= 1,000,000
	/* 
	B: 총감독관이 한 방에서 감시할 수 있는 응시자의 수
	C: 부감독관이 한 방에서 감시할 수 있는 응시자의 수
	*/

	int answer[MAXSIZE];
	/* DP 활용
	응시자수가 1명일 때부터 1,000,000명일 때까지의 감독 수 미리 저장
	answer[0]은 응시자수가 1명일 때, ~
	answer[999,999]는 응시자수가 1,000,000명일 때
	*/
	int mainSupervisor = 1;
	int subSupervisor = 0; //부감독 수
	int attendant; //응시자 수
	for(int i = 0; i < MAXSIZE; i++) {
		attendant = i + 1;
		if(mainSupervisor * B + subSupervisor * C >= attendant) {
			answer[i] = mainSupervisor + subSupervisor;
		}
		else {
			subSupervisor++;
			answer[i] = mainSupervisor + subSupervisor;
		}
	}

	/* 여기서 주의!
	시험장의 개수가 1,000,000이고, 응시자수는 1,000,000인데, 
	B, C가 1인 경우, 한 시험장마다 1,000,000명의 감독이 필요하므로,
	10^12 -> int 타입만으로 전체 감독 수를 저장할 수 없다.
	*/
	long long int totalSupervisor = 0;
	for(int i = 0; i < N; i++) {
		attendant = A[i];
		totalSupervisor += answer[attendant-1];
	}
	cout << totalSupervisor << endl;

	return 0;
}