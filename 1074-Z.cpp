#include <iostream>
#include <math.h>

using namespace std;


int main() {
	int N;
	long long r, c;
	long long result = 0;

	cin >> N >> r >> c;
	r++; c++;

	while (N != 0) {

		//cout << r << " " << c << "�� ";
		if (r <= pow(2, N - 1) && c <= pow(2, N - 1)) {	// 1��и�
			//cout << "1��и�\n";
		}
		else if (r <= pow(2, N - 1) && c > pow(2, N - 1)) { // 2��и�
			//cout << "2��и�\n";
			result += pow(2, N - 1) * pow(2, N - 1);
			c -= pow(2, N - 1);
		}
		else if (r > pow(2, N - 1) && c <= pow(2, N - 1)) {	// 3��и�
			//cout << "3��и�\n";
			result += 2 * pow(2, N - 1) * pow(2, N - 1);
			r -= pow(2, N - 1);
			
		}
		else {						// 4��и�
			//cout << "4��и�\n";
			result += 3 * pow(2, N - 1) * pow(2, N - 1);
			r -= pow(2, N - 1);
			c -= pow(2, N - 1);
		}
		N--;
	}

	cout << result;

	system("pause");
}