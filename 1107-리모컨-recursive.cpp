#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


int button[12] ={1,1,1,1,1,1,1,1,1,1,1,1};	// 0 ~ 9, +, -

int result = 0;

void channelChange(int channel, int curr, int ans) {
	int direct = 1;
	int chan = channel;
	int digit = 1;

	//cout << channel << " " << curr << " " << ans << "\n";
	cout << "���� ä���� " << channel << "\n";
	for (int i = chan % 10; chan != -1 ;) {
		if (!button[i]) {
			direct = 0;
			break;
		}

		if (chan / 10 != 0) { 
			chan /= 10;
			i = chan % 10;
			digit++;
		}
		else break;
	}
	
	if (curr == channel) {
		result = ans;
		return;
	}

	if (direct) {		// channel �ٷ� �� �� ����
		result = ans + digit;
		return;
	}
	else {
		if (button[10] && result == 0)
			channelChange(channel - 1, curr, ans + 1);
		if (button[11] && result == 0 && channel != 500000)
			channelChange(channel + 1, curr, ans + 1);
	}

}





int main() {
	
	int N;		// �̵��Ϸ��� �ϴ� ä��
	int M;		// ���峭 ��ư�� ����
	


	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		char temp;
		cin >> temp;
		if (temp == '+') button[10] = 0;
		else if (temp == '-') button[11] = 0;
		else button[temp - '0'] = 0;
	}

	channelChange(N, 100, 0);

	cout << result;

	system("pause");
}