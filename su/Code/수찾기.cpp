#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    int N,M;
    cin >> N;
    set<int> numbers;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers.insert(num);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (numbers.find(num) == numbers.end()) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }
    

    return 0;
}
