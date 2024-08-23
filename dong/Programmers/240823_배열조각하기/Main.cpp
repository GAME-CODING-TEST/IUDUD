#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    // �۾��� ������ �� arr�� index���� ��ȭ�� �����
    // 1. foreach���� ���� query�� ��ȸ�Ѵ�. : query[i] ���� arr�� index�̱� ������ foreach�� ����Ѵ�
    // 2.1. Ȧ/¦�� ���� ������ �����Ѵ�
    // 2.2. ���ǿ� ���� s_idx, e_idx�� ���� �����Ѵ�.
    // 3. s_idx�� e_idx ������ elements�� answer�� �߰��Ѵ�.
    int s_idx = 0;
    int e_idx = arr.size() - 1;
    for (int i = 0; i < query.size(); ++i) {
        int idx = query[i];
        if (i % 2 == 0) { // ¦��: �޺κ� ����
            e_idx = s_idx + idx;
        }
        else {              // Ȧ��: �պκ� ����
            s_idx += idx;
        }
    }

    return vector<int>(arr.begin() + s_idx, arr.begin() + e_idx + 1);
}

int main() {}