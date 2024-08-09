#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) 
{
    int answer = 0;

    vector<int> table(6);
    table[a - 1]++;    table[b - 1]++;    table[c - 1]++;    table[d - 1]++;
    vector<vector<int>> nums(5);
    nums[table[0]].emplace_back(1);
    nums[table[1]].emplace_back(2);
    nums[table[2]].emplace_back(3);
    nums[table[3]].emplace_back(4);
    nums[table[4]].emplace_back(5);
    nums[table[5]].emplace_back(6);

    if (!nums[4].empty())
    {
        return 1111 * nums[4][0];
    }
    else if (!nums[3].empty())
    {
        return pow(10 * nums[3][0] + nums[1][0], 2);
    }
    else if (nums[2].size() == 2)
    {
        return (nums[2][0] + nums[2][1]) * abs(nums[2][0] - nums[2][1]);
    }
    else if (nums[2].size() == 1)
    {
        return nums[1][0] * nums[1][1];
    }
    else
    {
        return *min_element(nums[1].begin(), nums[1].end());
    }

    return answer;
}

int main() {}