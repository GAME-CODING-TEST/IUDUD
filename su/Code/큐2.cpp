#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;
    deque<int> dq;

    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;
                
        if (command == "push") { // 숫자 추가
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (command == "pop") { // 빼고 출력, 없으면 -1
            if (dq.empty())  cout << "-1\n";
            else {
                cout << dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if (command == "front") { // 가장 앞, 없음 -1
            if (dq.empty())  cout << "-1"<<"\n";
            else  cout << dq.front() << "\n";
        }
        else if (command == "back") { // 가장 뒤, 없음 -1
            if (dq.empty()) cout << "-1\n";
            else  cout << dq.back() <<"\n";
        }
        else if (command == "size") {// 갯수
            cout << dq.size()<< "\n";
        }
        else if (command == "empty") {// 비어있음 1, 없음 0
            if (dq.empty())  cout << "1\n";
            else cout << "0\n";

        }
    }
    return 0;
}
