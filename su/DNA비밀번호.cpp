#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<char>DNA(N);
    int answer = 0;
    string password;
    cin >> password;

    for (int i = 0; i < N; i++) {
        DNA[i] = password[i];
    }

    int needA, needC, needG, needT;
    int A=0, C=0, G=0, T=0;
    cin >> needA >> needC >> needG >> needT;


    for (int i = 0; i < M; i++) {
        switch (DNA[i]) {
        case 'A':
            A++;
            break;
        case 'C':
            C++;
            break;
        case 'G':
            G++;
            break;
        case 'T':
            T++;
            break;
        }
    }
    
    if (needA <= A && needC <= C && needG <= G && needT <= T) {
        answer++;
    }

    for (int i = M; i < N; i++) {
        switch (DNA[i]) {
            case 'A':
                A++;
                break;
            case 'C':
                C++;
                break;
            case 'G':
                G++;
                break;
            case 'T':
                T++;
                break;
        }
        switch (DNA[i-M]) {
            case 'A':
                A--;
                break;
            case 'C':
                C--;
                break;
            case 'G':
                G--;
                break;
            case 'T':
                T--;
                break;
        }


        if (needA <= A && needC <= C && needG <= G && needT <= T) {
            answer++;
        }
    }

    cout << answer;

    return 0;
}
