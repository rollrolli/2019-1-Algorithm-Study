#include <iostream>

using namespace std;

int seq[2000];
int result[2000][2000];

void solution(int N) {

	// ���� 1�� ���� 2�� �� ���ÿ� ����
	for (int i = 0; i < N; i++) {
		result[i][i] = 1;
		if (i + 1 < N && seq[i] == seq[i + 1]) result[i][i + 1] = 1;
	}

	// ���̰� 3 �̻��� �� S���� E���� �Ӹ�������� Ȯ��
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
		// �迭�� index�� ����� ���̹Ƿ� 1�� ����
		if (result[S][E] == -1)
			cout << 0 << "\n";
		else cout << 1 << "\n";
	}

	system("pause");


}