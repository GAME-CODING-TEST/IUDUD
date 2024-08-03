#include <string>
#include <vector>

using namespace std;

// 각 자리 숫자의 합을 9로 나눠야 한다.
int solution(string number) {
    int answer = 0;

    for (auto ch : number) {
        answer += (ch - '0');
    }

    answer %= 9;

    return answer;
}

int main() {}