#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[8][8];
int map2[8][8];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	
	int N;		// 세로 크기
	int M;		// 가로 크기
	queue<pair<int, int>> q;
	int vac = 0;		// 빈칸 개수
	int max = 0;


	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			map2[i][j] = map[i][j];
			if (map[i][j] == 2)
				q.push(make_pair(i, j));
			else if (map[i][j] == 0) vac++;
		}
	}



	int perm[100] = { 0, };
	perm[0] = 1;
	perm[1] = 1;
	perm[2] = 1;

	do {
		int permIdx = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					if (perm[permIdx] == 1) {
						map2[i][j] = 1;
						//cout << "벽 세운 곳 : (" << i << ", " << j << ")\n";
						permIdx++;
					}
					else permIdx++;
				}
			}
		}

		while (!q.empty()) {
			pair<int, int> t = q.front();
			q.pop();

			int x = t.first;
			int y = t.second;
			for (int i = 0; i < 4; i++) {
				if (x + dx[i] >= 0 && x + dx[i] < N &&
					y + dy[i] >= 0 && y + dy[i] < M &&
					map2[x + dx[i]][y + dy[i]] == 0) {
					q.push(make_pair(x + dx[i], y + dy[i]));
					map2[x + dx[i]][y + dy[i]] = 2;
				}
			}		
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map2[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/

		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map2[i][j] == 0) {
					sum++;
				}
			}
		}

		if (max < sum) max = sum;



		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map2[i][j] = map[i][j];
				if (map[i][j] == 2) {
					q.push(make_pair(i, j));
				}
			}
		}

	
	} while (prev_permutation(perm, perm + vac));
	
	cout << max;
	system("pause");
		 
}