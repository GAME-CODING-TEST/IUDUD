#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// stack�� ������ ����
void DFS(int v, vector<bool>& visitied, stack<int>& stk, const vector<vector<int>>& adj)
{
	visitied[v] = true;

	// ������ ��� ��忡 DFS ����, �� �̻� Ž���� �� ���� ������ ����
	for (int i : adj[v]) {
		if (!visitied[i]) {
			DFS(i, visitied, stk, adj);
		}
	}

	// �� ������ Ž���� ������ ���� ��带 stack�� �����Ͽ� ������ ����
	stk.push(v);
}

vector<int> TopologicalSort(int V, const vector<vector<int>>& adj)
{
	stack<int> stk;
	vector<bool> visited(V, false);

	// DFSALL()
	for (int i = 0; i < V; ++i) {
		if (!visited[i]) {
			DFS(i, visited, stk, adj);
		}
	}

	// stk���� �����鼭 topological sort�� ������� �����´�.
	vector<int> result;
	while (!stk.empty()) {
		result.push_back(stk.top());
		stk.pop();
	}

	return result;
}

void PrintResult(const vector<int>& result)
{
	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<vector<int>> adj(V);
	for (int i = 0; i < E; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);			// ���� �׷���
	}

	vector<int> result = TopologicalSort(V, adj);
	PrintResult(result);
}