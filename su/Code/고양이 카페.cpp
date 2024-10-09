#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    int N, K;
    cin >> N>>K;
    vector<int> cat(N);

    for (int i = 0; i < N; i++) {
        cin >> cat[i];
    }

    sort(cat.begin(), cat.end());

    int start = 0, end = N-1;

    int ans = 0;

    while (start < end) {
        if (cat[start] + cat[end] <= K) {
            ans++;
            start++;
            end--;
        }
        else {
            end--;
        }
    }

    cout << ans;

    return 0;
}