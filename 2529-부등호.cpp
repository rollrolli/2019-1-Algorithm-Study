#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}


int main() {

	int k = 0;	// 부등호 문자의 개수
	char ineq[10];
	int num[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char temp;


	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> temp;
		ineq[i] = temp;
	}


	sort(num, num + 10, desc);
	// 내림차순으로 정렬


	do {
		int isAns = 1;		// 1이면 답이라는 의미

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
			// 부등호 안 맞으면 isAns 0으로
		}
		if (isAns == 1) break;
		// 전부 다 맞아서 isAns 1이면 멈춤
		
		// 내림차순 한 후 prev_permutation 중
		// 가장 먼저 조건을 만족하는 값이 최댓값
	} while (prev_permutation(num, num + k + 1));
	


	for (int i = 0; i <= k; i++) {
		cout << num[i];
	}

	cout << "\n";



	sort(num, num + 10);

	do {
		int isAns = 1;		// 1이면 답이라는 의미

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
			// 부등호 안 맞으면 isAns 0으로
		}
		if (isAns == 1) break;

		// 오름차순 한 후 next_permutation 중
		// 가장 먼저 조건을 만족하는 값이 최솟값
	} while (next_permutation(num, num + k + 1));


	for (int i = 0; i <= k; i++) {
		cout << num[i];
	}
	
	system("pause");
}