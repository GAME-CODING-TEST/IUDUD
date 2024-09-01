#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int answer=0;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr.begin(), arr.end());

    int start = 0, end = N-1;
    while (start<end) {
        if (arr[start] + arr[end] > M) {
            end--;
        }
        else if (arr[start] + arr[end] < M) {
            start++;
        }
        else {
            answer++;
            end--;
            start++;
        }
    }


    cout << answer;

    return 0;
}
