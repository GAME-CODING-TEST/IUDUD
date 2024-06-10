#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const size_t INF = numeric_limits<size_t>::max();

size_t V, E, start;
vector <vector<pair<size_t, size_t>>> adjList;
vector<size_t> dist;

void Init()
{
	cin >> V >> E;
	adjList.resize(V);
	dist.resize(V, INF);

	// 무향 그래프, 각 간선의 가중치
	for (size_t i = 0; i < E; ++i) {
		size_t v1, v2, w;
		cin >> v1 >> v2 >> w;
		adjList[v1].push_back({ v2, w });
		adjList[v2].push_back({ v1, w });
	}

	cin >> start;
}

void Dijkstra()
{
	priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		size_t distance = pq.top().first;
		size_t cur = pq.top().second;
		pq.pop();

		if (distance > dist[cur]) continue;

		for (const auto& neighbor : adjList[cur]) {
			size_t next = neighbor.first;
			size_t weight = neighbor.second;

			if (dist[cur] + weight < dist[next]) {
				dist[next] = dist[cur] + weight;
				pq.push({ dist[next], next });
			}
		}
	}
}

void Print()
{
	for (size_t i = 0; i < V; ++i) {
		if (dist[i] == INF) {
			cout << "노드 " << i << "까지의 거리: INF" << endl;
		}
		else {
			cout << "노드 " << i << "까지의 거리: " << dist[i] << endl;
		}
	}
}

int main()
{
	Init();
	Dijkstra();
	Print();
}