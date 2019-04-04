#include <iostream>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3


using namespace std;

int map[51][51];
// û�� �ȵ� �� : 0
// �� : 1
// û�� �� �� : 2


int main() {
	
	int N, M;	// 3 �̻� 50 ����

	int r, c;	// �κ�û�ұ� ó�� ��ġ
	int d;		// �κ�û�ұⰡ �ٶ󺸰� �ִ� ����

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
			cout << "(" << r << ", " << c << ")�� û���߽��ϴ�.\n";
			cout << "���� ������ ";
			if (d == NORTH) cout << "����";
			else if (d == EAST) cout << "������";
			else if (d == SOUTH) cout << "�Ʒ���";
			else cout << "����";
			cout << "�Դϴ�\n";
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