#include <iostream>
#include <stack>

using namespace std;

int check[10];
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
		if (check[i] == 1) continue;
		check[i] = 1;
		s[index] = i;
		solve(N, M, index + 1);
		check[i] = 0;
	}

}



int main() {

	int N, M;

	cin >> N >> M;

	solve(N, M, 0);


	system("pause");

}