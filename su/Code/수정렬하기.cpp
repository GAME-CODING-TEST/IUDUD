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
    vector<int> num(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < N; i++) {
        int min = i;
        for (int j = i+1; j < N; j++) {
            if (num[j] < num[min]) {
                min = j;
            }
        }
        // min과 i swap
        int tmp = num[min];
        num[min] = num[i];
        num[i] = tmp;
    }

    for (int n : num) {
        cout << n << "\n";
    }
    
    return 0;
}
