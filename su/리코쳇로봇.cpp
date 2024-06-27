#include <string.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> board) {
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n = board.size();
    int m = board[0].size();
    
    int visit[100][100];
    memset(visit,-1,sizeof(visit));
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            // 시작 지점 추가
            if(board[i][j] == 'R') q.push({i,j});
        }
    }
    
    visit[q.front().first][q.front().second] = 0;
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = cur.first, ny = cur.second;
            while(1){
                if(nx<0||nx>=n||ny<0||ny>=m||board[nx][ny] == 'D') break;
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];
            if(board[nx][ny] == 'G') return (visit[cur.first][cur.second]+1);
            if(visit[nx][ny] >= 0) continue;
            visit[nx][ny] = visit[cur.first][cur.second]+1;
            q.push({nx, ny});
        }
    }
    
    return -1;
}