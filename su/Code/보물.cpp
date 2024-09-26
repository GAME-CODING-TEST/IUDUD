#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
   
    for (int i = 0; i < N; i++) {
        int num;
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer += (A[i] * B[i]);
    }

    cout << answer;

    return 0;
}
