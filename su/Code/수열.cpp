#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> temp(N+1, 0);
    int maxValue = -999999999;
    
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        temp[i] = num + temp[i - 1];
    }

    for (int i = 0; i < N-K+1; i++) {
        if ((temp[i + K] - temp[i]) > maxValue) {
            maxValue = temp[i + K] - temp[i];
        }
    }


    cout << maxValue;

    return 0;
}
