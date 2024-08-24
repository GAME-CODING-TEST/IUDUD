// - 백준 2213 : 트리의 독립집합

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
int dp[MAX][2]; //0인 포함 1인 경우 미포함
int cost[MAX];
int maxnum = -1;
vector<int> result;

void dfs(int cur) {
    
    dp[cur][0] = cost[cur];
    dp[cur][1] = 0;
    
    for (int nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
        dp[cur][0] += dp[nxt][1];
        dp[cur][1] += max(dp[nxt][0], dp[nxt][1]);
        maxnum = max(dp[cur][0], dp[cur][1]);
        
    }
}

void trace(int cur,bool include) {
    if (include == true) {
        //포함하면 자식은 포함 안해야됨
        result.push_back(cur);
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            trace(nxt, false);
        }

    }
    else {
        //포함하지 않으면 자식은 포함할 수도 있고 안 할 수도 있고
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            if (dp[nxt][0] > dp[nxt][1]) trace(nxt, true);
            else trace(nxt, false);
        }
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
    
    if (dp[1][0] > dp[1][1]) trace(1, true);
    else trace(1, false);

    sort(result.begin(), result.end());

    for (auto& x : result) cout << x << " ";
}