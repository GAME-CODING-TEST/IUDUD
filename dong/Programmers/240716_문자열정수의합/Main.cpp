#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;

    for (char ch : num_str) {
        answer += (ch - '0');   // ASCII: 0 ~ 9 ���ڸ� ������ ǥ���ϱ� ���ؼ��� '0'�� ����. 
                                // 0 ~ 9 ���ڸ� �������� �ٲٸ� 48 ~ 57�̱� �����̴�.
    }

    return answer;
}

int main()
{

}