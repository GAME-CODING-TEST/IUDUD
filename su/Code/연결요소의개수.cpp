#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec[1001];
bool visited[1001];

void dfs(int n) {
    visited[n] = true;

    for (int i = 0; i < vec[n].size(); i++) {
        int idx = vec[n][i];
        if (!visited[idx]) {
            dfs(idx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        vec[to].push_back(from);
        vec[from].push_back(to);
    }

    int answer = 0;
    for (int i = 1; i < N + 1; i++) {
        if (!visited[i]) {
            answer++;
            dfs(i);
        }
    }

    cout << answer;

    return 0;
}
