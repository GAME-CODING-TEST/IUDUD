#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int map[3][3];
bool bfs() {    
    queue < pair<int, int> > q;
    q.push({ 0,0 });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nx = x + (map[x][y] * dx[i]);
            int ny = y + (map[x][y] * dy[i]);

            if (nx < N && ny < N) {
                if (map[nx][ny] == 0) {
                    return false;
                }
                if (nx == N - 1 && ny == N - 1) {
                    return true;
                }
                q.push({ nx,ny });
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    if (bfs()) {
        cout << "HaruHaru";

    }
    else {
        cout << "Hing";
    }

    return 0;
}
