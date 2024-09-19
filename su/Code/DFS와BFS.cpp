#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int N;
bool ans;
vector<int> people[1001];

void bfs(int num) {
    queue<int> q;
    q.push(num);
    vector<bool> visited(N+1);
    visited[num] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < people[cur].size(); i++) {
            int next = people[cur][i];
            if (visited[next]) continue;           
            visited[next] = true;
            q.push(next);
        }
    }
    return;
}
void dfs(int num, vector<bool>& visited) {
    cout << num<<" ";
    visited[num] = true;
    for (int i = 0; i < people[num].size(); i++) {
        int next = people[num][i];
        if (visited[next]) continue;
        dfs(next, visited);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    int M, K;
    string answer = "0";
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        people[from].push_back(to);
        people[to].push_back(from);
    } 

    for (int i = 1; i < N+1; i++) {
        sort(people[i].begin(), people[i].end());
    }

    vector<bool> visited(N+1);
    dfs(K, visited);
    cout << "\n";
    bfs(K);

    return 0;
}
