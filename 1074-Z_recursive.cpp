#include <iostream>
#include <math.h>

using namespace std;

int r, c;
int result;

void visit(int start, int num, int first_r, int first_c) {

	//cout << "start : " << start << ", num : " << num << 
	//	", first_r : " << first_r << ", first_c : " << first_c << "\n";


	if (num == 1) { 
		if (r == first_r && c == first_c) {
			result = start;
		}
		return; 
	}
	
	visit(start,				num / 4,	first_r,	first_c);
	visit(start + num / 4,		num / 4,	first_r,	first_c + sqrt(num) / 2);
	visit(start + num / 2,		num / 4,	first_r + sqrt(num) / 2,	first_c);
	visit(start + 3 * num / 4,	num / 4,	first_r + sqrt(num) / 2,	first_c + sqrt(num) / 2);

}

int main() {
	int N;

	cin >> N >> r >> c;

	r++; c++;

	//cout << "r : " << r << ", c : " << c << "\n\n";
	visit(0, (int)pow(2, N) * (int)pow(2, N), 1, 1);

	cout << result;


	system("pause");
}