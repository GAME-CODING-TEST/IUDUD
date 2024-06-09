#include <iostream>
#include <vector>
#include <queue>
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

	for (size_t i = 0; i < E; ++i) {
		size_t v1, v2;
		cin >> v1 >> v2;

		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}
}

void BFS(size_t start)
{
	queue<size_t> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		size_t v = q.front();
		q.pop();

		for (size_t adj : adjList[v]) {
			if (!visited[adj]) {
				visited[adj] = true;
				q.push(adj);
			}
		}
	}
}

int main()
{
	Init();
	BFS(0);
}