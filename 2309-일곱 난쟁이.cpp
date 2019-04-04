#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int height[9] = { 0, };
	int sum = 0;
	int fake[2] = { 0, };
	int dwarf[7] = { 0, };

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];

	}
	
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - height[i] - height[j] == 100) {
				fake[0] = i;
				fake[1] = j;
				break;
			}
		}
	}
	int index = 0;

	for (int i = 0; i < 9; i++) {
		if (i != fake[0] && i != fake[1])
			dwarf[index++] = height[i];
	}

	sort(dwarf, dwarf+7);

	for (int i = 0; i < 7; i++) {
		cout << dwarf[i] << endl;
	}

	system("pause");


}