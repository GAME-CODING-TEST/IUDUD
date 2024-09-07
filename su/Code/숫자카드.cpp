#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	string answer = "";
	set<int> number;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		number.insert(num);
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (number.insert(num).second) {
			answer += "0 ";
			number.erase(num);
		}
		else {
			answer += "1 ";
		}
	}
	cout << answer;
	return 0;
}