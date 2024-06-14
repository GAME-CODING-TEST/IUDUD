#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// stack에 순서를 저장
void DFS(int v, vector<bool>& visitied, stack<int>& stk, const vector<vector<int>>& adj)
{
	visitied[v] = true;

	// 인접한 모든 노드에 DFS 적용, 더 이상 탐색할 수 없을 때까지 수행
	for (int i : adj[v]) {
		if (!visitied[i]) {
			DFS(i, visitied, stk, adj);
		}
	}

	// 끝 노드까지 탐색이 끝나면 현재 노드를 stack에 삽입하여 순서를 저장
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

	// stk에서 꺼내면서 topological sort의 결과값을 가져온다.
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
		adj[u].push_back(v);			// 방향 그래프
	}

	vector<int> result = TopologicalSort(V, adj);
	PrintResult(result);
}