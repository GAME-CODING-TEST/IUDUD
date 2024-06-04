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
	// 각 문자열이 0인 경우부터 시작
	for (size_t i = 0; i <= lenA; ++i) {
		dp[i][0] = static_cast<int>(i);						// A의 첫 i 문자까지 삭제하는 비용 -> 같은 문자가 없기 때문에 A 문자열만큼 편집거리가 증가
	}
	for (size_t j = 0; j <= lenB; ++j) {
		dp[0][j] = static_cast<int>(j);						// B의 첫 j 문자까지 삽입하는 비용
	}

	for (size_t i = 1; i <= lenA; ++i) {
		for (size_t j = 1; j <= lenB; ++j) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1]; // 문자가 같으면 비용 증가 없음
			}
			else {
				dp[i][j] = min({ dp[i - 1][j] + 1,			 // 삭제
								dp[i][j - 1] + 1,			 // 삽입
								dp[i - 1][j - 1] + 1 });	 // 교체
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