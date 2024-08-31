#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;
    int answer=1;

    int start = 1;
    int end = 2;
    int sum = start + end;

    while (end<N) {
        if (sum > N) {
            sum -= start;
            start++;
        }
        else if (sum < N) {
            end++;
            sum += end;
        }
        else if (sum == N) {
            answer++;
            sum -= start;
            start++;
        }
    }


    cout << answer;

    return 0;
}
