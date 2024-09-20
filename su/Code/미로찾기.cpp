#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
bool ans;


void bfs(vector<vector<int>> map) {
    queue<pair<int,int>> q;
    q.push({0,0});
    int dx[] = { 1,-1,0,0 };
    int dy[] = { 0,0,1,-1 };
    int dp[100][100] = {0};
    bool visited[100][100] = {false};
    dp[0][0] = 1;
    visited[0][0] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        //cout << "현재 위치 : " << cur.first << ", " << cur.second << " = " << map[cur.first][cur.second] << "\n";
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];


            if (nx >= N || nx < 0 || ny >= M || ny < 0 || visited[nx][ny] || map[nx][ny] == 0 || dp[nx][ny] >= dp[cur.first][cur.second]) continue;
            dp[nx][ny] = dp[cur.first][cur.second] + 1; // 이동횟수 갱신 
            visited[nx][ny] = true;
            q.push({ nx,ny });
            if (nx == N - 1 && ny == M - 1) {
                //cout << "종료";
                cout << dp[nx][ny];
                return;
            }
        }
        
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    string answer = "0";
    cin >> N >> M;
    
    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {            // 미로 입력

        string row;                     // 행 입력

        cin >> row;

        for (int j = 0; j < M; ++j) {        // 행 별 좌표값 저장
            map[i][j] = row[j] - '0';    // 행 별 좌표값들은 문자 형태이기 때문에, 숫자로 변환
        }
    }

    bfs(map);

    return 0;
}
