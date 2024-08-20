#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(const string str, vector<int> vec)
{
    string answer = "";
    // str의 index 중에서 제거된 문자는 0, 아니면 1을 추가
    vector<int> temp(str.length(), 1);
    
    // vec의 value를 이용해서 제거된 idx를 temp에 표시
    for (auto idx : vec) {
        temp[idx] = 0;
    }

    // temp에서 value가 0이 아닌 idx만 골라서 string에 저장
    for (int i = 0; i < temp.size(); ++i) {
        if (temp[i]) {
            answer += str[i];
        }
    }

    return answer;
}

int main()
{
    string s = "apporoograpemmemprs";
    vector<int> vec{ 1, 16, 6, 15, 0, 10, 11, 3 };

    cout << solution(s, vec) << endl;
}