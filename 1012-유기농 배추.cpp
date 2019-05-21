#include <iostream>
#include <queue>

using namespace std;

int map[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	
	int T;
	int M, N, K;
	queue<pair<int, int>> q;

	cin >> T;

	while (T != 0) {

		cin >> M >> N >> K;

		int ans = 0;

		for (int i = 0; i < K; i++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			map[temp1][temp2] = 1;
		}



		while (1) {
			int flag = 0;
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] == 1) {
						flag = 1;
						q.push(make_pair(i, j));
						map[i][j] = 2;
						break;
					}
				}
				if (flag == 1) break;
			}
			if (flag == 0) break;

			while (!q.empty()) {
				pair<int, int> t = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					if (t.first + dx[i] >= 0 && t.first + dx[i] < M &&
						t.second + dy[i] >= 0 && t.second + dy[i] < N &&
						map[t.first + dx[i]][t.second + dy[i]] == 1) {

						q.push(make_pair(t.first + dx[i], t.second + dy[i]));
						map[t.first + dx[i]][t.second + dy[i]] = 2;
					}
				}



			}


			ans++;

		}
		cout << ans << "\n";


		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
			}
		} // 배추밭 초기화


		T--;
	}

	system("pause");

}