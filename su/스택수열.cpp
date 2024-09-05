#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    int cnt = 1;
    cin >> N;
    string answer="";
    stack<int> s;

    int top = 0;
    for (int i = 0; i < N; i++) {
        int number;
        cin >> number;

        while (cnt <= number) {
            s.push(cnt);

            cnt++;
            answer += "+\n";
        }
        if (s.top() == number) {
            s.pop();
            answer += "-\n";
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << answer;

    return 0;
}
