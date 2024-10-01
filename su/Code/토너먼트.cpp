#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N, K,E;
    cin >> N >> K >> E;
    N += 1;
    int cnt = 0;
    while (K != E) {
        K = (K/ 2.0f) + 0.5f;
        E = (E/ 2.0f) + 0.5f;
        cnt++;
    }
    
    cout << cnt;

    return 0;
}
