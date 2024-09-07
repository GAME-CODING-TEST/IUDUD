#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> money(N+1);

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        money[i] = num+ money[i-1];
    }

    if (N == M) cout << money[N - 1];
    else if (M == 0) cout << 0;

    long long max = 0;
    for (int i = M; i <= N; i++) {
        long long sum = money[i] - money[i-M];
        if (max < sum) {
            max = sum;
        }
    }

    cout << max<<"\n";

    return 0;
}
