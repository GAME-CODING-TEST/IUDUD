#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution1(string rny_string) {
    string answer = "";
    for (auto ch : rny_string) {
        if (ch == 'm') {
            answer += "rm";
        }
        else {
            answer += ch;
        }
    }

    return answer;
}

string solution2(string rny_string) {
    string answer = "";
    rny_string = regex_replace(rny_string, regex("m"), "rn");
    answer = rny_string;
    return answer;
}

int main() {}