#include <iostream>
#include <vector>
#include <string>

using namespace std;



void move(int N, int from, int to) {
	cout << from << " " << to << "\n";
}


void solve(int N, int n, int from, int by, int to) {

	// ������ ���� ���
	if (n == 1) {
		move(N, from, to);
	}

	// ���� ��� ���ȣ��
	else {
		solve(N, n - 1, from, to, by);
		move(N, from, to);
		solve(N, n - 1, by, from, to);
	}
}


string bigNumAdd(string num1, string num2)
{
	long long sum = 0;
	string result;
	string _result;

	//1�� �ڸ����� ���ϱ� �����Ѵ�
	while (!num1.empty() || !num2.empty() || sum)
	{
		if (!num1.empty())
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty())
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}
		//�ٽ� string ���·� ����� push_back
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	for (int i = 0; i < result.length(); i++)
	{
		char temp;
		temp = result[result.length() - i - 1];
		_result.push_back(temp);
	}
	return _result;
}

int main() {
	int N;		// ������ ����
	string result = "1";
	cin >> N;
	long long K = 1;

	if (N <= 20) {
		for (int i = 0; i < N; i++)
			K *= 2;
		K -= 1;
		cout << K << "\n";

		solve(N, N, 1, 2, 3);
		
	}

	else {
		// 2^N �����
		for (int i = 0; i < N; i++)
			result = bigNumAdd(result, result);

		// 2^N ���� 1 ����
		char temp = result.back();
		result.pop_back();
		result.push_back(temp - 1);

		cout << result;

	}

	system("pause");

}