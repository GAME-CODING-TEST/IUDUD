#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N, K;
    cin >> N ;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        cout << arr[i]<<"\n";

    }

    return 0;
}
