// - 백준 11265 : 끝나지 않는 파티

#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, c;
bool isAble;

void dfs(int cur, int time, vector<vector<int>>& board, vector<bool>& vis) {
	if (isAble) return;
	if (cur == b) {
		isAble = true;
		return;
	}
	for (int i=1; i<=n; i++) {
		if (!vis[i] && time+board[cur][i] <= c) {
			vis[i] = true;
			dfs(i, time+board[cur][i], board, vis);
			vis[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	vector<vector<int>> board(n+1, vector<int>(n+1));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> board[i][j];
		}
	}
	for (int i=0; i<m; i++) {
		vector<bool> vis(n+1, false);
		isAble = false;
		cin >> a >> b >> c;
		vis[a] = true;
		dfs(a, 0, board, vis);
		cout << (isAble ? "Enjoy other party\n" : "Stay here\n");
	}
}