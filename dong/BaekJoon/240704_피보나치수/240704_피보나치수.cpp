#include <iostream>

using namespace std;

// N��° �Ǻ���ġ ���� ���ϱ�
int main()
{
	const int MAX_N = 45;

	int N; 
	cin >> N;

	int dp[MAX_N];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];
}