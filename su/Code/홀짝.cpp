#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;
   
    for (int i = 0; i < N; i++) {
        string num;
        cin >> num;

        int size = (num.length()) - 1;
        
        if ((num[size] - '0') % 2 != 0) {
            cout << "odd\n";
        }
        else {
            cout << "even\n";
        }
    }

    return 0;
}
