#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	else {
		return p1.first < p2.first;
	}
}

int main()
{
	int N;
	cin >> N;

	int x, y;
	vector<pair<int, int>> points(N);
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		points[i] = { x, y };
	}

	sort(points.begin(), points.end(), Compare);
	for (int i = 0; i < N; ++i) {
		cout << points[i].first << " " << points[i].second << '\n';
	}
}