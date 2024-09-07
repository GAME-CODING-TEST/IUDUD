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

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (q.size() >1) {
        q.pop();
        if (q.size() == 1) {
            break;
        }
        int num = q.front();
        q.pop();
        q.push(num);
    }

    cout << q.front();

    return 0;
}
