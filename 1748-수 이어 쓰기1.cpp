#include <iostream>
#include <math.h>

using namespace std;

int main() {

	long long N;
	long long NN;
	int digit = 0;
	long long result = 0;
	long long temp = 0;

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;
	NN = N;

	for (int i = 1; i < 20; i++) {
		digit++;
		N /= 10;
		if (N == 0) break;
	}	// ��� 10���� �����༭ �ڸ��� ���ϱ�


	for (int i = 1; i < digit; i++) {
		result += i * 9 * pow(10, i - 1); 
		temp += 9 * pow(10, i - 1);
	}	
	// �ڸ��� - 1������ ��� ���� �ڸ����� result�� ������
	// temp�� ������ ������ ������ ��� ���ؼ� input���� ���� ��
	// ������ ������ �ϱ� ����

	result += (NN - temp) * digit;
	// input���� temp�� �� �������� input�� �ڸ����� �ڸ����� ����
	// �����̹Ƿ� �� ������ result�� ������

	cout << result;

	system("pause");

}