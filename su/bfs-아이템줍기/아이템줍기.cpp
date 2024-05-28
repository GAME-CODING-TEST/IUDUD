#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Coordx{
    int x, y, dis;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int map[102][102]={0};
    int visited[102][102]={0};
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    
    for(int i = 0; i<rectangle.size(); i++){
        for(int j = 0; j<rectangle[i].size(); j++)
        {
            rectangle[i][j] = rectangle[i][j]*2;
        }
        
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];
        
        for(int x = x1; x<=x2; x++){
            for(int y= y1; y<=y2; y++){
                map[x][y] = 1;
            }
        }
    }
    
    for(int i = 0; i<rectangle.size(); i++){
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];
        
        for(int x = x1+1; x<x2; x++){
            for(int y = y1+1;y<y2; y++){
                map[x][y] = 0;
            }
        }
    }
    
    queue<Coordx> q;
    
    q.push({characterX*2, characterY*2, 0});
    visited[characterX*2][characterY*2] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        if(cur.x == itemX*2 && cur.y == itemY*2){
            answer = cur.dis/2;
            break;
        }
        
        for(int i = 0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if(nx<=0||nx>101||ny<=0||ny>101||visited[nx][ny] == 1) continue;
            
            if(map[nx][ny] == 0) continue;
            
            visited[nx][ny] = 1;
            q.push({nx,ny,cur.dis+1});
        }
    }
    
    return answer;
}