#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    set<string> sArr;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        sArr.insert(s);
    }
    
    int answer = 0;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (sArr.find(s) != sArr.end()) {
            answer++;
        }
    }
    cout << answer;

    return 0;
}
