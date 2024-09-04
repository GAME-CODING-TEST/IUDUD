#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector<int> num(N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < N; i++) {
        q.push({ num[i] , i });
        while (1) {
            pair<int, int> p = q.top();
            if (i>=L && p.second <= i-L) {
                q.pop();
                continue;
            }
            else {
                cout << p.first << " ";
                break;
            }
        }
    }


    //cout << answer;

    return 0;
}
