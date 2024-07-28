#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    const int MAX_NUM = 1000001;
    vector<int> answer;

    for (vector<int> query : queries) {
        int min_num = MAX_NUM;
        for (int i = query[0]; i <= query[1]; ++i) {
            if (query[2] < arr[i]) {
                min_num = min(min_num, arr[i]);
            }
        }
        answer.push_back((min_num == MAX_NUM ? -1 : min_num));
    }

    return answer;
}

int main() {}