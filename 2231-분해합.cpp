#include <iostream>

using namespace std;

int main() {

	int N;
	int temp;
	int sum = 0;
	int exist = 0;

	cin >> N;

	for (int i = N - 70; i < N; i++) {
		sum += i;
		temp = i;
		for (int j = 0; j < 9; j++) {
			if (temp != 0) {
				sum += temp % 10;
				temp /= 10;
			}
			else break;
		}
		if (sum == N) {
			cout << i;
			exist = 1;
			break;
		}
		sum = 0;
	}
	if (exist == 0) cout << 0;

	system("pause");

}