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

	// min-heap�� ����ϱ� ����
	bool operator<(const Edge& other) const {
		return w > other.w;
	}
};

vector<Edge> Prim(int V, vector<vector<Edge>>& graph)
{
	vector<int> dist(V, INF);
	vector<int> parent(V, -1);		// mst�� �����ϱ� ���� �θ� �迭
	vector<bool> inMST(V, false);
	priority_queue<Edge> pq;		// ������� �߰ߵ� ���� ���� ����ġ�� ������ ����

	// 0�� ��带 �������� Prim �˰��� ���� ����
	int start = 0;
	dist[start] = 0;
	pq.push(Edge(start, start, 0));

	while (!pq.empty()) {
		int u = pq.top().u;
		pq.pop();

		// mst�� ���Ե� ������ �����Ѵ�.
		if (inMST[u]) continue;
		inMST[u] = true;

		// u�� ������ ��� ������ ���鼭 mst�� ���� �ĺ��� Ž���Ѵ�.
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
	// ���� ����� 0���� �θ� ��尡 ���� ������ -1�̴�.
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