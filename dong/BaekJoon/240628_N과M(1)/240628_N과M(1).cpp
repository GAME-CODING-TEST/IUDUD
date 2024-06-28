#include <iostream>

using namespace std;

const int MAX_N = 8;

int N, M;
int seq[MAX_N];
bool visited[MAX_N];

void DFS(int curIdx)
{
	if (curIdx == M) {
		for (int i = 0; i < M; ++i) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = 0; i < N; ++i) {
		if (visited[i]) continue;

		seq[curIdx] = i + 1;			// 1부터 N까지의 숫자를 출력
		visited[i] = true;
		DFS(curIdx + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> N >> M;
	DFS(0);
}