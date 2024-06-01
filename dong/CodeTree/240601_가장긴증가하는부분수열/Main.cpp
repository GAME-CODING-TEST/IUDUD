#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
int N;
int nums[MAX_N + 1];
int dp[MAX_N + 1];

void Init()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
		dp[i] = 1;
	}
}

void SetDp()
{
	for (int i = 1; i <= N; ++i) {
		// 1 ~ i - 1까지 탐색하면서 가장 큰 LIS를 구한다.
		for (int j = 1; j < i; ++j) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
}

int GetLengthLIS()
{
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		ret = max(dp[i], ret);
	}

	return ret;
}

int main()
{
	Init();
	SetDp();
	cout << GetLengthLIS();
}