#include <iostream>

using namespace std;

long long total[1000001];
// �� �渶�� ������ ��

int main() {

	long long N;			// �� ����
	long long B, C;		// �ְ����� ���� ����, �ΰ����� ���� ����
	
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