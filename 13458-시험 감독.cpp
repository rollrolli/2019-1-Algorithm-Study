#include <iostream>

using namespace std;

long long total[1000001];
// 각 방마다 응시자 수

int main() {

	long long N;			// 방 개수
	long long B, C;		// 주감독관 감시 가능, 부감독관 감시 가능
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> total[i];
	}
	cin >> B >> C;
	
	
	long long ans = 0;

	for (int i = 0; i < N; i++) {
		if (total[i] - B >= 0) {
			if ((total[i] - B) % C == 0)
				ans += (total[i] - B) / C + 1;
			else
				ans += (total[i] - B) / C + 2;
		}
		else
			ans += 1;
	}
	
	cout << ans;

	system("pause");

}