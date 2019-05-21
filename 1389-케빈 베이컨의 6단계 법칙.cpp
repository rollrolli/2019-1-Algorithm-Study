#include <iostream>
#include <algorithm>

using namespace std;

int adj[100][100];
int kb[100];

int main() {

	int N;		// 유저의 수
	int M;		// 친구 관계의 수

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int t1, t2;

		cin >> t1 >> t2;
		t1 -= 1;	t2 -= 1;
		adj[t1][t2] = 1;
		adj[t2][t1] = 1;
	}
	for (int k = 0; k < N; k++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j && adj[i][j] != 0 && adj[i][k] != 0 && adj[k][j] != 0)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				else if (i != j && adj[i][k] != 0 && adj[k][j] != 0)
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
	int min = 100000;
	int minNum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			kb[i] += adj[i][j];
		}
		if (min > kb[i]) {
			min = kb[i];
			minNum = i;
		}
	}

	cout << minNum + 1;

	system("pause");
	
	

}