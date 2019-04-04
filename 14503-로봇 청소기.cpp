#include <iostream>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3


using namespace std;

int map[51][51];
// 청소 안된 곳 : 0
// 벽 : 1
// 청소 된 곳 : 2


int main() {
	
	int N, M;	// 3 이상 50 이하

	int r, c;	// 로봇청소기 처음 위치
	int d;		// 로봇청소기가 바라보고 있는 방향

	cin >> N >> M;

	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int clear = 0;

	while (1) {
		
		if (map[r][c] == 0) {
			clear++;
			/*
			cout << "(" << r << ", " << c << ")를 청소했습니다.\n";
			cout << "현재 방향은 ";
			if (d == NORTH) cout << "윗쪽";
			else if (d == EAST) cout << "오른쪽";
			else if (d == SOUTH) cout << "아랫쪽";
			else cout << "왼쪽";
			cout << "입니다\n";
			*/
		}
		map[r][c] = 2;



		
		if (map[r - 1][c] != 0 && map[r][c - 1] != 0 &&
			map[r][c + 1] != 0 && map[r + 1][c] != 0) {
			if (d == NORTH) {
				if (map[r + 1][c] == 1) {
					break;
				}
				else {
					r = r + 1;
				}
			}
			else if (d == EAST) {
				if (map[r][c - 1] == 1) {
					break;
				}
				else {
					c = c - 1;
				}
			}
			else if (d == SOUTH) {
				if (map[r - 1][c] == 1) {
					break;
				}
				else {
					r = r - 1;
				}
			}
			else if (d == WEST) {
				if (map[r][c + 1] == 1) {
					break;
				}
				else {
					c = c + 1;
				}
			}
		}
		else {
			if (d == NORTH) {
				if (map[r][c - 1] == 0) {
					c = c - 1;
				}
				d = WEST;
			}
			else if (d == EAST) {
				if (map[r - 1][c] == 0) {
					r = r - 1;
				}
				d = NORTH;
			}
			else if (d == SOUTH) {
				if (map[r][c + 1] == 0) {
					c = c + 1;
				}
				d = EAST;

			}
			else if (d == WEST) {
				if (map[r + 1][c] == 0) {
					r = r + 1;
				}
				d = SOUTH;
			}

		}
	}

	cout << clear << endl;

	system("pause");

}