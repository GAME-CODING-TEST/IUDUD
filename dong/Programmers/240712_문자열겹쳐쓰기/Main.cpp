#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";

    // 1��
    //answer = my_string.replace(s, overwrite_string.size(), overwrite_string);

    // 2��
    for (int i = 0; i < overwrite_string.size(); ++i) {
        my_string[i + s] = overwrite_string[i];
    }
    answer = my_string;

    return answer;
}

int main()
{

}