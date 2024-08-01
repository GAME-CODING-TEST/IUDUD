#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> num_list) {
    int product = 1;
    int sum_pow = 0;
    for (auto num : num_list) {
        product *= num;
        sum_pow += num;
    }

    sum_pow = pow(sum_pow, 2);

    return (product > sum_pow) ? 0 : 1;
}

int main() {}