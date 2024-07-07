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
	word.erase(unique(word.begin(), word.end()), word.end());	// �ߺ��� ���ҵ��� vector �ڷ� �̵���Ų �� �ߺ����� ���� ���ҵ���� ���� ������ ����
																// ���� �ߺ��� ���ҵ��� erase�� ����
	for (const string& w : word) {
		cout << w << "\n";
	}
}