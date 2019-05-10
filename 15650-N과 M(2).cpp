#include <iostream>
#include <stack>

using namespace std;


stack<int> s;

void solve(int N, int M, int index) {
	
	if (index == N + 1 && M != 0) {	// M개 다 안 찼는데 끝남
		return;
	}
	if (M == 0) {	// M개 다 찼을 때
		stack<int> temp;
		while (!s.empty()) {
			temp.push(s.top());
			s.pop();
		}
		while (!temp.empty()) {
			cout << temp.top() << " ";
			s.push(temp.top());
			temp.pop();
		}

		cout << "\n";
		return;
	}
	// 넣고 지나감
	s.push(index);
	solve(N, M - 1, index + 1);
	s.pop();
	// 안 넣고 지나감
	solve(N, M, index + 1);
}



int main() {

	int N, M;

	cin >> N >> M;

	solve(N, M, 1);


	system("pause");

}