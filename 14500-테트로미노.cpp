#include <iostream>

using namespace std;

int field[501][501];

int main() {
	int N, M; // 4 이상 500 이하

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> field[i][j];
		}
	}

	// XXXX

	int temp_ans = -10;
	int sum = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j + 3 < M 
				&& (sum = field[i][j] + field[i][j + 1] + field[i][j + 2] + field[i][j + 3]) > temp_ans) {
				temp_ans = sum;
			}
		}
	
	}

	// X
	// X
	// X
	// X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 3 < N
				&& (sum = field[i][j] + field[i + 1][j] + field[i + 2][j] + field[i + 3][j]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	// X
	// X
	// XX

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 2 < N && j + 1 < M
				&& (sum = field[i][j] + field[i + 1][j] + field[i + 2][j] + field[i + 2][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	//  X
	//  X
	// XX

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - 2 >= 0 && j + 1 < M
				&& (sum = field[i][j] + field[i][j + 1] + field[i - 1][j + 1] + field[i - 2][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}


	// X
	// XXX

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 1 < N && j + 2 < M
				&& (sum = field[i][j] + field[i + 1][j] + field[i + 1][j + 1] + field[i + 1][j + 2]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	//   X
	// XXX

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - 1 >= 0 && j + 2 < M
				&& (sum = field[i][j] + field[i][j + 1] + field[i][j + 2] + field[i - 1][j + 2]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}


	// XX
	//  X
	//  X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 2 < N && j + 1 < M
				&& (sum = field[i][j] + field[i][j + 1] + field[i + 1][j + 1] + field[i + 2][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	// XX
	// X
	// X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 2 < N && j + 1 < M
				&& (sum = field[i][j] + field[i + 1][j] + field[i + 2][j] + field[i][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	// XXX
	// X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 1 < N && j + 2 < M
				&& (sum = field[i][j] + field[i + 1][j] + field[i][j + 1] + field[i][j + 2]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	// XXX
	//   X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 1 < N && j + 2 < M
				&& (sum = field[i][j] + field[i][j + 1] + field[i][j + 2] + field[i + 1][j + 2]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	// X
	// XX
	//  X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 2 < N && j + 1 < M
				&& (sum = field[i][j] + field[i + 1][j] + field[i + 1][j + 1] + field[i + 2][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	//  X
	// XX
	// X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - 2 >= 0 && j + 1 < M
				&& (sum = field[i][j] + field[i - 1][j] + field[i - 1][j + 1] + field[i - 2][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	//  XX
	// XX


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - 1 >= 0 && j + 2 < M
				&& (sum = field[i][j] + field[i][j + 1] + field[i - 1][j + 1] + field[i - 1][j + 2]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	// XX
	//  XX

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 1 < N && j + 2 < M
				&& (sum = field[i][j] + field[i][j + 1] + field[i + 1][j + 1] + field[i + 1][j + 2]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}



	// XXX
	//  X
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 1 < N && j + 2 < M
				&& (sum = field[i][j] + field[i][j + 1] + field[i][j + 2] + field[i + 1][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	//  X
	// XXX
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - 1 >= 0 && j + 2 < M
				&& (sum = field[i][j] + field[i][j + 1] + field[i][j + 2] + field[i - 1][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}


	// X
	// XX
	// X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 2 < N && j + 1 < M
				&& (sum = field[i][j] + field[i + 1][j] + field[i + 2][j] + field[i + 1][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}


	//  X
	// XX
	//  X

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 2 < N && j - 1 >= 0
				&& (sum = field[i][j] + field[i + 1][j] + field[i + 2][j] + field[i + 1][j - 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}


	// XX
	// XX

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 1 < N && j + 1 < M
				&& (sum = field[i][j] + field[i + 1][j] + field[i][j + 1] + field[i + 1][j + 1]) > temp_ans) {
				temp_ans = sum;
			}
		}
	}

	cout << temp_ans;

	system("pause");

}