#include <iostream>

using namespace std;

int D[101][10];


int main() {

	int N;
	long long sum = 0;
	cin >> N;

	for (int i = 0; i <= 9; i++)
		D[1][i] = 1;

	// D[계단 수 길이][마지막 숫자]
	for (int j = 2; j <= N; j++) {
		D[j][0] = D[j - 1][1];
		for (int i = 1; i < 9; i++) {
			D[j][i] = (D[j - 1][i - 1] + D[j - 1][i + 1]) % 1000000000;
		}
		D[j][9] = D[j - 1][8];
	}


	for (int i = 1; i <= 9; i++) {
		sum += D[N][i];
	}

	cout << sum % 1000000000;

	system("pause");
}
