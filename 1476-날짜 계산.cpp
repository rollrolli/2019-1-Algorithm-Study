#include <iostream>

using namespace std;

int main() {
	
	int E, S, M;
	int ans = 0;

	cin >> E >> S >> M;

	for (int i = 1; i <= 15*28*19; i++) {
		
		if (i % 15 == E % 15 && i % 28 == S % 28 && i % 19 == M % 19) {
			cout << i;
			break;
		}
	
	}

	system("pause");

}