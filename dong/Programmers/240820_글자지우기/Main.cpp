#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(const string str, vector<int> vec)
{
    string answer = "";
    vector<int> temp(str.length(), 1);       // str�� index �߿��� ���ŵ� ���ڴ� 0, �ƴϸ� 1�� �߰�
    
    for (auto idx : vec) {                   // vec�� value�� �̿��ؼ� ���ŵ� idx�� temp�� ǥ��
        temp[idx] = 0;
    }

    for (int i = 0; i < temp.size(); ++i) {  // temp���� value�� 0�� �ƴ� idx�� ��� string�� ����
        if (temp[i]) {
            answer += str[i];
        }
    }

    return answer;
}

// �� �ڿ������� ���ʴ�� �����ϴ� ���
string solution2(string my_string, vector<int> indices)
{
    sort(indices.begin(), indices.end(), greater<int>());
    for (auto idx : indices) {
        my_string.erase(idx, 1);
    }
    return my_string;
}

// ' ' ���ڸ� �����ϴ� ���
string solution3(string s, vector<int> indices)
{
    for (const auto& i : indices) s[i] = ' ';
    return { s.begin(), remove_if(s.begin(), s.end(), [](char c) {return c == ' '; }) };
}

int main() {}