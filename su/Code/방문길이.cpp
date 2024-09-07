#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    // U D R L
    int dx[4] = {0,0,1,-1};    
    int dy[4] = {1,-1,0,0};    
    set<pair<pair<int, int>, pair<int, int>>> coord;
    int x = 5, y = 5;
    
    // 커맨드 저장
    vector<int> dir(dirs.length());
    for(int i = 0; i<dirs.length(); i++){
        if(dirs[i] == 'U')  dir[i] = 0;
        else if(dirs[i] == 'D')  dir[i] = 1;
        else if(dirs[i] == 'R')  dir[i] = 2;
        else if(dirs[i] == 'L')  dir[i] = 3;
    }
        
    for(int i = 0; i<dirs.length(); i++){
        int nx = x + dx[dir[i]];
        int ny = y + dy[dir[i]];        
        
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10) continue; // 좌표 범위를 넘어가는 경우 무시
        
        pair<int, int> a = {x,y};
        pair<int, int> b = {nx,ny};
        
        coord.insert({a,b});
        coord.insert({b,a});
        
        x = nx;
        y = ny;
    }
    return coord.size()/2;
}