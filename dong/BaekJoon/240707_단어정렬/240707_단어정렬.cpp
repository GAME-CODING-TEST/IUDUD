#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool Compare(const string& a, const string& b)
{
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main()
{
	int N;
	cin >> N;

	vector<string> word(N);
	for (int i = 0; i < N; ++i) {
		cin >> word[i];
	}

	sort(word.begin(), word.end(), Compare);
	word.erase(unique(word.begin(), word.end()), word.end());	// 중복된 원소들을 vector 뒤로 이동시킨 뒤 중복되지 않은 원소들까지 정상 범위에 포함
																// 남은 중복된 원소들은 erase로 삭제
	for (const string& w : word) {
		cout << w << "\n";
	}
}