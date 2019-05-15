#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;


int button[10] ={1,1,1,1,1,1,1,1,1,1};	// 0 ~ 9



int possible[1000010];

int solution(int N) {
	int up = N;
	int down = N;
	int ans = 0;
	int flag = 0;
	
	while (flag == 0) {
		//cout << "up :" << up << ", down : " << down << "\n";
		//cout << "possible[up] :" << possible[up] << ", possible[down] : " << possible[down] << "\n";
		
		if (up == 100) {
			ans = 100 - N;
			flag = 1;
		}
		if (possible[up] != -1) {
			if (flag == 1) ans = min(ans, possible[up] + (up - N));
			else ans = possible[up] + up - N;
			flag = 1;

			if (ans > 100 - N && 100 - N >= 0) ans = 100 - N;
		}
		else up++;


		if (down == 100) {
			ans = N - 100;
			flag = 1;
		}
		if (possible[down] != -1) {
			if (flag == 1) ans = min (ans, possible[down] + (N - down));
			else ans = possible[down] + N - down;
			flag = 1;

			if (ans > N - 100 && N - 100 >= 0) ans = N - 100;

		}
		else if (down > 0) down--;

		
	}

	return ans;

}


void check() {		// ���� ��ư���� �������� ��� üũ

	for (int channel = 0; channel < 1000010; channel++) {
		int temp = channel;
		for (int i = temp % 10;;) {
			i = temp % 10;
			if (!button[i]) {
				possible[channel] = -1;		// �Ұ���
				break;
			}

			else {
				possible[channel]++;
			}

			if (temp/10) temp /= 10;
			else {
				break;
			}
		}
		//cout << "possible[" << channel << "] = " << possible[channel] << "\n";

	}

}


int main() {
	
	int N;		// �̵��Ϸ��� �ϴ� ä��
	int M;		// ���峭 ��ư�� ����


	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		char temp;
		cin >> temp;
		button[temp - '0'] = 0;
	}
	check();
	


	cout << solution(N);

	system("pause");
}