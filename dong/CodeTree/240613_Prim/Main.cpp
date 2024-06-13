#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

const int INF = numeric_limits<int>::max();

class Edge
{
public:
	int u, v, w;
	Edge(int u, int v, int w) :u(u), v(v), w(w) {}

	// min-heap을 사용하기 위함
	bool operator<(const Edge& other) const {
		return w > other.w;
	}
};

vector<Edge> Prim(int V, vector<vector<Edge>>& graph)
{
	vector<int> dist(V, INF);
	vector<int> parent(V, -1);		// mst를 저장하기 위한 부모 배열
	vector<bool> inMST(V, false);
	priority_queue<Edge> pq;		// 현재까지 발견된 가장 작은 가중치의 간선을 저장

	// 0번 노드를 기준으로 Prim 알고리즘 수행 시작
	int start = 0;
	dist[start] = 0;
	pq.push(Edge(start, start, 0));

	while (!pq.empty()) {
		int u = pq.top().u;
		pq.pop();

		// mst에 포함된 정점은 무시한다.
		if (inMST[u]) continue;
		inMST[u] = true;

		// u와 인접한 모든 간선을 보면서 mst에 넣을 후보를 탐색한다.
		for (auto& edge : graph[u]) {
			int v = edge.v;
			int w = edge.w;

			if (!inMST[v] && w < dist[v]) {
				dist[v] = w;
				pq.push(Edge(u, v, w));
				parent[v] = u;
			}
		}
	}

	vector<Edge> mst;
	// 시작 노드인 0번은 부모 노드가 없기 때문에 -1이다.
	for (int v = 1; v < V; ++v) {
		if (parent[v] != -1) {
			mst.push_back(Edge(parent[v], v, dist[v]));
		}
	}

	return mst;
}

void PrintMST(const vector<Edge>& mst)
{
	for (const auto& edge : mst) {
		cout << edge.u << " - " << edge.v << endl;
	}
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<vector<Edge>> graph(V);
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(Edge(u, v, w));
		graph[v].push_back(Edge(v, u, w));
	}

	vector<Edge> mst = Prim(V, graph);
	PrintMST(mst);
}