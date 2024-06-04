#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <algorithm>
using namespace std;

string A, B;
size_t lenA, lenB;
vector<vector<int>> dp;

void Init()
{
	cin >> A >> B;

	lenA = A.size();
	lenB = B.size();

	dp.resize(lenA + 1, vector<int>(lenB + 1, 0));
}

int EditDistance()
{
	// �� ���ڿ��� 0�� ������ ����
	for (size_t i = 0; i <= lenA; ++i) {
		dp[i][0] = static_cast<int>(i);						// A�� ù i ���ڱ��� �����ϴ� ��� -> ���� ���ڰ� ���� ������ A ���ڿ���ŭ �����Ÿ��� ����
	}
	for (size_t j = 0; j <= lenB; ++j) {
		dp[0][j] = static_cast<int>(j);						// B�� ù j ���ڱ��� �����ϴ� ���
	}

	for (size_t i = 1; i <= lenA; ++i) {
		for (size_t j = 1; j <= lenB; ++j) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1]; // ���ڰ� ������ ��� ���� ����
			}
			else {
				dp[i][j] = min({ dp[i - 1][j] + 1,			 // ����
								dp[i][j - 1] + 1,			 // ����
								dp[i - 1][j - 1] + 1 });	 // ��ü
			}
		}
	}

	return dp[lenA][lenB];
}

int main()
{
	Init();
	cout << EditDistance();
}