#include <iostream>
#include <stack>

using namespace std;

int s[10];

void solve(int N, int M, int index) {

	if (index == M) {	// 끝까지 다 옴!
		for (int i = 0; i < M; i++) {
			cout << s[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (s[index - 1] <= i) {
			s[index] = i;
			solve(N, M, index + 1);
		}
	}

}



int main() {

	int N, M;

	cin >> N >> M;

	solve(N, M, 0);


	system("pause");

}