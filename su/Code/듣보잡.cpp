#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int N ,M;
	cin >> N >> M;
	set<string> names;
	vector<string> popular;
	string answer = "";

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		names.insert(s);
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		
		if (!names.insert(s).second) {
			popular.push_back(s);
			cnt++;
		}
	}

	sort(popular.begin(), popular.end());

	cout << cnt << "\n";

	for (int i = 0; i < popular.size(); i++) {
		cout << popular[i] << "\n";
	}

	return 0;
}