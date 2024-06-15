#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> TopologicalSort(int V, const vector<vector<int>>& adj)
{
	vector<int> inDegree(V, 0);
	vector<int> result;
	queue<int> q;

	// 각 정점에 in-degree( 간선이 들어오는 갯수 ) 값을 세팅한다.
	for (int u = 0; u < V; ++u) {
		for (int v : adj[u]) {
			inDegree[v]++;
		}
	}

	// in-degree 값이 0인 정점은 queue에 넣는다.
	for (int i = 0; i < V; ++i) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		result.push_back(u);

		for (int v : adj[u]) {
			inDegree[v]--;			// u와 연결된 간선을 타고 갈 수 있는 정점의 in-degree 값을 -1 한다.

			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}

	// cycle이 생긴 경우 => 실제로 문제에서는 생기지 않는다.
	if (result.size() != V) {
		return {};
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
		adj[u].push_back(v);
	}

	vector<int> result = TopologicalSort(V, adj);
	PrintResult(result);
}