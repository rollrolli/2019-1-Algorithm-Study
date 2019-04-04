#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int perm[9] = { 0, };


	cin >> N;


	for (int i = 1; i <= N; i++) {
		perm[i - 1] = i;
		cout << perm[i - 1] << " ";
	}
	cout << "\n";
	while (1) {
		if (next_permutation(perm, perm + N) == true) {
			for (int i = 0; i < N; i++) {
				cout << perm[i] << " ";
			}
			cout << "\n";
		}
		// endl은 flush를 겸하기 때문에 매우 느림
		// 대신 "\n"을 쓰는 습관을 들여야겠다!
		else break;
	}
	system("pause");
}