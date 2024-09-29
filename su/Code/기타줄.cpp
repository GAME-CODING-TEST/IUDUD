#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    int answer = 0;
    int min01 = 0;
    int min02 = 0;
    vector<pair<int,int>> guitar(M);

    for (int i = 0; i < M; i++) {
        int mul, one;
        cin >> mul >> one;
        guitar[i].first = mul;
        guitar[i].second = one;

        if (guitar[i].first < guitar[min01].first) min01 = i;
        if (guitar[i].second < guitar[min02].second) min02 = i;
    }

    // 세트가 제일 싸다        
    answer = guitar[min01].first * ((N / 6) + 1);

    // 낱개가 제일 싸다
    answer = min(answer, guitar[min02].second * N);
    
    // 세트 저렴 + 낱개 저렴
    answer = min(answer, (guitar[min01].first * (N / 6)) + (guitar[min02].second * (N%6)));
    
    cout << answer;

    return 0;
}
