#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

size_t V, E;
vector<vector<size_t>> adjList;
vector<bool> visited;

void Init()
{
	cin >> V >> E;
	adjList.resize(V);
	visited.resize(V, false);

	// 公规氢 + 牢立府胶飘
	for (size_t i = 0; i < E; ++i) {
		size_t v1, v2;
		cin >> v1 >> v2;
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}
}

void DFS(size_t v)
{
	visited[v] = true;
	cout << v << " ";

	for (size_t child : adjList[v]) {
		if (!visited[child]) {
			DFS(child);
		}
	}
}

int main()
{
	Init();
	DFS(0);
}