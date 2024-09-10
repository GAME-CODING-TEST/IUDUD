#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A[i] = {num, i};
    }

    sort(A.begin(), A.end());

    int answer=-1;
    for (int i = 0; i < N; i++) {
        answer = max(A[i].second - i, answer);
    }
    cout << answer+1;
    return 0;
}
