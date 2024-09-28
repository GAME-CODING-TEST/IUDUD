#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N, X;
    cin >> N;
    
    vector<int> num(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    cin >> X;

    sort(num.begin(), num.end());
    
    int start = 0, end = N-1;
    int answer = 0;

    while (start < end) {
        int A = num[start] + num[end];
        if (A == X) {
            answer++;
            start++;
        }
        else if (A > X) {
            end--;
        }
        else if (A < X) {
            start++;

        }
    }
    
    cout << answer;

    return 0;
}
