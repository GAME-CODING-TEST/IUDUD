#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b;  // 길이가 같으면 사전순으로 정렬
	}
	return a.length() < b.length();
}

int main() {
	int T = 0;
	vector<string> answer;
	cin >> T;

	set<string> charArray;

	for (int t = 0; t < T; t++) {
		string s;
		cin >> s;
		charArray.insert(s);
	}

	for (auto s : charArray) {
		answer.push_back(s);
	}

	sort(answer.begin(), answer.end(), compare);

	for (auto s : answer) {
		cout << s << endl;
	}

		return 0;
}