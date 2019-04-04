#include <iostream>
#include <queue>

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

using namespace std;

typedef struct {
	int x;
	int y;
} loc;


int field[101][101];


int main() {

	int N;

	int x[101], y[101], d[101], g[101];
	// x : 시작점 x좌표 0 <= x <= 100
	// y : 시작점 y좌표 0 <= y <= 100
	// d : 시작 방향	0 <= d <= 3
	// g : 세대			0 <= g <= 10

	queue<loc> end;		// 끝점
	queue<loc> q;		// 90도 돌릴 점들
	queue<int> gen;	// 바로 전 세대 점들



	cin >> N;
	
	
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i] >> d[i] >> g[i];
	}
	for (int i = 0; i < N; i++) {
		loc gen0_a, gen0_b;
		gen0_a.x = x[i];
		gen0_a.y = y[i];

		if (d[i] == RIGHT) {
			gen0_b.x = x[i] + 1;
			gen0_b.y = y[i];
		}
		else if (d[i] == UP) {
			gen0_b.x = x[i];
			gen0_b.y = y[i] - 1;
		}
		else if (d[i] == LEFT) {
			gen0_b.x = x[i] - 1;
			gen0_b.y = y[i];
		}
		else if (d[i] == DOWN) {
			gen0_b.x = x[i];
			gen0_b.y = y[i] + 1;
		}

		q.push(gen0_b);
		q.push(gen0_a);

		end.push(gen0_b);
		end.push(gen0_b);

		gen.push(0);
		gen.push(0);

		int generation = 1;


		// n세대 드래곤 커브 그리기 (n >= 1)
		while (generation <= g[i]) {
			loc point = q.front(); q.pop();
			loc endPoint = end.front(); end.pop();
			int gg = gen.front();  gen.pop();

			loc newPoint;

			if (endPoint.x != point.x || endPoint.y != point.y) {

				newPoint.x = endPoint.x + (endPoint.y - point.y);
				newPoint.y = endPoint.y + (point.x - endPoint.x);

				q.push(newPoint);
				gen.push(generation);

				q.push(point);
				gen.push(generation);

			}
			else {
				q.push(point);

			}


			if (point.x == x[i] && point.y == y[i]) {
				generation++;
				if (generation > g[i]) break;
				for (int i = 0; i < q.size(); i++)
					end.push(newPoint);

				// 시작점을 돌린 점이 매 세대의 끝 점이므로
				// 그 점을 end 큐에 왕창 집어넣는다... 
			}

		}


		while (!q.empty()) {
			loc point = q.front(); q.pop();
			if (point.x <= 100 && point.y <= 100)
				field[point.x][point.y] = 1;
			// cout << "(" << point.x << ", " << point.y<< ")" << endl;
		}
		queue<loc> temp1;
		queue<loc> temp2;
		queue<int> temp3;

		q = temp1;
		end = temp2;
		gen = temp3;
	}

	int ans = 0;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (i + 1 <= 100 && j + 1 <= 100
				&& field[i][j] == 1 && field[i][j + 1] == 1
				&& field[i + 1][j] == 1 && field[i + 1][j + 1] == 1) {
				ans++;
				// cout << "(" << i - 50 << ", " << j- 50 << ")" << endl;
			}
		}
	}

	cout << ans;



	system("pause");
}