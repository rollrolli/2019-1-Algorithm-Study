#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else { return b; }
}


int main() {

	int N;
	int step[301] = { 0, };
	int score[301][2] = { 0, };
	int flag[301] = { 0, };


	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> step[i];
	}

	int bigger = 0;

	score[1][0] = step[1];
	score[2][0] = score[1][0] + step[2];
	flag[2] = 1;
	score[2][1] = step[2];
	

	for (int i = 3; i <= N; i++) {
		// 바로 전 계단에서 올라오는 경우
		if (score[i - 1][0] > score[i - 1][1] && flag[i - 1] < 1) {
			flag[i] = flag[i-1]+1;
			score[i][0] = score[i - 1][0] + step[i];
			
		}

		else if (score[i - 1][0] > score[i - 1][1] && flag[i - 1] == 1) {
			flag[i] = 1;
			score[i][0] = score[i - 1][1] + step[i];
			
		}

		else if (score[i - 1][0] <= score[i - 1][1]) {
			flag[i] = 1;
			score[i][0] = score[i - 1][1] + step[i];
			
		}
		// 두 개 아래 계단에서 올라오는 경우
		if (score[i - 2][0] > score[i - 2][1]) {
			score[i][1] = score[i - 2][0] + step[i];
			
		}
		else if (score[i - 2][0] <= score[i - 2][1]) {
			score[i][1] = score[i - 2][1] + step[i];
			
		}
		

	}
	
	cout << max(score[N][0], score[N][1]);

	system("pause");
}