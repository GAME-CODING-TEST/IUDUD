#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;

    for (auto str : intStrs) {
        int cnt = l;
        string temp = "";

        for (int i = s; i < s + l; ++i) {
            temp += str[i];
        }

        int num = stoi(temp);
        if (num > k) {
            answer.push_back(num);
        }
    }

    return answer;
}

vector<int> solution2(vector<string> intStrs, int k, int s, int l)
{
    vector<int> answer;
    for (int i = 0; i < intStrs.size(); ++i) {
        string temp = intStrs[i].substr(s, l);
        int num = stoi(temp);
        if (num > k) {
            answer.push_back(num);
        }
    }
    return answer;
}

int main() {}