#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    auto cmp = [](int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    };

    int N;
    cin >> N;

    string answer = "";

    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            if (!q.empty()) {
                cout << q.top()<<"\n";
                q.pop();
            }
            else {
                cout << 0 << "\n";
            }
        }
        else {
            q.push(num);
        }
    }
    return 0;
}
