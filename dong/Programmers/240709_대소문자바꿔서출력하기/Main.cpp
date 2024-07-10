#include <iostream>
#include <string>

using namespace std;

void CaseSwitcher(string& str)
{
    const int SWITCHER = 'a' - 'A';

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {   // Lowercase
            str[i] -= SWITCHER;
        }
        else {  // Uppercase
            str[i] += SWITCHER;
        }
    }
}

int main(void) {
    string str;
    cin >> str;

    CaseSwitcher(str);
    cout << str;

    return 0;
}