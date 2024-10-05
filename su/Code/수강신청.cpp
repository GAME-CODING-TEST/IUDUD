#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    map<string, int> students;
    vector<string> row(K);

    for (int i = 0; i < K; i++) {
        string number;
        cin >> number;
        students[number] = i;
        row[i] = number;        
    }

    int cnt = 0;
    for (int i = 0; i < K; i++) {
        if (cnt == N) {
            break;
        }
        if (students[row[i]] == i) {
            cout << row[i] << "\n";
            cnt++;
        }
    }
    

    return 0;
}
