#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    int N;
    cin >> N;
    set<string> dance;
    dance.insert("ChongChong");

    for (int i = 0; i < N; i++) {
        string from, to;
        cin >> from >> to;
        
        if (dance.find(to) != dance.end()) {
            dance.insert(from);
        }
        else if (dance.find(from) != dance.end()) {
            dance.insert(to);
        }
    }

    cout << dance.size();
    return 0;
}
