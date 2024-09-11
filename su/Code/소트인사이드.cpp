#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    string N;
    cin >> N;
    vector<int> A(N.length());
    int size = N.length();

    for (int i = 0; i < size; i++) {
        A[i] = N[i] - '0';
    }

    sort(A.begin(), A.end(), greater<int>());

    for (int i = 0; i < size; i++) {
        cout << A[i];

    }
    
    return 0;
}
