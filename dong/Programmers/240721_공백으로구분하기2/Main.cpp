#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> solution1(string myString)
{
    vector<string> answer;

    int start = 0;
    string tmp;
    myString += " ";
    for (int i = 0; i < myString.length(); i++)
    {
        if (myString[i] == ' ')
        {
            tmp = myString.substr(start, i - start);
            if (!tmp.empty()) {
                answer.push_back(tmp);
            }
            start = i + 1;
        }
    }

    return answer;
}

vector<string> solution2(string my_string) {
    vector<string> answer;

    string str;
    stringstream ss;
    ss.str(my_string);
    while (ss >> str)
    {
        answer.emplace_back(str);
    }

    return answer;
}

int main() {}