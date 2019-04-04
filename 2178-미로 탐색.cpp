#include <iostream>
#include <queue>

using namespace std;

char maze[101][101];
int check[101][101];

int main() {
	
	int N, M;
	queue<pair<int, int>> q;
	
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}

	q.push(make_pair(0, 0));
	check[0][0] = 1;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (maze[x - 1][y] == '1' && check[x - 1][y] == 0) {
			q.push(make_pair(x - 1, y));
			check[x - 1][y] = check[x][y] + 1;
		}
		if (maze[x + 1][y] == '1' && check[x + 1][y] == 0) {
			q.push(make_pair(x + 1, y));
			check[x + 1][y] = check[x][y] + 1;
		}
		if (maze[x][y - 1] == '1' && check[x][y - 1] == 0) {
			q.push(make_pair(x, y - 1));
			check[x][y - 1] = check[x][y] + 1;
		}
		if (maze[x][y + 1] == '1' && check[x][y + 1] == 0) {
			q.push(make_pair(x, y + 1));
			check[x][y + 1] = check[x][y] + 1;
		}
	}

	

	cout << check[N - 1][M - 1] ;

	system("pause");

}