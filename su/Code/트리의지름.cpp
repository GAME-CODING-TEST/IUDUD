#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N,M;

vector<pair<int, int>> tree[100001] = {};
bool visited[100001] = {};
int start, ans;

void dfs(int node, int dis) {
    visited[node] = true;
    if (ans < dis) {
        ans = dis;
        start = node;
    }

    for (auto& i : tree[node]) {
        if (visited[i.first]) continue;
        dfs(i.first, dis + i.second);
    }
}


int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    cin >> N;
    
    
    for (int i = 0; i < N; ++i) {
        int idx;
        cin >> idx;
        while (true) {
            int next;
            cin >> next;
            if (next == -1) break;
            int dis;
            cin >> dis;
            tree[idx].push_back({next, dis});
        }        
    }

    dfs(1, 0);
    ans = 0;

    memset(visited, false, sizeof(visited));
    dfs(start, 0);

    cout << ans;

    return 0;
}
