#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
bool ans;
vector<int> people[2001];

void dfs(int depth, int n, vector<bool>& visited) {
    if (depth == 4) {
        ans = true;
        return;
    }
    for (int i = 0; i < people[n].size(); i++) {
        int newfriend = people[n][i];
        if (visited[newfriend]) continue;
        visited[newfriend] = true;
        dfs(depth+1, newfriend, visited);
        visited[newfriend] = false;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    int M;
    string answer = "0";
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        people[from].push_back(to);
        people[to].push_back(from);
    } 

    for (int i = 0; i < N; i++) {
        vector<bool> visited(N);
        visited[i] = true;
        dfs(0, i, visited);
        if (ans) {
            answer = "1";
            break;
        }
    }

    cout << answer;

    return 0;
}
