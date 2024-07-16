#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;

    for (char ch : num_str) {
        answer += (ch - '0');   // ASCII: 0 ~ 9 문자를 정수로 표현하기 위해서는 '0'를 뺀다. 
                                // 0 ~ 9 문자를 십진수로 바꾸면 48 ~ 57이기 때문이다.
    }

    return answer;
}

int main()
{

}