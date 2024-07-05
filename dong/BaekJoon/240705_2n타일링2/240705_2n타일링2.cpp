#include <iostream>

using namespace std;

int main()
{
	const int MAX_N = 1000;
	const int CONDITION_NUM = 10007;

	int N;
	cin >> N;

	int dp[MAX_N + 1];		// 2 * n 직사각형을 만드는 방법의 수
	dp[1] = 1;				// 2 * 1
	dp[2] = 3;				// 2 * 2
	for (int i = 3; i <= N; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % CONDITION_NUM;
	}

	cout << dp[N];
}