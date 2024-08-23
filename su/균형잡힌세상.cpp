#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    string answer = "";
    while (1) {
        stack<char> s;
        string text;
        getline(cin, text);
        //cin >> text;

        if (text[0] == '.') {
            break;
        }

        bool isBalanced = true;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == '[') {
                s.push('[');
            }
            else if (text[i] == '(') {
                s.push('(');
            }
            else if (text[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    isBalanced = false;
                    break;
                }
            }
            else if (text[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    isBalanced = false;
                    break;
                }
            }
        }

        if (isBalanced && s.empty()) {
            answer += "yes\n";
        }
        else {
            answer += "no\n";
        }
    }

    cout << answer;

    return 0;
}
