#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> sumArr(N+1,0);
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		n += sumArr[i - 1];
		sumArr[i] = n;
	}

	cin >> N;
	string answer;
	for (int i = 0; i < N; i++) {
		int start;
		int end;

		cin >> start >> end;
		
		answer += to_string(sumArr[end] - sumArr[start-1]) + "\n";
	}

	cout << answer;

	return 0;
}