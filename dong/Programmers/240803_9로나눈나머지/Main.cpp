#include <string>
#include <vector>

using namespace std;

// �� �ڸ� ������ ���� 9�� ������ �Ѵ�.
int solution(string number) {
    int answer = 0;

    for (auto ch : number) {
        answer += (ch - '0');
    }

    answer %= 9;

    return answer;
}

int main() {}