#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(const string str, vector<int> vec)
{
    string answer = "";
    vector<int> temp(str.length(), 1);       // str의 index 중에서 제거된 문자는 0, 아니면 1을 추가
    
    for (auto idx : vec) {                   // vec의 value를 이용해서 제거된 idx를 temp에 표시
        temp[idx] = 0;
    }

    for (int i = 0; i < temp.size(); ++i) {  // temp에서 value가 0이 아닌 idx만 골라서 string에 저장
        if (temp[i]) {
            answer += str[i];
        }
    }

    return answer;
}

// 맨 뒤에서부터 차례대로 제거하는 방법
string solution2(string my_string, vector<int> indices)
{
    sort(indices.begin(), indices.end(), greater<int>());
    for (auto idx : indices) {
        my_string.erase(idx, 1);
    }
    return my_string;
}

// ' ' 문자를 제거하는 방식
string solution3(string s, vector<int> indices)
{
    for (const auto& i : indices) s[i] = ' ';
    return { s.begin(), remove_if(s.begin(), s.end(), [](char c) {return c == ' '; }) };
}

int main() {}