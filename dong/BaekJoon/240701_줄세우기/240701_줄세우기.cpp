#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 32000;

vector<int> topology[MAX + 1];
bool visited[MAX + 1];

void DFS(int node)
{
	if (visited[node]) return;

	for (int i : topology[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}

	visited[node] = true;
	cout << node << " ";
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		topology[b].push_back(a);
	}

	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (topology[i].empty()) {
			visited[i] = true;
			cout << i << " ";
		}
		else {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (visited[node]) continue;
		else DFS(node);
	}
}