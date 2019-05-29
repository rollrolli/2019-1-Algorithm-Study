#include <iostream>

using namespace std;

int seq[2000];
int result[2000][2000];

void solution(int N) {

	// 길이 1일 때와 2일 때 동시에 봐줌
	for (int i = 0; i < N; i++) {
		result[i][i] = 1;
		if (i + 1 < N && seq[i] == seq[i + 1]) result[i][i + 1] = 1;
	}

	// 길이가 3 이상일 때 S부터 E까지 팰린드롬인지 확인
	for (int dist = 3; dist <= N; dist++) {
		for (int S = 0; S < N; S++) {
			int E = S + dist - 1;
			if (result[S + 1][E - 1] == 1 && seq[S] == seq[E]) {
				result[S][E] = 1;
			}
		}
	}


	
	
}

int main() {
	int N;
	int M;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result[i][j] = -1;
		}
	}


	solution(N);

	cin >> M;


	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		S--; E--;
		// 배열의 index로 사용할 것이므로 1씩 빼줌
		if (result[S][E] == -1)
			cout << 0 << "\n";
		else cout << 1 << "\n";
	}

	system("pause");


}