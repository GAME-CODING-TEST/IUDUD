#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

int family[100][100];
int visited[100] = {0};
int N, M, T, F;
void bfs() {
    queue<int> q;
    q.push(T);
    visited[T] = 1;

    while (!q.empty()) {
        int num = q.front();
        q.pop();
        for (int i = 1; i < N+1; i++) {
            if (family[num][i] == 0 || visited[i] != 0) continue;            
            q.push(i);            
            visited[i] = visited[num] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    cin >> N >> T >>F;
    int ans = -1;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int to, from;
        cin >> from >> to;
        family[from][to] = 1;
        family[to][from] = 1;
    }

    bfs();
    if (visited[F] != 0)
        ans = visited[F]-1;
    cout << ans;

    return 0;
}
