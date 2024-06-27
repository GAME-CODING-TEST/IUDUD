#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 8;
const int MAX_M = 8;

int seq[MAX_N];
int ans[MAX_M];
bool visited[MAX_N];
int N, M;

// BackTracking�� �̿��Ѵ�.
void GetSeq(int len)
{
	if (len == M) {
		for (int i = 0; i < M; ++i) {
			cout << ans[i] << endl;
			return;
		}
	}

	// ans�� ����Ǵ� ���� �� ���� ������ ���� �ǹ��Ѵ�.
	// ������ ������ ���� ���� �߰��Ǵ� ���� ���� ��, �ߺ� ������ ��������� ������ �̸� �����Ѵ�.
	int last = 0;

	for (int i = 0; i < N; ++i) {
		if (!visited[i] && seq[i] != last) {
			ans[len] = seq[i];
			last = ans[len];
			visited[i] = true;
			GetSeq(len + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}

	sort(seq, seq + N);
	GetSeq(0);
}