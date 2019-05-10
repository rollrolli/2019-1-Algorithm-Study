#include <iostream>
#include <stack>

using namespace std;


stack<int> s;

void solve(int N, int M, int index) {
	
	if (index == N + 1 && M != 0) {	// M�� �� �� á�µ� ����
		return;
	}
	if (M == 0) {	// M�� �� á�� ��
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
	// �ְ� ������
	s.push(index);
	solve(N, M - 1, index + 1);
	s.pop();
	// �� �ְ� ������
	solve(N, M, index + 1);
}



int main() {

	int N, M;

	cin >> N >> M;

	solve(N, M, 1);


	system("pause");

}