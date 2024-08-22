#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    // 1. find() 함수를 이용해서 value가 2인 index 위치를 찾는다.
    //      - 만약 value 2가 없는 경우 -1을 리턴한다.
    // 2. for문을 end() - 1부터 find()_iterator까지 탐색하면서 가장 먼저 value 2가 나오는 index를 찾는다.
    // 3. 1번과 2번에서 찾은 index 사이의 원소를 answer에 넣는다.
    int s_idx = 0;
    int e_idx = -1;
    auto it = find_if(arr.begin(), arr.end(), [](int n) { return n == 2; });
    if (it == arr.end()) return { -1 };
    else s_idx = distance(arr.begin(), it);

    for (int i = arr.size() - 1; i > s_idx; --i) {
        if (arr[i] == 2) {
            e_idx = i;
            break;
        }
    }

    if (e_idx == -1) {
        answer.emplace_back(arr[s_idx]);
    }
    else {
        for (int i = s_idx; i <= e_idx; ++i) {
            answer.emplace_back(arr[i]);
        }
    }

    return answer;
}

vector<int> solution2(vector<int> arr) {

    // 1. value가 2인 index를 vector<int> temp에 저장
    // 2. temp.size() == 0 : { -1 }
    // 3. temp.size() == 1 : { 2 }
    // 4. temp.size() > 1 : vector<int>(begin(), end())
    vector<int> temp;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 2) temp.emplace_back(i);
    }

    if (temp.size() == 0) return { -1 };
    else if (temp.size() == 1) return { 2 };
    else return vector<int>(arr.begin() + temp[0], arr.begin() + temp[temp.size() - 1] + 1);
}

int main() {}