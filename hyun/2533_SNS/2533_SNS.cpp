// - 백준 2533 : 사회망 서비스(SNS)

#include <iostream>
#include <vector>
 
using namespace std;
 
int n;
 
int dp[1000001][2]; // 본인 노드가 얼리 일 때 또는 얼리가 아닐 때, 최소 얼리어댑터의 개수  
vector<vector<int> > edges;
vector<int> isVisited;
 
void dfs(int node){
    isVisited[node] = 1;
    dp[node][0] = 0; // 본인이 얼리가 아니면 얼리 개수 0 
    dp[node][1] = 1; // 본인이 얼리면 얼리 개수 1 
    
    for(int i=0; i<edges[node].size(); i++){
        int conn_node = edges[node][i]; 
        
        if(isVisited[conn_node]) continue; // 아래로 DFS 진행하기 위해서 위로 이동 방지  
        
        dfs(conn_node);
        
        dp[node][0] += dp[conn_node][1]; // 현재 노드가 얼리가 아니라면, 주변 노드는 얼리어야 한다. 
        dp[node][1] += min(dp[conn_node][0], dp[conn_node][1]); // 현재 노드가 얼리라면, 주변은 얼리 또는 얼리가 아니다. 
    }
}
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    edges.resize(n+1);
    isVisited.resize(n+1);
    
    int u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    dfs(1);
    
    cout << min(dp[1][0], dp[1][1]);
}
