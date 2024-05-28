#include <iostream>
using namespace std;

const int MAX_N = 10;
int N;
int dp[MAX_N + 1];

void Init()
{
	cin >> N;
	dp[0] = 1;
	dp[1] = 1;
}

int GetTileCombination(int num)
{
	for (int i = 2; i <= num; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[num];
}

int main()
{
	Init();
	cout << GetTileCombination(N);
}