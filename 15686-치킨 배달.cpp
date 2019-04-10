#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int city[51][51];
int visited[51][51] = { 0, };	// 매 서칭마다 초기화 필요
int comb[15] = { 0, };

typedef struct loc {
	int r;
	int s;
};


loc store[15];
loc house[101];

int store_num = 0;		// 치킨집 개수
int house_num = 0;		// 가정집 개수

int N, M;


queue<loc> house_q;
queue<loc> q;



int getDistance(loc a, loc b) {
	return (a.r - b.r >= 0 ? a.r - b.r : b.r - a.r) +
		(a.s - b.s >= 0 ? a.s - b.s : b.s - a.s);
}

int getChickenDistance(int* comb) {
	int min = 100000;
	int sum = 0;
	int temp = 0;

	for (int i = 0; i < house_num; i++) {
		min = 100000;
		for (int j = 0; j < store_num; j++) {
			if (comb[j] == 1) {
				temp = getDistance(house[i], store[j]);
			
				if (min > temp) min = temp;
			}
		}
		sum += min;
	}

	return sum;
}


int main() {


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) {
				store[store_num].r = i;
				store[store_num++].s = j;
			}
			else if (city[i][j] == 1) {
				house[house_num].r = i;
				house[house_num++].s = j;
			}
		}
	}

	//////////////////////////////////////////////////////
	for (int i = store_num - 1; i >= 0 ; i--) {
		if (i < M) comb[i] = 1;
		else comb[i] = 0;
	}
	sort(comb, comb + store_num);
	//////////////////////////////////////////////////////
	// 조합 사용을 위한 밑작업
	
	int min = 10000;
	int temp = 0;
	do {
		
		temp = getChickenDistance(comb);
		// 새로운 치킨집 조합의 치킨 거리 구하기

		if (min > temp) min = temp;

		
	} while (next_permutation(comb, comb + store_num));

	cout << min;

	system("pause");
}