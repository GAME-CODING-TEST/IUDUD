#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    // 1. find() �Լ��� �̿��ؼ� value�� 2�� index ��ġ�� ã�´�.
    //      - ���� value 2�� ���� ��� -1�� �����Ѵ�.
    // 2. for���� end() - 1���� find()_iterator���� Ž���ϸ鼭 ���� ���� value 2�� ������ index�� ã�´�.
    // 3. 1���� 2������ ã�� index ������ ���Ҹ� answer�� �ִ´�.
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

    // 1. value�� 2�� index�� vector<int> temp�� ����
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