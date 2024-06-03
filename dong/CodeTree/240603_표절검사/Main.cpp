#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
using namespace std;

string strA, strB;
size_t numA, numB;
vector<vector<int>> dp;


void Init()
{
	cin >> strA >> strB;
	numA = strA.size();
	numB = strB.size();

	dp.resize(numA + 1, vector<int>(numB + 1, 0));
}

int LCS()
{
	for (size_t i = 1; i <= numA; ++i) {
		for (size_t j = 1; j <= numB; ++j) {
			if (strA[i - 1] == strB[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[numA][numB];
}

int main()
{
	Init();
	cout << LCS();
}