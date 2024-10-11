#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    
    int N, L;

    cin >> N >> L;
    vector<int> alchol(N+1);

    for(int i = 1; i<=N; i++){
        cin>> alchol[i];
        alchol[i] += alchol[i - 1];
    }

    int ans = 0;

    for (int i = 0; i < L; i++) {
        if (alchol[i] < 129 || alchol[i] > 138) continue;
        ans++;
    }

    for (int i = L; i <= N; i++) {
        int cur = alchol[i] - alchol[i - L];

        if (cur < 129 || cur > 138) continue;
        ans++;
    }

    cout << ans;
    return 0;
}
