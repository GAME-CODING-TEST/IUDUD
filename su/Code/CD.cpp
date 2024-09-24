#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    
    while (true) {
        int N, M;
        int answer = 0;
        cin >> N >> M;

        if (N == 0 && M == 0) break;

        unordered_map<int, int> CD1;
        for (int i = 0; i < N; i++) {
            int cd;
            cin >> cd;
            CD1[cd]++;
        }
        for (int i = 0; i < M; i++) {
            int cd;
            cin >> cd;
            if (CD1[cd] > 0) { // CD가 첫 번째 집합에 존재하는지 확인
                answer++;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
