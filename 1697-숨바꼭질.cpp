#include <iostream>
#include <queue>

using namespace std;

int check[100001];

int main() {

	int N;		// 수빈 위치
	int K;		// 동생 위치
	queue<int> q;


	cin >> N >> K;

	for (int i = 0; i < 100001; i++) {
		check[i] = -1;
	}

	q.push(N);
	check[N] = 0;
	
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		if (temp == K) {
			break;
		}

		if ( temp - 1 >= 0 && check[temp - 1] == -1) {
			q.push(temp - 1);
			check[temp - 1] = check[temp] + 1;
			if (temp - 1 == K) break;
		}
		if (temp + 1 <= 100000 && check[temp + 1] == -1) {
			q.push(temp + 1);
			check[temp + 1] = check[temp] + 1;
			if (temp + 1 == K) break;
		}
		if (temp * 2 <= 100000 && check[temp * 2] == -1) {
			q.push(temp * 2);
			check[temp * 2] = check[temp] + 1;
			if (temp * 2 == K) break;
		}


	}
	
	cout << check[K];

	system("pause");
}