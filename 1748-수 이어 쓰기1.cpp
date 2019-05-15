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
	}	// 계속 10으로 나눠줘서 자리수 구하기


	for (int i = 1; i < digit; i++) {
		result += i * 9 * pow(10, i - 1); 
		temp += 9 * pow(10, i - 1);
	}	
	// 자리수 - 1까지인 모든 수의 자리수를 result에 더해줌
	// temp는 더해준 수들의 개수를 모두 구해서 input에서 빼준 후
	// 마지막 연산을 하기 위함

	result += (NN - temp) * digit;
	// input에서 temp를 뺀 나머지는 input의 자리수와 자리수가 같은
	// 수들이므로 이 값들을 result에 더해줌

	cout << result;

	system("pause");

}