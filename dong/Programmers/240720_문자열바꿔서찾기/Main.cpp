#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution1(string myString, string pat) {
    int answer = 0;

    string temp = "";
    for (int i = 0; i < myString.length(); ++i) {
        if (myString[i] == 'A') {
            temp += 'B';
        }
        else if (myString[i] == 'B') {
            temp += 'A';
        }
        else {
            temp += myString[i];
        }
    }

    if (temp.find(pat) != string::npos) {
        answer = 1;
    }

    return answer;
}

/// <summary>
/// [pat.cbegin(), pat.cend()) 범위 내의 각 원소를 lambda 식에 맞게 변환하여 그 결과를 p.begin()에 저장한다.
///     - cbegin()은 container의 시작 위치를 가리킨다.
/// </summary>
int solution2(string myString, string pat) {
    transform(pat.cbegin(), pat.cend(), pat.begin(), [](char c) {return c == 'A' ? 'B' : 'A'; });
    return myString.find(pat) != string::npos;
}

int main() {}