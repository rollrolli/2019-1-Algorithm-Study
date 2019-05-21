#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// �� �Ʒ� ���� ������
int apartNum[10000];

int main() {

	int N;		// ������ ũ��
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

		// ���鼭 �ϳ��� 1�� ����Ʈ ã���� ť�� �ְ� BFS ����

		while (!q.empty()) {
			pair<int, int> t = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				if (t.first + dx[i] >= 0 && t.first + dx[i] < N &&
					t.second + dy[i] >= 0 && t.second + dy[i] < N &&
					map[t.first + dx[i]][t.second + dy[i]] == 1) {

					map[t.first + dx[i]][t.second + dy[i]] = num;
					// ó�� input�� 1�� �����ϱ� ���� ���� id�� 2����
					q.push(make_pair(t.first + dx[i], t.second + dy[i]));
					//cout << t.first + dx[i] << " " << t.second + dy[i] << " " << num << "\n";
				}
			}

		}

		// ó���� ���� ����Ʈ�� ���� ���� BFS

		//cout << "------------------------\n";
		num++;
		// ���� id 1�� ����
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) {
				apartNum[map[i][j] - 1]++;
			}
		}
	}

	// ���� id�� �������� �ϳ��� ���� ����Ǿ� �����Ƿ�
	// ���� ���� �� �� 1�� ����
	

	sort(apartNum + 1, apartNum + num - 1);
	// ������ 1���� ���� ���� N����

	cout << num - 2 << "\n";
	// ���� ���� N�� num - 2

	for (int i = 1; i < num - 1; i++) {
		cout << apartNum[i] << "\n";
	}

	system("pause");


}