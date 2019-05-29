#include <iostream>
#include <algorithm>

using namespace std;

int result[11];

void solution() {
	
	// n�� 1�� ��
	result[1] = 1;

	// n�� 2�� ��
	//	2				1+1
	result[2] = 2;

	// n�� 3�� ��
	//	2+1				1+1+1
	//	3				1+2
	result[3] = 4;

	// n�� 4�� ��
	// 3+1		1+2+1		2+1+1		1+1+1+1
	//			1+3			2+2			1+1+2
	result[4] = 7;

	// n�� 5�� ��
	// 1+3+1	2+2+1	3+1+1	1+1+2+1	1+2+1+1	2+1+1+1	1+1+1+1+1
	//			2+3		3+2		1+1+3	1+2+2	2+1+2	1+1+1+2
	for (int n = 5; n < 11; n++) {
		result[n] = 2 * result[n - 1] - result[n - 4];
	}
	// n�� 6�� ��
	// 1+1+1+1+1+1		1
	// 1+1+1+1+2		5
	// 1+1+2+2			6
	// 2+2+2			1
	// 1+1+1+3			4
	// 1+2+3			6
	// 3+3				1
	//					24



}



int main() {
	int T;

	cin >> T;

	solution();


	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		cout << result[n] << "\n";


	}
	system("pause");

}