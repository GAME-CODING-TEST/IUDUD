#include <iostream>

using namespace std;

int count[10001] = {0}; // 1 ~ 10,000까지의 자연수를 카운팅할 배열 (4 byte * 10001 = 약 40KB)

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL); // 입력과 출력을 묶지 않음으로써 속도 향상

    int N;
    cin >> N; // 수의 개수 N 입력받기

    // 입력을 받으며 카운팅
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num; // 수 입력
        count[num]++; // 해당 수의 카운트를 증가
    }

    // 카운팅된 결과를 오름차순으로 출력
    for (int i = 1; i <= 10000; i++) {
        while (count[i]--) { // 해당 숫자의 카운트가 0이 될 때까지
            cout << i << "\n"; // 해당 숫자를 출력
        }
    }

    return 0;
}
