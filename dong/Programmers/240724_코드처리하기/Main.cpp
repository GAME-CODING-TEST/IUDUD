#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";

    int mode = 0;
    string ret = "";
    for (int i = 0; i < code.length(); ++i) {
        if (mode == 0) {
            if (code[i] == '1') {
                mode = 1;
            }
            else if (i % 2 == 0) {
                ret += code[i];
            }
        }
        else if (mode == 1) {
            if (code[i] == '1') {
                mode = 0;
            }
            else if (i % 2 == 1) {
                ret += code[i];
            }
        }
    }

    if (ret.length() == 0) {
        answer = "EMPTY";
    }
    else {
        answer = ret;
    }

    return answer;
}

string solution2(string code)
{
    string ret = "";
    int mode = 0;
    for (int idx = 0; idx < code.size(); ++idx) {
        if (mode) {
            if (code[idx] == '1') {
                mode = 0;
            }
            else if (idx % 2 == 0) {
                ret += code[idx];
            }
        }
        else {
            if (code[idx] == '1') {
                mode = 1;
            }
            else if (idx % 2 == 1) {
                ret += code[idx];
            }
        }
    }

    return ret.empty() ? "EMPTY" : ret;
}

string solution3(string code)
{
    string ret = "";
    bool mode = false;
    for (int i = 0; i < code.length(); ++i) {
        switch (mode) {
        case true:
            if (code[i] != '1' && i % 2 == 1)   ret += code[i];
            else if (code[i] == '1')            mode = !mode;
            break;
        case false:
            if (code[i] != '1' && i % 2 == 0)   ret += code[i];
            else if (code[i] == '1')            mode = !mode;
        }
    }

    return ret.empty() ? "EMPTY" : ret;
}

int main() {}