#include <string>
#include <vector>
#include <numeric>

using namespace std;

string solution1(vector<string> arr) {
    string answer = "";
    for (auto c : arr) {
        answer.append(c);
    }
    return answer;
}

string solution2(vector<string> arr) {
    return accumulate(arr.begin(), arr.end(), string(""));
}

int main()
{

}