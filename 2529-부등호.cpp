#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}


int main() {

	int k = 0;	// �ε�ȣ ������ ����
	char ineq[10];
	int num[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char temp;


	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> temp;
		ineq[i] = temp;
	}


	sort(num, num + 10, desc);
	// ������������ ����


	do {
		int isAns = 1;		// 1�̸� ���̶�� �ǹ�

		for (int i = 0; i < k; i++) {
			char c = ineq[i];
			if (c == '<') {
				if (num[i] > num[i + 1])
					isAns = 0;
			}	
			else if (c == '>') {
				if (num[i] < num[i + 1])
					isAns = 0;
			}
			// �ε�ȣ �� ������ isAns 0����
		}
		if (isAns == 1) break;
		// ���� �� �¾Ƽ� isAns 1�̸� ����
		
		// �������� �� �� prev_permutation ��
		// ���� ���� ������ �����ϴ� ���� �ִ�
	} while (prev_permutation(num, num + k + 1));
	


	for (int i = 0; i <= k; i++) {
		cout << num[i];
	}

	cout << "\n";



	sort(num, num + 10);

	do {
		int isAns = 1;		// 1�̸� ���̶�� �ǹ�

		for (int i = 0; i < k; i++) {
			char c = ineq[i];
			if (c == '<') {
				if (num[i] > num[i + 1])
					isAns = 0;
			}
			else if (c == '>') {
				if (num[i] < num[i + 1])
					isAns = 0;
			}
			// �ε�ȣ �� ������ isAns 0����
		}
		if (isAns == 1) break;

		// �������� �� �� next_permutation ��
		// ���� ���� ������ �����ϴ� ���� �ּڰ�
	} while (next_permutation(num, num + k + 1));


	for (int i = 0; i <= k; i++) {
		cout << num[i];
	}
	
	system("pause");
}