// - 백준 1922 : 네트워크 연결

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1<=n <=1000
// 1<= m<= 100000
//1<= c<=10000
int n, m;
int parent[1001];
int result;
int getParent(int num) {
	if (num == parent[num]) return num;
	return parent[num] = getParent(parent[num]);

}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		parent[a]= b;
	}
}
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edge(m);
	for (int i = 0; i < m; i++) {
		int cost, a, b;
		cin >> a >> b >> cost;
		edge[i] = { cost,{a,b} };
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sort(edge.begin(), edge.end());

	for (int i = 0; i < m; i++) {
		int cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (!findParent(a, b)) {
			result += cost;
			unionParent(a, b);
		}
	}
	cout << result;

	return 0;
}