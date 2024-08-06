#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";

    int start_idx = my_string.size() - n;
    for (int i = start_idx; i < my_string.size(); ++i) {
        answer += my_string[i];
    }

    return answer;
}

string solution2(string my_string, int n)
{
    return my_string.substr(my_string.length() - n);
}

string solution3(string my_string, int n)
{
    return string{ my_string.end() - n, my_string.end() };
}

int main() {}