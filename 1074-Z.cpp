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

		//cout << r << " " << c << "은 ";
		if (r <= pow(2, N - 1) && c <= pow(2, N - 1)) {	// 1사분면
			//cout << "1사분면\n";
		}
		else if (r <= pow(2, N - 1) && c > pow(2, N - 1)) { // 2사분면
			//cout << "2사분면\n";
			result += pow(2, N - 1) * pow(2, N - 1);
			c -= pow(2, N - 1);
		}
		else if (r > pow(2, N - 1) && c <= pow(2, N - 1)) {	// 3사분면
			//cout << "3사분면\n";
			result += 2 * pow(2, N - 1) * pow(2, N - 1);
			r -= pow(2, N - 1);
			
		}
		else {						// 4사분면
			//cout << "4사분면\n";
			result += 3 * pow(2, N - 1) * pow(2, N - 1);
			r -= pow(2, N - 1);
			c -= pow(2, N - 1);
		}
		N--;
	}

	cout << result;

	system("pause");
}