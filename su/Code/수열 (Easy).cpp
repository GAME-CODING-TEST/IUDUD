#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    int N, K;
    cin >> N;
    vector<long long> arr(N+1);
    vector<long long> ps(N+1);
    long long ans = 0;
    for (int i = 1; i < N+1; i++) {
        cin >> arr[i];
        ps[i] = ps[i - 1] + arr[i];
        ans += arr[i] * ps[i - 1];
        ans %= 1000000007;
    }

    cout << ans;

    return 0;
}
