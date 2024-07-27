#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(num_list);

    int last_idx = answer.size() - 1;
    if (answer[last_idx] > answer[last_idx - 1]) {
        int ele = answer[last_idx] - answer[last_idx - 1];
        answer.push_back(ele);
    }
    else {
        answer.push_back(answer[last_idx] * 2);
    }

    return answer;
}

vector<int> solution2(vector<int> vec) {
    vec.push_back(vec.back() > *(vec.end() - 2) ? vec.back() - *(vec.end() - 2) : vec.back() << 1);
    return vec;
}

int main() {}