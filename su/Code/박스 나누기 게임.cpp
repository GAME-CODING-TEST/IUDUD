#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    
    int N, M;

    cin >> N >> M;

    string answer = "B";

    if (N == 1 && M == 1) {
        answer = "A";
    }
    else if (N % 2 == 0 || M % 2 == 0) {
        answer = "A";
    }


    cout << answer;
    return 0;
}
