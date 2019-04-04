#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int box[101][101][101];
int check[101][101][101];


int main() {
	int M, N, H;
	queue<tuple<int, int, int>> q;
	queue<int> day;
	
	cin >> M >> N >> H;

	int start_x = 0, start_y = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
					day.push(0);
				}
			}
		}
	}

	int d = 0;
	while (!q.empty()) {;
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		// row column height
		check[x][y][z] = 1;
		d = day.front();
		q.pop();
		day.pop();

		// 合率 沫
		if (x != 0 && check[x - 1][y][z] == 0 && box[x - 1][y][z] == 0) {
			q.push(make_tuple(x - 1, y, z));
			check[x - 1][y][z] = 1;
			//cout << x - 1 << y << z << " " << d << endl;
			day.push(d + 1);
		}
		// 巢率 沫
		if (x != N - 1 && check[x + 1][y][z] == 0 && box[x + 1][y][z] == 0) {
			q.push(make_tuple(x + 1, y, z));
			check[x + 1][y][z] = 1;
			//cout << x + 1 << y << z << " " << d << endl;
			day.push(d + 1);
		}
		// 辑率 沫
		if (y != 0 && check[x][y - 1][z] == 0 && box[x][y - 1][z] == 0) {
			q.push(make_tuple(x, y - 1, z));
			check[x][y - 1][z] = 1;
			//cout << x << y - 1 << z << " " << d << endl;
			day.push(d + 1);
		}
		// 悼率 沫
		if (y != M - 1 && check[x][y + 1][z] == 0 && box[x][y + 1][z] == 0) {
			q.push(make_tuple(x, y + 1, z));
			check[x][y + 1][z] = 1;
			//cout << x << y + 1 << z  << " " << d << endl;
			day.push(d + 1);
		}
		// 拉率 沫
		if (z != 0 && check[x][y][z - 1] == 0 && box[x][y][z - 1] == 0) {
			q.push(make_tuple(x, y, z - 1));
			check[x][y][z - 1] = 1;
			//cout << x << y << z - 1 << " " << d << endl;
			day.push(d + 1);
		}
		// 酒阀率 沫
		if (z != H - 1 && check[x][y][z + 1] == 0 && box[x][y][z + 1] == 0) {
			q.push(make_tuple(x, y, z + 1));
			check[x][y][z + 1] = 1;
			//cout << x << y << z+1 << " " << d << endl;
			day.push(d + 1);
		}
	}
	int flag = 0;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j][k] == 0 && check[i][j][k] == 0) {
					flag = 1;
				}
			}
		}
	}
	
	if (flag == 1) cout << "-1";
	else cout << d;
	
	system("pause");
}