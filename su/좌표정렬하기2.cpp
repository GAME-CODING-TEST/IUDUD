#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>>  pos(N);
	string answer = "";

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x>>y;
		pos[i] = { y, x };
	}

	sort(pos.begin(), pos.end());

	for (int i = 0; i < pos.size(); i++) {
		cout << pos[i].second << " "<< pos[i].first << "\n";
	}

	return 0;
}