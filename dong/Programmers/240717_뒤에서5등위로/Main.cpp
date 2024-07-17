#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> solution1(vector<int> num_list) {
    vector<int> answer;

    sort(num_list.begin(), num_list.end());
    for (int i = 5; i < num_list.size(); ++i) {
        answer.push_back(num_list[i]);
    }

    return answer;
}

vector<int> solution2(vector<int> num_list)
{
    sort(num_list.begin(), num_list.end());
    return vector<int>(num_list.begin() + 5, num_list.end());
}

vector<int> solution3(vector<int> num_list) 
{
    vector<int> answer;
    sort(num_list.begin(), num_list.end());
    copy_n(num_list.cbegin() + 5, num_list.size() - 5, back_inserter(answer));  // back_inserter: include iterator
    return answer;
}

int main() {}