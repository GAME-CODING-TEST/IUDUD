#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string answer="<";
    queue<int> best;

    for (int i = 0; i < N; i++) {
        best.push(i+1);
    }

    int idx = 0;
    while (!best.empty()) {
        idx++;
        if (idx % K == 0) {
            answer += to_string(best.front())+", ";
        }
        else {
            best.push(best.front());
        }
        best.pop();
    }
    answer = answer.substr(0, answer.size() - 2);
    cout << answer<<">";

    return 0;
}
