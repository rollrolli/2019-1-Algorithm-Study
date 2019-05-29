#include <iostream>
#include <algorithm>

using namespace std;

int result[10001];

void solution() {
	// 1
	result[1] = 1;

	// 1 1
	// 1+1		2
	result[2] = 2;

	// 1 1 1
	// 1+1+1	1+2		3
	result[3] = 3;

	// 1 1 1 1
	// 1+1+1+1	1+1+2	1+3		2+2
	result[4] = 4;

	// 1 1 1 1 1
	// 1+1+1+1+1	1+1+1+2		1+1+3	1+2+2	2+3
	result[5] = 1 + (result[3] - 1) + (result[2]);

	// 1 1 1 1 1 1
	// 1+1+1+1+1+1	1+1+1+1+2	1+1+2+2	1+1+1+3	1+2+3	3+3	2+2+2
	result[6] = 1 + (result[4] - 1) + result[3];

	//	1+1+1+1+1+1+1	1+1+1+1+1+2		1+1+1+2+2	1+2+2+2
	//	1+1+1+1+3		1+1+2+3			1+3+3		2+2+3
	result[7] = 1 + (result[5] - result[2]) + (result[4]);

	for (int n = 8; n <= 10000; n++) {
		result[n] = 1 + result[n - 2] - result[n - 5] + result[n - 3];
	}

}

int main() {
	
	int T;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	solution();

	for (int i = 0; i < T; i++) {
		int n;
		
		cin >> n;

		cout << result[n] << "\n";
	}
	system("pause");
}