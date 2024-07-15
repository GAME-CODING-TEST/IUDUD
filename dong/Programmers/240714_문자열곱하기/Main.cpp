#include <string>
#include <vector>

using namespace std;

string solution1(string my_string, int k) {
    string answer = "";

    for (int i = 0; i < k; ++i) {
        answer.append(my_string);
    }

    return answer;
}

string solution2(string my_string, int k) {
    string answer = "";

    while (k--) {
        answer.append(my_string);
    }

    return answer;
}

int main()
{

}