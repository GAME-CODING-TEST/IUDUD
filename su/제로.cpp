#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>>  pos(N);
	int answer = 0;
	stack<int> s;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0 && !s.empty()) {
			s.pop();
		}
		else
			s.push(num);
	}

	while (!s.empty()) {
		answer += s.top();
		s.pop();

	}

	cout << answer;
	return 0;
}