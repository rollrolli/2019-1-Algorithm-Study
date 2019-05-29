#include <iostream>


using namespace std;

int maze[1000][1000];
int memo[1000][1000][3];
int result[1000][1000];

int max(int a, int b, int c) {
	return a > b ? a : (b > c ? b : c);
}
int max(int a, int b) {
	return a > b ? a : b;
}

int solution(int N, int M) {

	result[0][0] = maze[0][0];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - 1 >= 0 && j - 1 >= 0) {
				result[i][j] =
					max(result[i - 1][j], result[i][j - 1], result[i - 1][j - 1])
					+ maze[i][j];
			}	// 세 방향의 값 중 가장 큰 쪽에서 온 거...
			else if (i - 1 >= 0) {
				result[i][j] =
					result[i - 1][j]
					+ maze[i][j];
			}	// j가 0일 때는 왼쪽에서밖에...
			else if (j - 1 >= 0) {
				result[i][j] =
					result[i][j - 1]
					+ maze[i][j];
			}	// i가 0일 때는 윗쪽에서밖에...
		}
	}

	return result[N - 1][M - 1];
	

}


int main() {

	int N, M;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}


	cout << solution(N, M);

	system("pause");

	

}