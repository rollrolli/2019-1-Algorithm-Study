#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// 위 아래 왼쪽 오른쪽
int apartNum[10000];

int main() {

	int N;		// 지도의 크기
	queue<pair<int, int>> q;
	int num = 2;


	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;

			if (temp == '0') map[i][j] = 0;
			else map[i][j] = 1;

		}
	}



	while (1) {

		int flag = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					q.push(make_pair(i, j));
					map[i][j] = num;
					//cout << i << " " << j << " " << num << "\n";
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0) break;

		// 돌면서 하나라도 1인 아파트 찾으면 큐에 넣고 BFS 시작

		while (!q.empty()) {
			pair<int, int> t = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				if (t.first + dx[i] >= 0 && t.first + dx[i] < N &&
					t.second + dy[i] >= 0 && t.second + dy[i] < N &&
					map[t.first + dx[i]][t.second + dy[i]] == 1) {

					map[t.first + dx[i]][t.second + dy[i]] = num;
					// 처음 input의 1과 구별하기 위해 단지 id는 2부터
					q.push(make_pair(t.first + dx[i], t.second + dy[i]));
					//cout << t.first + dx[i] << " " << t.second + dy[i] << " " << num << "\n";
				}
			}

		}

		// 처음에 넣은 아파트가 속한 단지 BFS

		//cout << "------------------------\n";
		num++;
		// 단지 id 1씩 증가
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) {
				apartNum[map[i][j] - 1]++;
			}
		}
	}

	// 단지 id가 원래보다 하나씩 높게 저장되어 있으므로
	// 단지 수를 셀 때 1씩 빼줌
	

	sort(apartNum + 1, apartNum + num - 1);
	// 소팅은 1부터 단지 개수 N까지

	cout << num - 2 << "\n";
	// 단지 개수 N은 num - 2

	for (int i = 1; i < num - 1; i++) {
		cout << apartNum[i] << "\n";
	}

	system("pause");


}