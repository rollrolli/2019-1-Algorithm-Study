#include <iostream>

using namespace std;

int result[1000001] = { 0, };

int min(int a, int b) {
	if (a > b) return b;
	else return a;

}


int main() {
	
	int N;
	
	cin >> N;
	

	for (int i = 2; i <= 1000000; i++) {
		if (i % 3 == 0 && i % 2 == 0)
			result[i] = min(result[i / 3] + 1, result[i / 2] + 1);
		else if (i % 3 == 0)
			result[i] = min(result[i / 3] + 1, result[i - 1] + 1);
		else if (i % 2 == 0)
			result[i] = min(result[i / 2] + 1, result[i - 1] + 1);
		else
			result[i] = result[i - 1] + 1;
	}
	

	cout << result[N];

	system("pause");
}
