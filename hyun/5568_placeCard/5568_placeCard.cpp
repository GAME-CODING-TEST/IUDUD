// - 백준 5568 : 카드 놓기

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector <int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	// next_permutation을 사용하기 전 정렬을 해줘야함

	set <string> s;
	do {
		string res;
		for (int i = 0; i < k; i++) {
			res += to_string(v[i]);
		}
		s.insert(res);
	} while (next_permutation(v.begin(), v.end()));
	cout << s.size();
}