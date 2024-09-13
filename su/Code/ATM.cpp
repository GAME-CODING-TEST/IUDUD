#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    int answer= arr[0];

    for (int i = 1; i < N; i++) {
        arr[i] = arr[i] + arr[i - 1];
        answer += arr[i];
    }
    cout << answer;

    return 0;
}
