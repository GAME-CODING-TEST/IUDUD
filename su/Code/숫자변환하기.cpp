#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 9999;
    vector<int> visited(y+1, 0);
    queue<pair<int, int>> q;
    q.push({x,0});
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();        
        if(cur == y) answer = min(answer, cnt);
        if(visited[cur]==1||cur>y) continue;
        
        visited[cur] = 1;
        
        if(cur+n <= y)
            q.push({cur+n, cnt+1});
        if(cur*2 <= y)
            q.push({cur*2, cnt+1});
        if(cur*3 <= y)
            q.push({cur*3, cnt+1});
    }
    
    return answer==9999?-1:answer;
}