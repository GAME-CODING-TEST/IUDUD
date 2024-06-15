#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> TopologicalSort(int V, const vector<vector<int>>& adj)
{
	vector<int> inDegree(V, 0);
	vector<int> result;
	queue<int> q;

	// �� ������ in-degree( ������ ������ ���� ) ���� �����Ѵ�.
	for (int u = 0; u < V; ++u) {
		for (int v : adj[u]) {
			inDegree[v]++;
		}
	}

	// in-degree ���� 0�� ������ queue�� �ִ´�.
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
			inDegree[v]--;			// u�� ����� ������ Ÿ�� �� �� �ִ� ������ in-degree ���� -1 �Ѵ�.

			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}

	// cycle�� ���� ��� => ������ ���������� ������ �ʴ´�.
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