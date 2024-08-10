#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries)
{
    for (auto query : queries) {
        int front_idx = query[0];
        int back_idx = query[1];
        while (front_idx < back_idx) {
            swap(my_string[front_idx], my_string[back_idx]);

            front_idx++;
            back_idx--;
        }
    }
    return my_string;
}

string solution2(string my_string, vector<vector<int>> queries)
{
    for (const auto& query : queries) {
        reverse(my_string.begin() + query[0], my_string.begin() + query[1] + 1);
    }
    return my_string;
}



int main() {}