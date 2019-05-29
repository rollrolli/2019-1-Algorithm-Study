#include <iostream>

using namespace std;

int map[100][100];
long long result[100][100];


long long solution(int N) {

	result[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) return result[N - 1][N - 1];
			// �̰� �����ָ� �������� �� result[N - 1][N - 1]�� 0�� �ƴϹǷ�
			// ���� if�� �ɷ��� �� ������
			if (result[i][j]) {
				int dist = map[i][j];
				if (i + dist < N) result[i + dist][j] += result[i][j];
				if (j + dist < N) result[i][j + dist] += result[i][j];
			}
		}
	}



}

int main() {

	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}


	cout << solution(N);

	system("pause");
}