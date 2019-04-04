#include <iostream>
#include <algorithm>

using namespace std;

int perm[10001];

int main() {

	int N; // 1 이상 10000 이하

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> perm[i];
	}

	if (prev_permutation(perm, perm + N) == true) {

		for (int i = 0; i < N; i++) {
			cout << perm[i] << " ";
		}
	}
	else cout << "-1";

	system("pause");
}