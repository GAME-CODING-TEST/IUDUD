// - 백준 1949 : 우수 마을

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

const int MAX = 10005;

vector<int> adj[MAX];
int p[MAX];
int N;
int dp[MAX][2]; //0인 경우 우수 마을 1인 경우 안 우수 마을
int cost[MAX];
int maxnum = -1;

void dfs(int cur) {
    //cout << "cur : " << cur << "\n";
    dp[cur][0] = cost[cur];
    dp[cur][1] = 0;
    
    for (int nxt : adj[cur]) {
        //cout << "nxt : " << nxt << "\n";
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
        dp[cur][0] += dp[nxt][1];
        dp[cur][1] += max(dp[nxt][0], dp[nxt][1]);
        maxnum = max(dp[cur][0], dp[cur][1]);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> cost[i];
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    
    cout << maxnum << "\n";

}