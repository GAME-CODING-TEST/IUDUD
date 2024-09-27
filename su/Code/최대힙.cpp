#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;

        if (num == 0) {
            cout << (pq.empty() ? 0 : pq.top())<< "\n";
            if (!pq.empty()) {
                pq.pop();
            }
        }
        else {
            pq.push(num);
        }
    }
    

    return 0;
}
