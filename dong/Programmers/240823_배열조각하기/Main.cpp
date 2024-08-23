#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    // 작업을 수행한 후 arr의 index에는 변화가 생긴다
    // 1. foreach문을 통해 query를 순회한다. : query[i] 값이 arr의 index이기 때문에 foreach를 사용한다
    // 2.1. 홀/짝에 따라 조건을 수행한다
    // 2.2. 조건에 따라 s_idx, e_idx의 값만 변경한다.
    // 3. s_idx와 e_idx 사이의 elements를 answer에 추가한다.
    int s_idx = 0;
    int e_idx = arr.size() - 1;
    for (int i = 0; i < query.size(); ++i) {
        int idx = query[i];
        if (i % 2 == 0) { // 짝수: 뒷부분 제거
            e_idx = s_idx + idx;
        }
        else {              // 홀수: 앞부분 제거
            s_idx += idx;
        }
    }

    return vector<int>(arr.begin() + s_idx, arr.begin() + e_idx + 1);
}

int main() {}