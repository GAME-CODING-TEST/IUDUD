#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:
	int u, v, w;
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}

	bool operator<(const Edge& other) const		// weight 비교
	{
		return w < other.w;
	}
};

// Union-Find 자료구조
class UnionFind
{
public:
	UnionFind(int n)
	{
		parent.resize(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	int Find(int u)
	{
		if (parent[u] != u) {	// 자신이 root가 아닌 경우
			parent[u] = Find(parent[u]);
		}
		return parent[u];
	}

	void Union(int u, int v)
	{
		int rootU = Find(u);
		int rootV = Find(v);
		// 같은 집합이 아닌 경우
		if (rootU != rootV) {
			parent[rootU] = rootV;
		}
	}

private:
	vector<int> parent;
};

vector<Edge> Kruskal(int V, vector<Edge>& edges)
{
	vector<Edge> mst;
	UnionFind uf(V);
	sort(edges.begin(), edges.end());
	
	for (const auto& edge : edges) {
		// 같은 집합이 아닌 경우
		if (uf.Find(edge.u) != uf.Find(edge.v)) {
			uf.Union(edge.u, edge.v);
			mst.push_back(edge);
		}
	}

	return mst;
}

void PrintMST(const vector<Edge>& mst)
{
	for (const auto& edge : mst) {
		cout << edge.u << " - " << edge.v << "( weight: " << edge.w << " )" << endl;
	}
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<Edge> edges;
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ u, v, w });
	}

	vector<Edge> mst = Kruskal(V, edges);
	PrintMST(mst);
}