#include <iostream>

using namespace std;

long long sour[10] = { 0, };
long long bitter[10] = { 0, };


long long diff(long long a, long long b) {
	if (a > b) return a - b;
	else return b - a;
}

long long solve(int N) {
	long long min = 1000000;


	for (int i = 1; i < (1 << N); i++) {
		
		long long sour_all = 1;
		long long bitter_all = 0;

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				sour_all *= sour[j];
				bitter_all += bitter[j];
			}
		}
		int dif = diff(sour_all, bitter_all);
		if (min > dif) min = dif;
	
	}

	return min;
	
}

int main() {
	int N;	// 재료 개수


	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> sour[i] >> bitter[i];
	}

	cout << solve(N);

	system("pause");
}