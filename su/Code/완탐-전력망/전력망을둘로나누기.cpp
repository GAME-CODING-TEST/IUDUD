#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int elecNetwork(vector<vector<int>> v){
    vector<int> visit(v.size());
    queue<int> q;
    
    q.push(1);
    int cnt = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(visit[cur]==1)continue;
        visit[cur] = 1;
        
        cnt++;
        
        for(int i = 0; i<v[cur].size(); i++){
            q.push(v[cur][i]);
        }
    }
    int cnt2 = v.size()-1-cnt;
    return abs(cnt2-cnt);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 10000;
    for(int i = 0; i<wires.size(); i++){
        vector<vector<int>> visit(n+1);
        for(int j = 0; j<wires.size(); j++){
            if(i==j)continue;
            int to = wires[j][0];
            int from = wires[j][1];
                
            visit[to].push_back(from);
            visit[from].push_back(to);
        }
        answer = min(answer, elecNetwork(visit));
        visit.clear();
    }
    
    return answer;
}