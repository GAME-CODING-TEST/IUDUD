#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int N, M;
int map[20][20];
int maxNum;
int dx[] = { 1, 0,-1, 0 };
int dy[] = { 0, 1, 0, -1 };
void dfs(int x, int y, int cnt, int visited) {
    maxNum = max(maxNum, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
        if (visited & (1 << map[nx][ny])) continue;
        dfs(nx, ny, cnt + 1, visited | (1 << map[nx][ny]));
    }

}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    set<int> s;
    s.insert(map[0][0]);
    
    dfs(0, 0, 1, 1 << (map[0][0]));
    cout << maxNum;
    return 0;
}
