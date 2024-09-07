#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    // 전화번호부를 정렬
    sort(phone_book.begin(), phone_book.end());

    // 인접한 번호들만 비교
    for (int i = 0; i < phone_book.size() - 1; i++) {
        // 현재 번호가 다음 번호의 접두사인지 확인
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            return false;
        }
    }
    
    return true;
}
