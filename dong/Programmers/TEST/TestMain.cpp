#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(const string str, vector<int> vec)
{
    string answer = "";
    // str�� index �߿��� ���ŵ� ���ڴ� 0, �ƴϸ� 1�� �߰�
    vector<int> temp(str.length(), 1);
    
    // vec�� value�� �̿��ؼ� ���ŵ� idx�� temp�� ǥ��
    for (auto idx : vec) {
        temp[idx] = 0;
    }

    // temp���� value�� 0�� �ƴ� idx�� ��� string�� ����
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