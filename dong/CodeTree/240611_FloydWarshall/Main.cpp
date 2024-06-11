#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const size_t INF = numeric_limits<size_t>::max();

size_t V, E;
vector<vector<size_t>> dist;

void Init()
{
	cin >> V >> E;
	dist.resize(V, vector<size_t>(V));

	// Set_Graph
	for (size_t i = 0; i < V; ++i) {
		for (size_t j = 0; j < V; ++j) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = INF;
			}
		}
	}

	// Set Edge
	for (size_t i = 0; i < E; ++i) {
		size_t u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = w;
	}
}

void FloydWarshall()
{
	for (size_t k = 0; k < V; ++k) {
		for (size_t i = 0; i < V; ++i) {
			for (size_t j = 0; j < V; ++j) {
				// k 지점에서 i와 j로 가는 경로가 없는 경우를 제외
				if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void PrintDist()
{
	for (size_t i = 0; i < V; ++i) {
		for (size_t j = 0; j < V; ++j) {
			if (dist[i][j] == INF) {
				cout << "INF ";
			}
			else {
				cout << dist[i][j] << " ";
			}
		}
		cout << endl;
	}
}

int main()
{
	Init();
	FloydWarshall();
	PrintDist();
}