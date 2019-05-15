#include <iostream>

using namespace std;

int main() {
	int T;
	int M, N;
	int x, y;

	ios_base::sync_with_stdio(0);

	cin.tie(0); //실행속도 향상

	cin >> T;

	while (T != 0) {
		int k = 0;
		int ans = -1;

		cin >> M >> N;
		cin >> x >> y;


		if (M < N) {
			for (int i = 0; i < N; i++) {
				if ((i*M + x) % N == y % N) {
					ans = i * M + x;
					break;
				}
			}
		}

		else {
			for (int i = 0; i < M; i++) {
				if ((i*N + y) % M == x % M) {
					ans = i * N + y;
					break;
				}
			}
		}

		/*while (i < M*N && j < M*N) {
			if (i % M == x && j % N == y) {
				ans = i;
				break;
			}
		
			i++; j++;
		
		}*/

		
		cout << ans << "\n";
	
	
		T--;
	}
	system("pause");

}