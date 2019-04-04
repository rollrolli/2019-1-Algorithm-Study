#include <iostream>
using namespace std;


int tri[501][501];
int max_sum[501][501];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}


int main() {
	
	int n; // 삼각형의 크기



	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	max_sum[1][1] = tri[1][1];

	for (int i = 2; i <= n; i++) {
		max_sum[i][1] = max_sum[i - 1][1] + tri[i][1];
		max_sum[i][i] = max_sum[i - 1][i - 1] + tri[i][i];
		for (int j = 2; j <= i-1; j++) {
			max_sum[i][j] = max(max_sum[i - 1][j - 1], max_sum[i - 1][j]) + tri[i][j];
		}
	}

	int ans = -100;

	for (int i = 1; i <= n; i++) {
		if (ans < max_sum[n][i])
			ans = max_sum[n][i];
	}

	cout << ans;


	//system("pause");
}