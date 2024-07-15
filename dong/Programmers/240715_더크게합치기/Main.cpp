#include <string>
#include <vector>

using namespace std;

int solution1(int a, int b) {
    int answer = 0;

    string a_str = to_string(a);
    string b_str = to_string(b);
    string temp = a_str;

    int num1 = stoi(a_str.append(b_str));
    int num2 = stoi(b_str.append(temp));

    answer = (num1 > num2) ? num1 : ((num1 == num2) ? num1 : num2);

    return answer;
}

int solution2(int a, int b) {
    return max(stoi(to_string(a) + to_string(b)), stoi(to_string(b) + to_string(a)));
}

int main()
{

}