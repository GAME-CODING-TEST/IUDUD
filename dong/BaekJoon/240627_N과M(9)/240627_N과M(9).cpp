#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 8;
const int MAX_M = 8;

int seq[MAX_N];
int ans[MAX_M];
bool visited[MAX_N];
int N, M;

// BackTracking을 이용한다.
void GetSeq(int len)
{
	if (len == M) {
		for (int i = 0; i < M; ++i) {
			cout << ans[i] << endl;
			return;
		}
	}

	// ans에 저장되는 원소 중 가장 마지막 값을 의미한다.
	// 수열의 마지막 값과 새로 추가되는 값이 같을 때, 중복 수열이 만들어지기 때문에 이를 배제한다.
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